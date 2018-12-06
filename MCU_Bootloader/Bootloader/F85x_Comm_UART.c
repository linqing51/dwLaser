
#define CMD_STX								0x81
#define CMD_END								0x91
#define CMD_GET_HW_VER_TX_SZ				3
#define CMD_GET_HW_VER_RX_SZ 				6
#define CMD_SET_HW_VER_TX_SZ				7
#define CMD_SET_HW_VER_RX_SZ				3





void cmdPoll(void)
{
	uint16_t i;
	uint8_t CmdRxDone, CmdRxDoing;
	while(1)
	{
		uart0Receive(&temp, 1)
		if(temp == CMD_STX)
		{
			CmdRxDoing = 1;
			rxbuf[i++] = temp;
			do{
				uart0Receive(&temp, 1);
				rxbuf[i++] = temp;
				if(temp == CMD_END)
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


