//-----------------------------------------------------------------------------
// Fxxx_EEPROM_Interface.c
//-----------------------------------------------------------------------------
// Copyright (C) 2010 Silicon Laboratories, Inc.
// http://www.silabs.com
//
// File Description:
//
// This file defines an emulated EEPROM interface for Silicon Labs Flash-based
// 8051 MCUs.
//
// Release 1.0 / 10NOV2010 (BD)
//    -Initial Revision
//

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <compiler_defs.h>
#include "Fxxx_Flash_Interface.h"
#include "Fxxx_EEPROM_Configuration.h"

//-----------------------------------------------------------------------------
// Internal Constants
//-----------------------------------------------------------------------------

#define NEW_TAG         0xFF        // Value for New Sector
#define WIP_TAG         0x7F        // Value for WIP Sector

#define DONE_TAG_MIN    0x01        // Done tag minimum
#define DONE_TAG_MAX    0x7E        // Done tag maximum

#define NO_TAG          0x00

//-----------------------------------------------------------------------------
// Global Variables
//-----------------------------------------------------------------------------
U8 currentEepromSector = 0, currentEepromPage = 0;

//-----------------------------------------------------------------------------
// Function Prototypes
//-----------------------------------------------------------------------------
void copySector(U16, U16, U8, U8);
U16 getBaseAddress(U8, U8);
U8 findNextSector(void);
U8 findCurrentSector(void);

U8 EEPROM_WriteBlock (U8, U8 *, U8);
U8 EEPROM_ReadBlock (U8, U8 *, U8);

//-----------------------------------------------------------------------------
// EEPROM_WriteBlock
//-----------------------------------------------------------------------------
//
// This routine writes the specified array into the emulated EEPROM by
// decoding the address and calling flash write functions.
//
// Arguments :  U8 address - 8-bit EEPROM address to start at
//              U8 *dataBuf - pointer to data array
//              U8 length - number of bytes to write
//
// Returns U8 : EE_NO_ERROR = Write was sucessful
//              EE_WRITE_ERROR = Write did not succeed, due to either a page
//                erase problem or an out-of-bounds address.
//              EE_SECTOR_ERROR = Could not determine current sector.
//
U8 EEPROM_WriteBlock (U8 address, U8 *dataBuf, U8 length)
{
   U16 readAddr, writeAddr;
   U8 nextSector;
   U8 currentTag;
   U8 byteCount;
   U8 pageEraseCounter;

   if ((U16)(address+length) > EE_SIZE)
   {
      return EE_WRITE_ERROR;
   }

   currentTag = findCurrentSector();
   if (currentTag == NO_TAG)
   {
      return EE_SECTOR_ERROR;
   }

   // Get the current sector's base address for read (copy) later
   readAddr = getBaseAddress(currentEepromPage, currentEepromSector);

   nextSector = findNextSector();

   // Get base address of sector where we will be writing
   writeAddr = getBaseAddress(currentEepromPage, currentEepromSector);

   if (nextSector == 0x00)
   {
      pageEraseCounter = 0;

      while (pageEraseCounter < FL_ERASE_LIMIT)
      {
         EE_FLASH_WriteErase (writeAddr, 0xFF, FL_ERASE);
         if (!EE_FLASH_BlankCheck(writeAddr))
         {
            if (++pageEraseCounter == FL_ERASE_LIMIT)
            {
               return EE_WRITE_ERROR;
            }
         }
         else
         {
            break;
         }
      }
   }

   // Mark new sector as copy in progress
   EE_FLASH_WriteErase (writeAddr + TAG_OFFSET, WIP_TAG, FL_WRITE);

   // Copy from old to new sector excluding copy addresses
   copySector(readAddr, writeAddr, address, length);

   // Write new info to sector
   for (byteCount = 0; byteCount < length; byteCount++)
   {
      EE_FLASH_WriteErase (writeAddr + address + byteCount, *dataBuf++, FL_WRITE);
   }
   if (currentTag == DONE_TAG_MAX)
   {
      currentTag = DONE_TAG_MIN;
   }
   else
   {
      currentTag++;
   }

   // Mark new sector with valid tag
   EE_FLASH_WriteErase (writeAddr + TAG_OFFSET, currentTag, FL_WRITE);

   return EE_NO_ERROR;
}

//-----------------------------------------------------------------------------
// EEPROM_ReadBlock
//-----------------------------------------------------------------------------
//
// This routine reads the emulated EEPROM information into the specified
// buffer.
//
// Arguments :  U8 address - 8-bit EEPROM address to start at
//              U8 *dataBuf - pointer to data array
//              U8 length - number of bytes to read
//
// Returns U8 : EE_NO_ERROR = Read was sucessful
//              EE_READ_ERROR = Read did not succeed, due to  out-of-bounds
//                 address.
//              EE_SECTOR_ERROR = Could not determine current sector.
//
U8 EEPROM_ReadBlock (U8 address, U8 *dataBuf, U8 length)
{
   U16 sectorAddress;
   U8 byteCount;

   if ((U16)(address+length) > EE_SIZE)
   {
      return EE_READ_ERROR;
   }
   if (findCurrentSector() == 0x00)
   {
      return EE_SECTOR_ERROR;
   }
   sectorAddress = getBaseAddress(currentEepromPage, currentEepromSector);
   // Read data bytes
   for (byteCount = 0; byteCount < length; byteCount++)
   {
      *dataBuf++ = EE_FLASH_Read(sectorAddress+address+byteCount);
   }
   return EE_NO_ERROR;
}


