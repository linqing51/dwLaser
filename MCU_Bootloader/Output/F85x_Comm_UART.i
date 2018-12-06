
#line 1 "Bootloader\F85x_Comm_UART.c" /0
 
 
 
 
 
 
 
 
 uint8_t * CmdGetHwVer(void)
 {
 uint8_t txbuf[3], rxbuf[6];
 cmd[0] = 0x81;
 cmd[1] = CMD_GET_ID;
 cmd[2] = 0x91
 uart0Send(&cmd, 3);
 uart0Receive(rx_buf, 6); 
 return (rxbuf + 1); 
 }
 
 void CmdSetHwVer(uint16_t ver)
 {
 uint8_t txbuf[7], rxbuf[3];
 txbuf[0] = 0x81;
 txbuf[1] = CMD_SET_HW_VER;
 uint16ToAscii(&ver, txbuf[2]);
 txbuf[6] = 0x91;
 uart0Receive(rxbuf, 3); 
 }
 void CmdResetMcu(void)
 {
 uint8_t txbuf[CMD_RESET_MCU_TX_SZ], rxbuf[CMD_RESET_MCU_RX_SZ];
 txbuf[0] = 0x81;
 txbuf[1] = CMD_SET_HW_VER;
 
 }
 
 
 void cmdPoll(void)
 {
 uint16_t i;
 uint8_t CmdRxDone, CmdRxDoing;
 while(1)
 {
 uart0Receive(&temp, 1)
 if(temp == 0x81)
 {
 CmdRxDoing = 1;
 rxbuf[i++] = temp;
 do{
 uart0Receive(&temp, 1);
 rxbuf[i++] = temp;
 if(temp == 0x91)
 {
 CmdRxDone = 1;
 switch(rxbuf[1])
 {
 case CMD_SET_HW_VER:
 break;
 case CMD_GET_HW_VER:
 break;
 case CMD_RESET_MCU:
 break;
 case CMD_GET_BOOTLOADER_VER:
 break;
 case CMD_GET_OTA1_VER:
 break;
 case CMD_GET_OTA2_VER:
 break;
 case CMD_GET_OTA1_CRC32:
 break;
 default:break;
 }
 break;
 }
 else if(i >= CMD_RX_BUFFER_SIZE)
 {
 CmdRxDoing = 0;
 break;
 }
 }while(1);
 }
 }
 }
 
 
 void uart0send(uint8_t *buf, uint16_t count)
 {
 uint8_t *ptr = buf;
 do{
 SBUF0 = *ptr++;
 while(TI0 == 0);
 TI0 = 0;
 }while(--count);
 }
 
 void uart0receive(uint8_t *buf, uint16_t count)
 {
 uint8_t * ptr = buf;
 do{
 if(RI0 == 1)
 {
 *ptr++ = SBUF0;
 RI0 = 0;
 count--;
 }
 }while(count);
 }
 
