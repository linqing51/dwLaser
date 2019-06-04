#include "sPlcUsb.h"
/*****************************************************************************/
#if CONFIG_SPLC_USING_CH376 == 1
static void sPlcUsbDiskConnectPoll(void){//USB DISK连接轮询 周期200mS	
	T10MS(T10MS_USBDISK_CONNECT_DELAY, true, 20);//启动计时器延时
	if(LD(T_10MS_START * 16U + T10MS_USBDISK_CONNECT_DELAY)){
		if(CH376DiskConnect() == USB_INT_SUCCESS){//检查U盘是否连接,等待U盘插入
			SET(SPCOIL_USBDISK_CONNECT_DONE);
		}
		else{
			RES(SPCOIL_USBDISK_CONNECT_DONE);
		}
		T10MS(T10MS_USBDISK_CONNECT_DELAY, false, 20);
	}
}
static void sPlcUsbDiskMountPoll(void){//USB DISK载入轮询 周期100mS
	uint8_t i;
	for(i = 0;i < 5;i ++){
		T10MS(T10MS_USBDISK_MOUNT_DELAY, true, 10);//启动计时器延时100mS
		if(LD(T_10MS_START * 16 + T10MS_USBDISK_MOUNT_DELAY)){
			if(CH376DiskMount() == USB_INT_SUCCESS){ 
				SET(SPCOIL_USBDISK_MOUNT_DONE);
			}
			else{
				RES(SPCOIL_USBDISK_MOUNT_DONE);
			}
			T10MS(T10MS_USBDISK_MOUNT_DELAY, false, 5);//启动计时器延时100mS
		}
	}
}
static void sPlcUsbDiskRemove(void){//USB DISK安全移除
	uint8_t s;
	if(LD(SPCOIL_USBDISK_CONNECT_DONE) && LDB(SPCOIL_USBDISK_REMOVE_DOING)){
		RES(SPCOIL_USBDISK_REMOVE_DONE);
		SET(SPCOIL_USBDISK_REMOVE_DOING);
		s = CH376SendCmdDatWaitInt(CMD1H_SET_CONFIG, 0);//取消配置,会导致很多U盘的LED灯灭
		RES(SPCOIL_USBDISK_REMOVE_DOING);
	}
	T10MS(T10MS_USBDISK_REMOVE_DELAY, true, 50);//启动计时器延时100mS
	if(LD(T_10MS_START * 16 + T10MS_USBDISK_REMOVE_DELAY)){
		if(s == USB_INT_SUCCESS){
			SET(SPCOIL_USBDISK_REMOVE_DONE);
			RES(SPCOIL_USBDISK_CONNECT_DONE);
			RES(SPCOIL_USBDISK_MOUNT_DONE);
		}
		else{
			RES(SPCOIL_USBDISK_REMOVE_DONE);
		}
		RES(SPCOIL_USBDISK_REMOVE_DOING);
		RES(SPCOIL_USBDISK_REMOVE_REQ);
		T10MS(T10MS_USBDISK_REMOVE_DELAY, false, 50);//启动计时器延时100mS
	}
}
	
void sPlcUsbPoll(void){//USB 控制轮询
	if(LD(SPCOIL_USBHOST_CONNECT_REQ)){
		sPlcUsbDiskConnectPoll();
	}
	if(LD(SPCOIL_USBDISK_MOUNT_REQ)){
		sPlcUsbDiskMountPoll();
	}
	if(LD(SPCOIL_USBDISK_REMOVE_REQ)){
		sPlcUsbDiskRemove();
	}
}	
#endif