//-----------------------------------------------------------------------------
// copySector
//-----------------------------------------------------------------------------
//
// This internal routine copies the contents of one sector to another, while
// excluding the addresses about to be written.
//
// Arguments :  U16 fromAddr - 16-bit Flash address to copy from
//              U16 toAddr - 16-bit Flash addres to copy to
//              U8 exclude - Starting EEPROM address to exclude for copy.
//              U8 length - Number of bytes to exlude from copy.
//
// Returns :    None
//
void copySector(U16 fromAddr, U16 toAddr, U8 exclude, U8 length)
{
   U8 offset_addr;
   U8 copy_byte;

   for (offset_addr = 0; offset_addr < EE_SIZE; offset_addr++)
   {
      //copy_byte = *((U8 SEG_CODE *) (fromAddr+offset_addr));
      copy_byte = EE_FLASH_Read(fromAddr+offset_addr);
      
      if ((offset_addr < exclude)||(offset_addr >= exclude+length))
      {
         EE_FLASH_WriteErase ((toAddr+offset_addr), copy_byte, FL_WRITE);
      }
   }
}

//-----------------------------------------------------------------------------
// findNextSector
//-----------------------------------------------------------------------------
//
// This internal routine finds the next available sector in the EEPROM area
// and updates the currentEepromPage and currentEepromSector variables.
//
// Arguments :  None
//
// Returns U8 : 0 if next page needs to be erased, 1 if empty sector found
//
U8 findNextSector(void)
{
   U8 pageNow = currentEepromPage, sectorNow = currentEepromSector;
   U8 sectorFound = 2;
   U8 sectTag;
   U16 sectorAddress;

   while (sectorFound == 2)
   {
      currentEepromSector++;
      if (currentEepromSector == EE_SECTORS)
      {
         currentEepromSector = 0;
         currentEepromPage++;
         if (currentEepromPage == FL_PAGES)
         {
            currentEepromPage = 0;
         }
      }
      sectorAddress = getBaseAddress(currentEepromPage, currentEepromSector);
      sectTag = EE_FLASH_Read(sectorAddress+TAG_OFFSET);
      if (sectTag == NEW_TAG)
      {
         sectorFound = 1;
      }
      else if ((pageNow == currentEepromPage)&&
               (sectorNow == currentEepromSector))
      {
         currentEepromSector = 0;
         currentEepromPage++;
         if (currentEepromPage == FL_PAGES)
         {
            currentEepromPage = 0;
         }
         sectorFound = 0;
      }
   }
   return sectorFound;
}

//-----------------------------------------------------------------------------
// findCurrentSector
//-----------------------------------------------------------------------------
//
// This internal routine finds the currently used sector in the EEPROM area
// and updates the currentEepromPage and currentEepromSector variables.
//
// Arguments :  None
//
// Returns U8 : 0 if sector could not be determined, sector tag if sector
//              was found
//
U8 findCurrentSector(void)
{
   U8 pgCount, sectCount;
   U8 emptySectors = 0;
   U8 sectTag = NO_TAG, latestTag = NO_TAG, nextTag = NO_TAG;

   for (pgCount = 0; pgCount < FL_PAGES; pgCount++)
   {
      for (sectCount = 0; sectCount < EE_SECTORS; sectCount++)
      {
         sectTag = EE_FLASH_Read(getBaseAddress(pgCount, sectCount)+TAG_OFFSET);

         if (sectTag == NEW_TAG)
         {
            emptySectors++;
         }
         if ((sectTag >= DONE_TAG_MIN)&&(sectTag <= DONE_TAG_MAX))
         {
            if ((latestTag == NO_TAG)||(sectTag == nextTag))
            {
               latestTag = sectTag;
               currentEepromPage = pgCount;
               currentEepromSector = sectCount;

               if (sectTag == DONE_TAG_MAX)
               {
                  nextTag = DONE_TAG_MIN;
               }
               else
               {
                  nextTag = sectTag + 1;
               }
            }
         }
      }
   }
   // If all sectors are empty, start fresh
   if (emptySectors == FL_PAGES*EE_SECTORS)
   {
      latestTag = DONE_TAG_MIN;
      currentEepromPage = FL_PAGES-1;
      currentEepromSector = EE_SECTORS-1;
   }

   return latestTag;
}

//-----------------------------------------------------------------------------
// getBaseAddress
//-----------------------------------------------------------------------------
//
// This internal routine calculates the base address for a Flash sector in the
// emulated EEPROM area.
//
// Arguments :  U8 page - zero-based page number to calculate from.
//              U8 sector - zero-based sector number to calculate from.
//
// Returns U16: 16-bit Flash address corresponding to the page and sector.
//
U16 getBaseAddress(U8 page, U8 sector)
{
   return (EE_BASE_ADDR+(FL_PAGE_SIZE*page)+(EE_SIZE+EE_TAG_SIZE)*sector);
}

//-----------------------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------------------