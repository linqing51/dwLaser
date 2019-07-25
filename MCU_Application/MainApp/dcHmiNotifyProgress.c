#include "dcHmiNotifyProgress.h"
void NotifyProgress(uint16_t screen_id, uint16_t control_id, uint32_t value){ 
	uint8_t dispBuf[16];
	switch(screen_id){
		case GDDC_PAGE_STANDBY_CW_0:{
			switch(control_id){
				case GDDC_PAGE_STANDBY_CW_PROGRESS_CH0:{
					if(value > 100){
						value = 100;
					}
					if(value < 0){
						value = 0;
					}
					NVRAM0[EM_LASER_POWER_CH0] = (int16_t)(value * CONFIG_MAX_LASERPOWER_CH0 / 100);
					NVRAM0[EM_TOTAL_POWER] = NVRAM0[EM_LASER_POWER_CH0] + NVRAM0[EM_LASER_POWER_CH1];
					updatePowerDisplay(LASER_SELECT_CH0, LASER_MODE_CW);					
					break;
				}
				case GDDC_PAGE_STANDBY_CW_PROGRESS_CH1:{
					if(value > 100){
						value = 100;
					}
					if(value < 0){
						value = 0;
					}
					NVRAM0[EM_LASER_POWER_CH1] = (int16_t)(value * CONFIG_MAX_LASERPOWER_CH1 / 100);
					NVRAM0[EM_TOTAL_POWER] = NVRAM0[EM_LASER_POWER_CH0] + NVRAM0[EM_LASER_POWER_CH1];
					updatePowerDisplay(LASER_SELECT_CH1, LASER_MODE_CW);
					break; 					
				}
				default:break;
			}
			break;
		}
		case GDDC_PAGE_STANDBY_SP_0:{
			switch(control_id){
				case GDDC_PAGE_STANDBY_SP_PROGRESS_CH0:{
					if(value > 100){
						value = 100;
					}
					if(value < 0){
						value = 0;
					}
					NVRAM0[EM_LASER_POWER_CH0] = (int16_t)(value * CONFIG_MAX_LASERPOWER_CH0 / 100);
					NVRAM0[EM_TOTAL_POWER] = NVRAM0[EM_LASER_POWER_CH0] + NVRAM0[EM_LASER_POWER_CH1];
					updatePowerDisplay(LASER_SELECT_CH0, LASER_MODE_SP);
					break;
				}
				case GDDC_PAGE_STANDBY_SP_PROGRESS_CH1:{
					if(value > 100){
						value = 100;
					}
					if(value < 0){
						value = 0;
					}
					NVRAM0[EM_LASER_POWER_CH1] = (int16_t)(value * CONFIG_MAX_LASERPOWER_CH1 / 100);
					NVRAM0[EM_TOTAL_POWER] = NVRAM0[EM_LASER_POWER_CH0] + NVRAM0[EM_LASER_POWER_CH1];
					updatePowerDisplay(LASER_SELECT_CH1, LASER_MODE_SP);				
					break; 					
				}
				default:break;
			}
			break;
		}
		case GDDC_PAGE_STANDBY_MP_0:{
			switch(control_id){
				case GDDC_PAGE_STANDBY_MP_PROGRESS_CH0:{
					if(value > 100){
						value = 100;
					}
					if(value < 0){
						value = 0;
					}
					NVRAM0[EM_LASER_POWER_CH0] = (int16_t)(value * CONFIG_MAX_LASERPOWER_CH0 / 100);
					NVRAM0[EM_TOTAL_POWER] = NVRAM0[EM_LASER_POWER_CH0] + NVRAM0[EM_LASER_POWER_CH1];
					updatePowerDisplay(LASER_SELECT_CH0, LASER_MODE_MP);
					break;
				}
				case GDDC_PAGE_STANDBY_MP_PROGRESS_CH1:{
					if(value > 100){
						value = 100;
					}
					if(value < 0){
						value = 0;
					}
					NVRAM0[EM_LASER_POWER_CH1] = (int16_t)(value * CONFIG_MAX_LASERPOWER_CH1 / 100);
					NVRAM0[EM_TOTAL_POWER] = NVRAM0[EM_LASER_POWER_CH0] + NVRAM0[EM_LASER_POWER_CH1];
					updatePowerDisplay(LASER_SELECT_CH1, LASER_MODE_MP);		
					break; 					
				}
				default:break;
			}
			break;
		}
		case GDDC_PAGE_STANDBY_GP_0:{
			switch(control_id){
				case GDDC_PAGE_STANDBY_GP_PROGRESS_CH0:{
					if(value > 100){
						value = 100;
					}
					if(value < 0){
						value = 0;
					}
					NVRAM0[EM_LASER_POWER_CH0] = (int16_t)(value * CONFIG_MAX_LASERPOWER_CH0 / 100);
					NVRAM0[EM_TOTAL_POWER] = NVRAM0[EM_LASER_POWER_CH0] + NVRAM0[EM_LASER_POWER_CH1];
					updatePowerDisplay(LASER_SELECT_CH0, LASER_MODE_GP);
					break;
				}
				case GDDC_PAGE_STANDBY_GP_PROGRESS_CH1:{
					if(value > 100){
						value = 100;
					}
					if(value < 0){
						value = 0;
					}
					NVRAM0[EM_LASER_POWER_CH1] = (int16_t)(value * CONFIG_MAX_LASERPOWER_CH1 / 100);
					NVRAM0[EM_TOTAL_POWER] = NVRAM0[EM_LASER_POWER_CH0] + NVRAM0[EM_LASER_POWER_CH1];
					updatePowerDisplay(LASER_SELECT_CH1, LASER_MODE_GP);
					break; 					
				}
				default:break;
			}
			break;
		}
		case GDDC_PAGE_STANDBY_SIGNAL_0:{
			switch(control_id){
				case GDDC_PAGE_STANDBY_SIGNAL_PROGRESS_CH0:{
					if(value > 100){
						value = 100;
					}
					if(value < 0){
						value = 0;
					}
					NVRAM0[EM_LASER_POWER_CH0] = (int16_t)(value * CONFIG_MAX_LASERPOWER_CH0 / 100);
					NVRAM0[EM_TOTAL_POWER] = NVRAM0[EM_LASER_POWER_CH0] + NVRAM0[EM_LASER_POWER_CH1];
					updatePowerDisplay(LASER_SELECT_CH0, LASER_MODE_SIGNAL);
					break;
				}
				case GDDC_PAGE_STANDBY_SIGNAL_PROGRESS_CH1:{
					if(value > 100){
						value = 100;
					}
					if(value < 0){
						value = 0;
					}
					NVRAM0[EM_LASER_POWER_CH1] = (int16_t)(value * CONFIG_MAX_LASERPOWER_CH1 / 100);
					NVRAM0[EM_TOTAL_POWER] = NVRAM0[EM_LASER_POWER_CH0] + NVRAM0[EM_LASER_POWER_CH1];
					updatePowerDisplay(LASER_SELECT_CH1, LASER_MODE_SIGNAL);
					break; 					
				}
				default:break;
			}
			break;
		}
		case GDDC_PAGE_STANDBY_DERMA_0:{
			switch(control_id){
				case GDDC_PAGE_STANDBY_DERMA_PROGRESS_CH0:{
					if(value > 100){
						value = 100;
					}
					if(value < 0){
						value = 0;
					}
					NVRAM0[EM_LASER_POWER_CH0] = (int16_t)(value * CONFIG_MAX_LASERPOWER_CH0 / 100);
					NVRAM0[EM_TOTAL_POWER] = NVRAM0[EM_LASER_POWER_CH0] + NVRAM0[EM_LASER_POWER_CH1];
					updatePowerDisplay(LASER_SELECT_CH0, LASER_MODE_DERMA);
					break;
				}
				case GDDC_PAGE_STANDBY_DERMA_PROGRESS_CH1:{
					if(value > 100){
						value = 100;
					}
					if(value < 0){
						value = 0;
					}
					NVRAM0[EM_LASER_POWER_CH1] = (int16_t)(value * CONFIG_MAX_LASERPOWER_CH1 / 100);
					NVRAM0[EM_TOTAL_POWER] = NVRAM0[EM_LASER_POWER_CH0] + NVRAM0[EM_LASER_POWER_CH1];
					updatePowerDisplay(LASER_SELECT_CH1, LASER_MODE_DERMA);
					break; 					
				}
				default:break;
			}
			break;
		}
		case GDDC_PAGE_OPTION_0:{
			switch(control_id){
				case GDDC_PAGE_OPTION_PROGRESS_AIM_BRG:{
					if(value < CONFIG_MIN_AIM_BRG){
						value = CONFIG_MIN_AIM_BRG;
					}
					if(value > CONFIG_MAX_AIM_BRG){
						value = CONFIG_MAX_AIM_BRG;
					}
					NVRAM0[DM_AIM_BRG] = (int16_t)value;	
					SetTextInt32(GDDC_PAGE_OPTION_0, GDDC_PAGE_OPTION_TEXTDISPLAY_AIM_BRG , NVRAM0[DM_AIM_BRG], 1, 0);
					break;
				}
				case GDDC_PAGE_OPTION_PROGRESS_BEEM_VOLUME:{
					if(value < CONFIG_MIN_BEEM_VOLUME){
						value = CONFIG_MIN_BEEM_VOLUME;
					}
					if(value > CONFIG_MAX_BEEM_VOLUME){
						value = CONFIG_MAX_BEEM_VOLUME;
					}
					NVRAM0[DM_BEEM_VOLUME] = (int16_t)value;
					SetTextInt32(GDDC_PAGE_OPTION_0, GDDC_PAGE_OPTION_TEXTDISPLAY_BEEM_VOLUME , NVRAM0[DM_BEEM_VOLUME], 1, 0);
					break;
				}
				case GDDC_PAGE_OPTION_PROGRESS_LCD_BRG:{
					if(value < CONFIG_MIN_LCD_BRG){
						value = CONFIG_MIN_LCD_BRG;
					}
					if(value > CONFIG_MAX_LCD_BRG){
						value = CONFIG_MAX_LCD_BRG;
					}
					NVRAM0[DM_LCD_BRG] = (int16_t)value;
					SetTextInt32(GDDC_PAGE_OPTION_0, GDDC_PAGE_OPTION_TEXTDISPLAY_LCD_BRG , NVRAM0[DM_LCD_BRG], 1, 0);
					SetBackLight(getLcdDuty(NVRAM0[DM_LCD_BRG]));
					break;
				}					
				default:break;
			}
			break;
		}
	}
} 