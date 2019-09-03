#include "dcHmiNotifyProgress.h"
void NotifyProgress(uint16_t screen_id, uint16_t control_id, uint32_t value){ 
	switch(screen_id){
		case GDDC_PAGE_STANDBY_CW:{
			switch(control_id){
				case GDDC_PAGE_STANDBY_PROGRESS_CH0:{
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
#if CONFIG_USING_DUAL_WAVE == 1
				case GDDC_PAGE_STANDBY_PROGRESS_CH1:{
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
#endif
				default:break;
			}
			break;
		}
		case GDDC_PAGE_STANDBY_SP:{
			switch(control_id){
				case GDDC_PAGE_STANDBY_PROGRESS_CH0:{
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
#if CONFIG_USING_DUAL_WAVE == 1
				case GDDC_PAGE_STANDBY_PROGRESS_CH1:{
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
#endif
				default:break;
			}
			break;
		}
		case GDDC_PAGE_STANDBY_MP:{
			switch(control_id){
				case GDDC_PAGE_STANDBY_PROGRESS_CH0:{
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
#if CONFIG_USING_DUAL_WAVE == 1
				case GDDC_PAGE_STANDBY_PROGRESS_CH1:{
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
#endif
				default:break;
			}
			break;
		}
		case GDDC_PAGE_STANDBY_GP:{
			switch(control_id){
				case GDDC_PAGE_STANDBY_PROGRESS_CH0:{
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
#if CONFIG_USING_DUAL_WAVE == 1
				case GDDC_PAGE_STANDBY_PROGRESS_CH1:{
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
#endif
				default:break;
			}
			break;
		}
		case GDDC_PAGE_STANDBY_SIGNAL:{
			switch(control_id){
				case GDDC_PAGE_STANDBY_PROGRESS_CH0:{
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
#if CONFIG_USING_DUAL_WAVE == 1
				case GDDC_PAGE_STANDBY_PROGRESS_CH1:{
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
#endif
				default:break;
			}
			break;
		}
		case GDDC_PAGE_STANDBY_DERMA:{
			switch(control_id){
				case GDDC_PAGE_STANDBY_PROGRESS_CH0:{
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
#if CONFIG_USING_DUAL_WAVE == 1
				case GDDC_PAGE_STANDBY_PROGRESS_CH1:{
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
#endif
				default:break;
			}
			break;
		}
		case GDDC_PAGE_OPTION:{
			switch(control_id){
				case GDDC_PAGE_OPTION_PROGRESS_AIM_BRG:{
					if(value < CONFIG_MIN_AIM_BRG){
						value = CONFIG_MIN_AIM_BRG;
					}
					if(value > CONFIG_MAX_AIM_BRG){
						value = CONFIG_MAX_AIM_BRG;
					}
					NVRAM0[DM_AIM_BRG] = (int16_t)value;	
					SetTextInt32(GDDC_PAGE_OPTION, GDDC_PAGE_OPTION_TEXTDISPLAY_AIM_BRG , NVRAM0[DM_AIM_BRG], 1, 0);
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
					SetTextInt32(GDDC_PAGE_OPTION, GDDC_PAGE_OPTION_TEXTDISPLAY_BEEM_VOLUME , NVRAM0[DM_BEEM_VOLUME], 1, 0);
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
					SetTextInt32(GDDC_PAGE_OPTION, GDDC_PAGE_OPTION_TEXTDISPLAY_LCD_BRG , NVRAM0[DM_LCD_BRG], 1, 0);
					SetBackLight(getLcdDuty(NVRAM0[DM_LCD_BRG]));
					break;
				}					
				default:break;
			}
			break;
		}
	}
} 