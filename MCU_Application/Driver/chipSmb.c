#include "chipSMB.h"

#define  SMB_WRITE          0x00           // WRITE direction bit
#define  SMB_READ           0x01           // READ direction bit



#define  SMB_BUS_ERROR  0x00           // (all modes) BUS ERROR
#define  SMB_START      0x08           // (MT & MR) START transmitted
#define  SMB_RP_START   0x10           // (MT & MR) repeated START
#define  SMB_MTADDACK   0x18           // (MT) Slave address + W transmitted;
                                       //    ACK received
#define  SMB_MTADDNACK  0x20           // (MT) Slave address + W transmitted;
                                       //    NACK received
#define  SMB_MTDBACK    0x28           // (MT) data byte transmitted;
                                       //    ACK rec'vd
#define  SMB_MTDBNACK   0x30           // (MT) data byte transmitted;
                                       //    NACK rec'vd
#define  SMB_MTARBLOST  0x38           // (MT) arbitration lost
#define  SMB_MRADDACK   0x40           // (MR) Slave address + R transmitted;
                                       //    ACK received
#define  SMB_MRADDNACK  0x48           // (MR) Slave address + R transmitted;
                                       //    NACK received
#define  SMB_MRDBACK    0x50           // (MR) data byte rec'vd;
                                       //    ACK transmitted
#define  SMB_MRDBNACK   0x58           // (MR) data byte rec'vd;
                                       //    NACK transmitted
/*****************************************************************************/
static data uint8_t SMB_ReadBuffer[CONFIG_SMB_BUFFER_SIZE];//IN
static data uint8_t SMB_WriteBuffer[CONFIG_SMB_BUFFER_SIZE];//OUT
static data uint8_t SMB_SlaveAddress;//Target SMBus slave address
static data uint8_t SMB_ReadLength;//读长度
static data uint8_t SMB_WriteLength;//写长度
static data uint8_t SMB_MyAddress;//SMB主机地址 
bit SMB_BUSY;                          // Software flag to indicate when the
                                       // SMB_Read() or SMB_Write() functions
                                       // have claimed the SMBus

bit SMB_RW;                            // Software flag to indicate the
                                       // direction of the current transfer
/*****************************************************************************/
static void SMBus_Init (void);
static void Timer3_Init (void);
/*****************************************************************************/
void EPROM_Write(uint16_t addr, uint8_t *pdat, uint8_t len)
{//ERPOM写入
}
void EPROM_Read(uint16_t addr, uint8_t *pdat, uint8_t len)
{//EPROM读取
}

void SMB_Init(void)
{//SMB初始化
   SMBus_Init ();                      // Configure and enable SMBus
   Timer3_Init ();                     // Configure and enable Timer3
   EIE1 |= 0x02;                       // Enable the SMBus interrupt
   SI = 0;  
}
void SMB_Write (uint8_t slaveAddr, uint8_t wrsize, uint8_t *pwdat)
{//硬件SMB写入
	SMB_WriteLength = wrsize;
	SMB_SlaveAddress = slaveAddr;
	memcpy(SMB_WriteBuffer, pwdat, wrsize);
	while (SMB_BUSY);                   // Wait for SMBus to be free.
	SMB_BUSY = 1;                       // Claim SMBus (set to busy)
	SMB_RW = 0;                         // Mark this transfer as a WRITE
	STA = 1;                            // Start transfer
}
void SMB_Read (uint8_t slaveAddr ,uint8_t rdsize, uint8_t *prdat)
{//硬件SMB读取
	SMB_ReadLength = rdsize;
	SMB_SlaveAddress = slaveAddr;
	memcpy(SMB_ReadBuffer, prdat, rdsize);//复制pdat内容到发送缓冲区
	while (SMB_BUSY);                   // Wait for bus to be free.
	SMB_BUSY = 1;                       // Claim SMBus (set to busy)
	SMB_RW = 1;                         // Mark this transfer as a READ
	STA = 1;                            // Start transfer
	while (SMB_BUSY);                   // Wait for transfer to complete
}
static void SMBus_Init (void)
{//硬件SMB BUS初始化
   SMB0CN = 0x07;                      // Assert Acknowledge low (AA bit = 1b);
                                       // Enable SMBus Free timeout detect;
                                       // Enable SCL low timeout detect

   // SMBus clock rate (derived approximation from the Tlow and Thigh equations
   // in the SMB0CR register description)
   SMB0CR = 257 - (CONFIG_SYSCLK / (2 * CONFIG_SMB_FREQUENCY));
   SMB0ADR = SMB_MyAddress;// Set own slave address.
   SMB0CN |= 0x40;                     // Enable SMBus;
}
static void Timer3_Init (void)
{//SMB 频率计时器
   TMR3CN = 0x00;                      // Timer3 uses SYSCLK/12
   TMR3RL = -(CONFIG_SYSCLK/12/40);           // Timer3 configured to overflow after
   TMR3 = TMR3RL;                      // ~25ms (for SMBus low timeout detect)
   EIE2 |= 0x01;                       // Timer3 interrupt enable
   TMR3CN |= 0x04;                     // Start Timer3
}

