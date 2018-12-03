#include "slaveModbusAscii.h"
#define SerialRCV	       128                    //定义串口接收缓冲区大小
#define SerialSEND	       128                    //定义串口发送缓冲区大小
/****************************************************************************/
/****************************************************************************/
/****************************************************************************/
volatile unsigned char RcvNum;                    
volatile unsigned char RcvBuf[SerialRCV];
volatile unsigned char SendBuf[SerialSEND];
volatile unsigned char *SendRead;
volatile unsigned char *SendWrite;
volatile unsigned char SendNum;
volatile unsigned char *RcvRead;   
volatile unsigned char *RcvWrite;
uint8_t FlagRcvOk, FlagRcving, FlagSendOk, FlagSending;
uint16_t OverCounter;
/****************************************************************************/

void Int_serial() interrupt 4
{
  //INT8U err;
  //OS_ENTER_CRITICAL(); //关闭Ucos 中断
	if(TI0)
    {
        TI0 = 0;        
        if(SendNum == 0)
        {
            FlagSendOk = 0;                    
        }
        else 
        {
            SBUF0 = *SendRead;			
            if(SendRead == (SendBuf + SerialSEND - 1))
            {
                SendRead = SendBuf;                        
            }
            else 
            {
                SendRead++;
            }
			SendNum--;						                   
        }
    }
    if(RI0)
    {
        RI0 = 0;  
	    if((SBUF0 == ':')){//接收到起始符号
			OverCounter = 0;
			memset(RcvBuf, 0x00, SerialRCV);
			RcvWrite = RcvBuf;
			FlagRcving = 1;
			FlagRcvOk = 0;
			RcvNum = 0;
		}
		else if(SBUF0 == 0x0D){ //接收到终止符号
		  *RcvWrite = SBUF0;
		  RcvNum++;
		  RcvWrite = RcvBuf;
		  FlagRcvOk = 1;
		  FlagRcving = 0;
		}      
        if(FlagRcving){ 
		 *RcvWrite = SBUF0;        
         if(RcvWrite == (RcvBuf + SerialRCV - 1))
         {
             RcvWrite = RcvBuf;            
         }
         else 
         {
            RcvWrite++;
         }    
         RcvNum++;
		}
   }   
   //OS_EXIT_CRITICAL();
}
                                       
void processor_queun(void)
{ 
 INT16U wtemp;
 FP64   ftemp1,ftemp2;
 INT8U *queun_location,err;
 queun_location = RcvBuf;
 if	(FlagRcvOk)  
 {
  //FlagRcvOk = 0;
  if( *(queun_location) == 'A' && Locked != 1)    //检测到A指令且不再锁定态调节设置
  {//检测到调节 A 命令
     /********************************************************************************/
	 /*设定CH1 电流                                                                  */
	 /********************************************************************************/
	 CH1cur = ( *(queun_location + 1) - 0x30 ) * 100 + ( *(queun_location + 2) - 0x30 ) * 10 + ( *(queun_location + 3) - 0x30 );
	 if(CH1cur >= CH1MAXCUR) CH1cur = CH1MAXCUR; //接收到的电流大于定义的最大电流时 以最大电流为限度
	 ftemp1 = (FP64)CH1cur / CH1MAXCUR;   //归一化电流值 [0,1]
   	 DACOut020(1,ftemp1);                 //设置新的电流值 CH1
	 /********************************************************************************/
	 /*设定CH2 电流                                                                  */
	 /********************************************************************************/
	 CH2cur = ( *(queun_location + 9) - 0x30 ) * 100 + ( *(queun_location +10) - 0x30 ) * 10 + ( *(queun_location +11) - 0x30 );
	 if(CH2cur >= CH2MAXCUR) CH2cur = CH2MAXCUR; //接收到的电流大于定义的最大电流时 以最大电流为限度
	 ftemp2 = (FP64)CH2cur / CH2MAXCUR;   //归一化电流值 [0,1]
     DACOut020(2,ftemp2);                 //设置新的电流值 CH1
	 /*********************************************************************************/
	 /*设定CH1 占空比                                                                 */
	 /*********************************************************************************/
	 wtemp = ( *(queun_location + 5) - 0x30 ) * 100 + ( *(queun_location + 6) - 0x30 ) * 10 + ( *(queun_location + 7) - 0x30 );
	 if(wtemp < 5 ) wtemp = 5;    //限定PWM 占空比在0-100%
	 if(wtemp >= 100) wtemp = 100;
	 ftemp1 = ( (FP64)wtemp / 100 ) * 255;   
	 wtemp = (INT8U)ftemp1;
	 if(wtemp < 0 ) wtemp = 0;    
	 if(wtemp >= 255) wtemp = 255;
	 //CH1cyc = wtemp;     //更新CH1占空比
	 /*********************************************************************************/
	 /*设定CH2 占空比                                                                 */
	 /*********************************************************************************/
	 wtemp = ( *(queun_location +13) - 0x30 ) * 100 + ( *(queun_location +14) - 0x30 ) * 10 + ( *(queun_location +15) - 0x30 );
	 if(wtemp < 5 ) wtemp = 5;    //限定PWM 占空比在0-100%
	 if(wtemp >= 100) wtemp = 100;
	 ftemp1 = ( (FP64)wtemp / 100 ) * 255;   
	 wtemp = (INT8U)ftemp1;
	 if(wtemp < 0 ) wtemp = 0;    
	 if(wtemp >= 255) wtemp = 255;
	 //CH2cyc = wtemp;     //更新CH1占空比
	 /*********************************************************************************/
	 /*RCK*****************************************************************************/
  	 memset(SendBuf,0x00,SerialRCV);
	 SendBuf[0] = 'C';
	 SendBuf[1]	= 'A';
   	 SendBuf[2] = 13; //回车
     StarSendUart0();
	 /*********************************************************************************/	          
   }




 }
 FlagRcvOk = 0;
}