//-----------------------------------------------------------------------------
// Interrupt Service Routines
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// SMBus Interrupt Service Routine (ISR)
//-----------------------------------------------------------------------------
//
// SMBus ISR state machine
// - Master only implementation - no slave or arbitration states defined
// - All incoming data is written to global array <SMB_DATA_IN>
// - All outgoing data is read from global array <SMB_DATA_OUT>
//
void SMBUS_ISR (void) interrupt INTERRUPT_SMBUS0
{
   bit FAIL = 0;                       // Used by the ISR to flag failed
                                       // transfers
   static uint8_t sent_byte_counter;
   static uint8_t rec_byte_counter;
   // Status code for the SMBus (SMB0STA register)
   switch (SMB0STA)
   {
      // Master Transmitter/Receiver: START condition transmitted.
      // Load SMB0DAT with slave device address.
      case SMB_START:

      // Master Transmitter/Receiver: repeated START condition transmitted.
      // Load SMB0DAT with slave device address
      case SMB_RP_START:
         SMB0DAT = SMB_SlaveAddress;// Load address of the slave.
         SMB0DAT &= 0xFE;// Clear the LSB of the address for the
                                       // R/W bit
         SMB0DAT |= SMB_RW;// Load R/W bit
         STA = 0;// Manually clear STA bit

         rec_byte_counter = 1;// Reset the counter
         sent_byte_counter = 1;// Reset the counter

         break;

      // Master Transmitter: Slave address + WRITE transmitted.  ACK received.
      // For a READ: N/A
      //
      // For a WRITE: Send the first data byte to the slave.
      case SMB_MTADDACK:

         SMB0DAT = SMB_WriteBuffer[sent_byte_counter-1];
         sent_byte_counter++;

         break;

      // Master Transmitter: Slave address + WRITE transmitted.  NACK received.
      // Restart the transfer.
      case SMB_MTADDNACK:
         STA = 1;                      // Restart transfer
         break;

      // Master Transmitter: Data byte transmitted.  ACK received.
      // For a READ: N/A
      //
      // For a WRITE: Send all data.  After the last data byte, send the stop
      //  bit.
      case SMB_MTDBACK:
         if (sent_byte_counter <= SMB_WriteLength)
         {
            // send data byte
            SMB0DAT = SMB_WriteBuffer[sent_byte_counter-1];
            sent_byte_counter++;
         }
         else
         {
            STO = 1;                   // Set STO to terminate transfer
            SMB_BUSY = 0;              // And free SMBus interface
         }

         break;

      // Master Transmitter: Data byte transmitted.  NACK received.
      // Restart the transfer.
      case SMB_MTDBNACK:
         STA = 1;                      // Restart transfer

         break;

      // Master Receiver: Slave address + READ transmitted.  ACK received.
      // For a READ: check if this is a one-byte transfer. if so, set the
      //  NACK after the data byte is received to end the transfer. if not,
      //  set the ACK and receive the other data bytes.
      //
      // For a WRITE: N/A
      case SMB_MRADDACK:

         if (rec_byte_counter == SMB_ReadLength)
         {
            AA = 0;                    // Only one byte in this transfer,
                                       // send NACK after byte is received
         }
         else
         {
            AA = 1;                    // More than one byte in this transfer,
                                       // send ACK after byte is received
         }

         break;

      // Master Receiver: Slave address + READ transmitted.  NACK received.
      // Restart the transfer.
      case SMB_MRADDNACK:
         STA = 1;                      // Restart transfer

         break;

      // Master Receiver: Data byte received.  ACK transmitted.
      // For a READ: receive each byte from the slave.  if this is the last
      //  byte, send a NACK and set the STOP bit.
      //
      // For a WRITE: N/A
      case SMB_MRDBACK:

         if (rec_byte_counter < SMB_ReadLength)
         {
            SMB_ReadBuffer[rec_byte_counter-1] = SMB0DAT; // Store received byte
            AA = 1;                    // Send ACK to indicate byte received
            rec_byte_counter++;        // Increment the byte counter
         }
         else
         {
            AA = 0;                    // Send NACK to indicate last byte
                                       // of this transfer
         }

         break;

      // Master Receiver: Data byte received.  NACK transmitted.
      // For a READ: Read operation has completed.  Read data register and
      //  send STOP.
      //
      // For a WRITE: N/A
      case SMB_MRDBNACK:

         SMB_ReadBuffer[rec_byte_counter-1] = SMB0DAT; // Store received byte
         STO = 1;
         SMB_BUSY = 0;
         AA = 1;                       // Set AA for next transfer

         break;

      // Master Transmitter: Arbitration lost.
      case SMB_MTARBLOST:

         FAIL = 1;                     // Indicate failed transfer
                                       // and handle at end of ISR

         break;

      // All other status codes invalid.  Reset communication.
      default:
         FAIL = 1;

         break;
   }

   if (FAIL)                           // If the transfer failed,
   {
      SMB0CN &= ~0x40;                 // Reset communication
      SMB0CN |= 0x40;
      STA = 0;
      STO = 0;
      AA = 0;
      SMB_BUSY = 0;                    // Free SMBus
      FAIL = 0;
   }

   SI = 0;                             // Clear interrupt flag
}

//-----------------------------------------------------------------------------
// Timer3 Interrupt Service Routine (ISR)
//-----------------------------------------------------------------------------
//
// A Timer3 interrupt indicates an SMBus SCL low timeout.
// The SMBus is disabled and re-enabled if a timeout occurs.
//
void Timer3_ISR (void) interrupt INTERRUPT_TIMER3
{
   SMB0CN &= ~0x40;                    // Disable SMBus
   SMB0CN |= 0x40;                     // Re-enable SMBus
   TMR3CN &= ~0x80;                    // Clear Timer3 interrupt-pending flag
   SMB_BUSY = 0;                       // Free bus
}
