/************************************版权申明********************************************
**                             广州大彩光电科技有限公司
**                             http://www.gz-dc.com
**-----------------------------------文件信息--------------------------------------------
** 文件名称:   mian.c
** 修改时间:   2018-05-18
** 文件说明:   主函数
** 技术支持：  Tel: 020-82186683  Email: hmi@gz-dc.com Web:www.gz-dc.com
--------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------*/
/*****************************************************************************/
#include "hmiLib.h"
/*****************************************************************************/
#define FLASH_DATA_VERSION  0XAABB0000
#define FLASH_DATA_ADDR     0X00000000
/*****************************************************************************/
                                           
uint8_t  hmiCmdBuffer[CMD_MAX_SIZE];//指令缓存
//static uint16_t current_screen_id = 0;                                                 //当前画面ID
//static int32_t Progress_Value = 0;                                                     //进度条测试值
//static int32_t test_value = 0;                                                         //测试值
//static uint8_t update_en = 0;                                                          //更新标记
//static int32_t meter_flag = 0;                                                         //仪表指针往返标志位
//static int32_t num = 0;                                                                //曲线采样点计数
//static int sec = 1;                                                                  //时间秒
//static int32_t curves_type = 0;                                                        //曲线标志位  0为正弦波，1为锯齿波                  
//static int32_t second_flag=0;                                                          //时间标志位                                                                       
//static int32_t icon_flag = 0;                                                          //图标标志位
//static uint8_t Select_H ;                                                              //滑动选择小时
//static uint8_t Select_M ;                                                              //滑动选择分钟 
//static uint8_t Last_H ;                                                                //上一个选择小时
//static uint8_t Last_M;                                                                 //上一个选择分钟 


void UpdateUI(void);                                                                 //更新UI数据


//void hmiLoop(void){//程序入口
//    qsize  size = 0;
//    uint32_t timer_tick_last_update = 0;

//    queue_reset();//清空指令接收缓冲区

//    /*延时等待串口屏初始化完毕,必须等待300ms*/
//    delay_ms(300);

//    //尝试从FLASH中恢复设置
//    FlashRestoreControl(FLASH_DATA_VERSION,FLASH_DATA_ADDR);

//    while(1)
//    {
//        size = queue_find_cmd(hmiCmdBuffer,CMD_MAX_SIZE);                              //从缓冲区中获取一条指令         

//        if(size>0)                                                                   //接收到指令 ，及判断是否为开机提示
//        {                                                                           
//            ProcessMessage((PCTRL_MSG)hmiCmdBuffer, size);                             //指令处理  
//        }                                                                           



//        
//        //特别注意
//        //MCU不要频繁向串口屏发送数据，否则串口屏的内部缓存区会满，从而导致数据丢失(缓冲区大小：标准型8K，基本型4.7K)
//        //1) 一般情况下，控制MCU向串口屏发送数据的周期大于100ms，就可以避免数据丢失的问题；
//        //2) 如果仍然有数据丢失的问题，请判断串口屏的BUSY引脚，为高时不能发送数据给串口屏。
//        
//        //    TODO: 添加用户代码
//        //    数据有更新时标志位发生改变，定时100毫秒刷新屏幕
//        if(update_en && (timer_tick_count - timer_tick_last_update >= TIME_100MS))
//        {
//            update_en = 0;
//            timer_tick_last_update = timer_tick_count;   

//            UpdateUI();
//        } 

//        //这里为了方便演示不同的功能，在UpdateUI函数里对不同功能进行定时启动
//        //进一次中断10ms，timer_tick_count值+1,100*timer_tick_count = 1s
//        UpdateUI(); 

//    }  
//}

/*! 
*  \brief  消息处理流程
*  \param msg 待处理消息
*  \param size 消息长度
*/
void ProcessMessage( PCTRL_MSG msg, uint16_t size ){
    uint8_t cmd_type = msg->cmd_type;                                                     //指令类型
    uint8_t ctrl_msg = msg->ctrl_msg;                                                     //消息的类型
    uint8_t control_type = msg->control_type;                                             //控件类型
    uint16_t screen_id = PTR2U16(&msg->screen_id);                                        //画面ID
    uint16_t control_id = PTR2U16(&msg->control_id);                                      //控件ID
    uint32_t value = PTR2U32(msg->param);                                                 //数值


    switch(cmd_type)
    {  
        case NOTIFY_TOUCH_PRESS:                                                        //触摸屏按下
    case NOTIFY_TOUCH_RELEASE:                                                          //触摸屏松开
        NotifyTouchXY(hmiCmdBuffer[1],PTR2U16(hmiCmdBuffer + 2),PTR2U16(hmiCmdBuffer + 4)); 
        break;                                                                    
    case NOTIFY_WRITE_FLASH_OK:                                                         //写FLASH成功
        NotifyWriteFlash(1);                                                      
        break;                                                                    
    case NOTIFY_WRITE_FLASH_FAILD:                                                      //写FLASH失败
        NotifyWriteFlash(0);                                                      
        break;                                                                    
    case NOTIFY_READ_FLASH_OK:                                                          //读取FLASH成功
        NotifyReadFlash(1,hmiCmdBuffer + 2,size-6);                                         //去除帧头帧尾
        break;                                                                    
    case NOTIFY_READ_FLASH_FAILD:                                                       //读取FLASH失败
        NotifyReadFlash(0,0,0);                                                   
        break;                                                                    
    case NOTIFY_READ_RTC:                                                               //读取RTC时间
        NotifyReadRTC(hmiCmdBuffer[2], hmiCmdBuffer[3], hmiCmdBuffer[4], hmiCmdBuffer[5], hmiCmdBuffer[6], hmiCmdBuffer[7], hmiCmdBuffer[8]);
        break;
    case NOTIFY_CONTROL:
        {
            if(ctrl_msg==MSG_GET_CURRENT_SCREEN)                                        //画面ID变化通知
            {
                NotifyScreen(screen_id);                                                //画面切换调动的函数
            }
            else
            {
                switch(control_type)
                {
                case kCtrlButton:                                                       //按钮控件
                    NotifyButton(screen_id,control_id,msg->param[1]);                  
                    break;                                                             
                case kCtrlText:                                                         //文本控件
                    NotifyText(screen_id,control_id,msg->param);                       
                    break;                                                             
                case kCtrlProgress:                                                     //进度条控件
                    NotifyProgress(screen_id,control_id,value);                        
                    break;                                                             
                case kCtrlSlider:                                                       //滑动条控件
                    NotifySlider(screen_id,control_id,value);                          
                    break;                                                             
                case kCtrlMeter:                                                        //仪表控件
                    NotifyMeter(screen_id,control_id,value);                           
                    break;                                                             
                case kCtrlMenu:                                                         //菜单控件
                    NotifyMenu(screen_id,control_id,msg->param[0],msg->param[1]);      
                    break;                                                              
                case kCtrlSelector:                                                     //选择控件
                    NotifySelector(screen_id,control_id,msg->param[0]);                
                    break;                                                              
                case kCtrlRTC:                                                         //倒计时控件
                    NotifyTimer(screen_id,control_id);
                    break;
                default:
                    break;
                }
            } 
            break;  
        } 
    case NOTIFY_HandShake:
        //NOTIFYHandShake();
        break;
    default:
        break;
    }
}

/*! 
*  \brief  string 转 int
*  \param char *str  数字字符串
*/
int str2int(const char *str){
    int temp = 0;
    const char *ptr = str;                                                            //记录字符串

    if(*str == '-' || *str == '+')                                                    //判断第一个字符是否是正负
    {                                                                            
        str++;                                                                        //偏移一位
    }                                                                            
    while(*str != 0)                                                             
    {                                                                            
        if ((*str < '0') || (*str > '9'))                                             //检测是否为数字字符 
        {                                                                        
            break;                                                               
        }                                                                        
        temp = temp * 10 + (*str - '0');                                              //转换
        str++;                                                                        //偏移一位
    }                                                                            
    if (*ptr == '-')                                                                  //如果为负数就取反
    {
        temp = -temp;
    }

    return temp;   
}
/*! 
*  \brief  画面切换通知
*  \details  当前画面改变时(或调用GetScreen)，执行此函数
*  \param screen_id 当前画面ID
*/
void NotifyScreen(uint16_t screen_id){
    //TODO: 添加用户代码
//    current_screen_id = screen_id;                                                     //在工程配置中开启画面切换通知，记录当前画面ID
//                                                                                   
//                                                                                   
//    //进到画面3亮起一个按钮                                                        
//    if(screen_id == 3)                                                             
//    {                                                                              
//        SetButtonValue(3,1,1);    
//        SetHandShake();        
//    }                                                                             
//    //进到画面自动播放GIF                                                          
//    if(current_screen_id == 9)                                                     
//    {                                                                              
//        AnimationStart(9,1);                                                           //动画开始播放
//    }

//    //进到二维码页面生成二维码
//    if(current_screen_id==14)                                   
//    {
//        //二维码控件显示中文字符时，需要转换为UTF8编码，
//        //通过“指令助手”，转换“www.gz-dc.com” ，得到字符串编码如下
//        uint8_t dat[] = {0x77,0x77,0x77,0x2E,0x67,0x7A,0x2D,0x64,0x63,0x2E,0x63,0x6F,0x6D};
//        SetTextValue(14,1,dat);                                                        //发送二维码字符编码                     
//    }

//    //数据记录显示
//    if(current_screen_id == 15)
//    {
//        Record_SetEvent(15,1,0,0);  
//        Record_SetEvent(15,1,1,0);                                                      //设置触发警告
//        Record_SetEvent(15,1,2,0);
//        Record_SetEvent(15,1,3,0);
//        Record_SetEvent(15,1,4,0);
//        Record_SetEvent(15,1,5,0);
//        Record_SetEvent(15,1,6,0);
//        Record_SetEvent(15,1,7,0);
//        //delay_ms(2000);                                                                 //延时两秒
//        Record_ResetEvent(15,1,0,0);                                                    //设置解除警告
//        Record_ResetEvent(15,1,1,0);
//        Record_ResetEvent(15,1,2,0);

//    }
//    //进入音乐画面自动播放
//    if(current_screen_id == 17)   
//    {
//         uint8_t buffer[6] = {0x90,0x01 ,0x00 ,0x01 ,0x01};
//         SetButtonValue(17,3,1);
//         PlayMusic(buffer);                                                           //播放音乐
//    }
}

/*! 
*  \brief  触摸坐标事件响应
*  \param press 1按下触摸屏，3松开触摸屏
*  \param x x坐标
*  \param y y坐标
*/
void NotifyTouchXY(uint8_t press,uint16_t x,uint16_t y){
    //TODO: 添加用户代码
}


/*! 
*  \brief  更新数据
*/ 
void UpdateUI(void){
//    //文本设置和显示  定时10ms刷新一次数据
//    if(current_screen_id==4 && timer_tick_count %1 == 0)                                              
//    {
//        //当前电流、温度从0到1000循环显示，艺术字从0-999循环显示
//        SetTextInt32(4,6,test_value%1000,0,1);                                      //当前电流
//        SetTextInt32(4,7,test_value%1000,0,1);                                      //艺术字
//        SetTextValue(4,1,"机房10");                                                 //设置文本值
//        test_value++;                                                                
//        if(test_value >= 1000)                                                       
//        {                                                                            
//            test_value = 0;                                                            
//        }                                                                            
//        if(test_value>0&&test_value<500)                                            //大于0小于500文本显示红色
//        {                                                                           
//            SetControlBackColor(4,6,0xF800);                                        //设置文本背景色
//        }                                                                           
//        else if(test_value>=500)                                                    //大于500文本显蓝色
//        {                                                                           
//            SetControlBackColor(4,6,0x001F);                                        //设置文本背景色
//        }                                                                           
//    }                                                                               

//    //仪表控件更新数据                                                
//    if(current_screen_id == 6)                                                                         
//    {                                                                              
//        if(meter_flag == 0)                                                         //标志位 0顺时针 ，1逆时针
//        {   
//            //顺时针旋转                    
//            Set_picMeterValue(6,2,test_value);                                      //设置图片指针旋转角度
//            test_value +=1;                                                         //指针旋转从0度到260度
//            if(test_value >= 260)                                                   
//            {                                                                        
//                test_value = 260;                                                     
//                meter_flag = 1;                                                             
//            }                                                                        
//        }                                                                          
//        else if(meter_flag == 1)                                                               
//        {    
//            //逆时针旋转              
//            Set_picMeterValue(6,2,test_value);                                      //设置图片指针旋转角度
//            test_value -=1;                                                         //指针旋转从260度到0度
//            if(test_value <= 0)
//            {
//                test_value = 0;
//                meter_flag = 0;    
//            }
//        }
//    }

//      //图标1s轮流显示 
//    if(current_screen_id == 10)
//    {
//        if(timer_tick_count %100 == 0 && icon_flag == 0)       
//         {        
//             SetButtonValue(10,5,0); 
//             SetButtonValue(10,2,1);                                                      //工作中图标
//             AnimationPlayFrame(10,1,0);
//             icon_flag = 1 ;            
//         }
//         else if(timer_tick_count %100 == 0 && icon_flag == 1)
//         {
//             SetButtonValue(10,2,0);                                                      
//             SetButtonValue(10,3,1);                                                      //暂停中图标
//             AnimationPlayFrame(10,1,1);  
//             icon_flag = 2;             
//         }
//         else if(timer_tick_count %100 == 0 && icon_flag == 2)
//         {
//             SetButtonValue(10,3,0);                                                      
//             SetButtonValue(10,4,1);                                                      //停止图标
//             AnimationPlayFrame(10,1,2);  
//             icon_flag = 3 ;            
//         }
//         else if(timer_tick_count %100 == 0 && icon_flag == 3)
//         {        
//             SetButtonValue(10,4,0);                                                                                                                  
//             SetButtonValue(10,5,1);                                                      //隐藏图标
//             AnimationPlayFrame(10,1,3);  
//             icon_flag  = 0 ;              
//         }
//    }



//    //实时曲线，正弦波数组。
//    if(current_screen_id == 11 )      
//    { 
//        if(curves_type == 0)
//        {
//            //正弦数组
//            uint8_t code sin[256] = {1,1,1,1,1,2,3,4,6,8,10,13,15,
//                19,22,25,29,33,38,42,47,52,57,62,68,73,79,85,91,97,103,109,115,121,127,134,
//                140,146,152,158,164,170,176,182,187,193,198,203,208,213,217,222,226,230,233,
//                236,240,242,245,247,249,251,252,253,254,254,254,254,254,253,252,251,249,247,
//                245,242,240,236,233,230,226,222,217,213,208,203,198,193,187,182,176,170,164,
//                158,152,146,140,134,128,121,115,109,103,97,91,85,79,73,68,62,57,52,47,42,38,
//                33,29,25,22,19,15,13,10,8,6,4,3,2,1,1,1,1,1,2,3,4,6,8,10,13,15,
//                19,22,25,29,33,38,42,47,52,57,62,68,73,79,85,91,97,103,109,115,121,127,134,
//                140,146,152,158,164,170,176,182,187,193,198,203,208,213,217,222,226,230,233,
//                236,240,242,245,247,249,251,252,253,254,254,254,254,254,253,252,251,249,247,
//                245,242,240,236,233,230,226,222,217,213,208,203,198,193,187,182,176,170,164,
//                158,152,146,140,134,128,121,115,109,103,97,91,85,79,73,68,62,57,52,47,42,38,
//                33,29,25,22,19,15,13,10,8,6,4,3,2};
//                  
//            GraphChannelDataAdd(11,1,0,&sin[num],2);                                    //添加数据到曲线  一次一个数据
//       
//            num +=2 ;                                                                        
//            if(num >= 255)                                                                
//            {                                                                             
//                num =0;                                                                  
//            }
//        } 
//        else if(curves_type == 1)
//        {
//            //锯齿波数组
//            uint8_t code sawtooth[180] = {0,9,18,27,36,45,54,63,72,81,90,99,108,117,126,135,144,153,162,171,180,189,198,207,216,225,234,243,252,
//                0,9,18,27,36,45,54,63,72,81,90,99,108,117,126,135,144,153,162,171,180,189,198,207,216,225,234,243,252,
//                0,9,18,27,36,45,54,63,72,81,90,99,108,117,126,135,144,153,162,171,180,189,198,207,216,225,234,243,252,
//                0,9,18,27,36,45,54,63,72,81,90,99,108,117,126,135,144,153,162,171,180,189,198,207,216,225,234,243,252,
//                0,9,18,27,36,45,54,63,72,81,90,99,108,117,126,135,144,153,162,171,180,189,198,207,216,225,234,243,252,
//                0,9,18,27,36,45,54,63,72,81,90,99,108,117,126,135,144,153,162,171,180,189,198,207,216,225,234,243,252};

//            GraphChannelDataAdd(11,1,0,&sawtooth[num],2);                                //添加数据到曲线  一次一个数据

//            num += 2;                                                                        
//            if(num >= 180)                                                                
//            {                                                                             
//                num =0;                                                                  
//            }
//        }          
//    }                                                                              

//    //历时曲线，正弦波数组                                                         
//    if(current_screen_id == 16 && timer_tick_count %100 == 0)                          //历史曲线控件采样周期1s一个点。//一次添加五个数据                                                    
//    {   
//        if(curves_type == 0)
//        {        
//            //正弦数组
//            uint8_t code sin[256] = {1,1,1,1,1,2,3,4,6,8,10,13,15,
//                19,22,25,29,33,38,42,47,52,57,62,68,73,79,85,91,97,103,109,115,121,127,134,
//                140,146,152,158,164,170,176,182,187,193,198,203,208,213,217,222,226,230,233,
//                236,240,242,245,247,249,251,252,253,254,254,254,254,254,253,252,251,249,247,
//                245,242,240,236,233,230,226,222,217,213,208,203,198,193,187,182,176,170,164,
//                158,152,146,140,134,128,121,115,109,103,97,91,85,79,73,68,62,57,52,47,42,38,
//                33,29,25,22,19,15,13,10,8,6,4,3,2,1,1,1,1,1,2,3,4,6,8,10,13,15,
//                19,22,25,29,33,38,42,47,52,57,62,68,73,79,85,91,97,103,109,115,121,127,134,
//                140,146,152,158,164,170,176,182,187,193,198,203,208,213,217,222,226,230,233,
//                236,240,242,245,247,249,251,252,253,254,254,254,254,254,253,252,251,249,247,
//                245,242,240,236,233,230,226,222,217,213,208,203,198,193,187,182,176,170,164,
//                158,152,146,140,134,128,121,115,109,103,97,91,85,79,73,68,62,57,52,47,42,38,
//                33,29,25,22,19,15,13,10,8,6,4,3,2}; 

//            HistoryGraph_SetValueInt8(16,1,&sin[num],1);                                  //添加历史曲线数据         
//            num++;
//            if(num >= 255)
//            {
//                num =0;
//            }
//        } 
//        else if(curves_type == 1)
//        {          
//            //锯齿波数组
//            uint8_t code sawtooth[180] = {0,9,18,27,36,45,54,63,72,81,90,99,108,117,126,135,144,153,162,171,180,189,198,207,216,225,234,243,252,
//                0,9,18,27,36,45,54,63,72,81,90,99,108,117,126,135,144,153,162,171,180,189,198,207,216,225,234,243,252,
//                0,9,18,27,36,45,54,63,72,81,90,99,108,117,126,135,144,153,162,171,180,189,198,207,216,225,234,243,252,
//                0,9,18,27,36,45,54,63,72,81,90,99,108,117,126,135,144,153,162,171,180,189,198,207,216,225,234,243,252,
//                0,9,18,27,36,45,54,63,72,81,90,99,108,117,126,135,144,153,162,171,180,189,198,207,216,225,234,243,252,
//                0,9,18,27,36,45,54,63,72,81,90,99,108,117,126,135,144,153,162,171,180,189,198,207,216,225,234,243,252};

//            HistoryGraph_SetValueInt8(16,1,&sawtooth[num],1);                            //添加历史曲线数据        
//            num++;
//            if(num >= 90)
//            {
//                num =0;
//            }
//        } 


//    }

}


/*! 
*  \brief  按钮控件通知
*  \details  当按钮状态改变(或调用GetControlValue)时，执行此函数
*  \param screen_id 画面ID
*  \param control_id 控件ID
*  \param state 按钮状态：0弹起，1按下
*/
void NotifyButton(uint16_t screen_id, uint16_t control_id, uint8_t  state){ 
//    //选择波形
//    if(screen_id == 11)
//    {
//        if(control_id==2)                                                                //正弦波
//        {
//            curves_type = 0;                                                                
//        }
//        else if(control_id==3)                                                            //锯齿波
//        {
//            curves_type = 1;
//        }   
//    }
//    //时间画面按钮获取RTC时间
//    if(screen_id == 8)
//    {
//        if(control_id==8 && state == 1)                                                  //获取时间
//        {
//            ReadRTC();                                                              
//        }
//    }
//     //选择控件显示时间段
//     if(screen_id == 13 && control_id==4)
//     {
//         
//         if(Select_H>=0&&Select_H<=6)                                                       //0~6小时，凌晨  
//        {     
//            SetSelectorValue(13,3,0);                                                       //设置选择控件选项  
//        }                                        
//        else if(Select_H>=7&&Select_H<=12)                                                  //7~12小时，上午
//        {
//            SetSelectorValue(13,3,1);
//        }         
//        else if(Select_H>=13&&Select_H<=18)                                                 //13~18小时，下午
//        { 
//            SetSelectorValue(13,3,2);
//        }    
//        else if(Select_H>18&&Select_H<=23)                                                  //19~23小时，深夜
//        {
//            SetSelectorValue(13,3,3);
//        }    
//         Last_H   = Select_H;   
//         Last_M   = Select_M;          
//     }
//         //选择控件显示时间段
//     if(screen_id == 13 && control_id==5)
//     {
//          SetSelectorValue(13,1,Last_H);
//          SetSelectorValue(13,2,Last_M);
//     }
//     if(screen_id == 5)
//     {
//        if(control_id==3)                                                            //递减
//        {
//            Progress_Value -= 1; 
//            if(Progress_Value <= 0)
//            {
//                Progress_Value = 0;
//            }                
//            SetProgressValue(5,1,Progress_Value);                                    //设置进度条的值
//            SetTextInt32(5,2,Progress_Value,0,1);                                    //设置文本框的值
//        }
//        else if(control_id==4)                                                       //递加
//        {
//            Progress_Value += 1;
//            if(Progress_Value >= 100)
//            {
//                Progress_Value = 100;
//            }
//            SetProgressValue(5,1,Progress_Value);
//            SetTextInt32(5,2,Progress_Value,0,1);
//        }   
//    }
}

/*! 
*  \brief  文本控件通知
*  \details  当文本通过键盘更新(或调用GetControlValue)时，执行此函数
*  \details  文本控件的内容以字符串形式下发到MCU，如果文本控件内容是浮点值，
*  \details  则需要在此函数中将下发字符串重新转回浮点值。
*  \param screen_id 画面ID
*  \param control_id 控件ID
*  \param str 文本控件内容
*/
void NotifyText(uint16_t screen_id, uint16_t control_id, uint8_t *str){
//    //TODO: 添加用户
//    if(screen_id==4)                                                                 //画面ID2：文本设置和显示
//    {                                                                            
//        int32_t value=0;                                                            
//        value = str2int(str);                                                        //把字符串转换为整数 
//        if(control_id==2)                                                            //最高电压
//        {                                                                         
//            //限定数值范围（也可以在文本控件属性中设置）                             
//            if(value<0)                                                              
//            {                                                                        
//                value = 0;                                                            
//            }                                                                        
//            else if(value>380)                                                       
//            {                                                                        
//                value = 380;                                                           
//            }                                                                        
//            SetTextInt32(4,2,value,0,1);                                             //更新最高电压
//            SetTextFloat(4,5,(float)value/2,1,1);                                    //更新最高电压/2
//        }                                                                         
//    }                                                                            
}                                                                                

/*!                                                                              
*  \brief  进度条控件通知                                                       
*  \details  调用GetControlValue时，执行此函数                                  
*  \param screen_id 画面ID                                                      
*  \param control_id 控件ID                                                     
*  \param value 值                                                              
*/                                                                              
void NotifyProgress(uint16_t screen_id, uint16_t control_id, uint32_t value)           {                                                                                
//     if(screen_id == 5)
//    {
//        Progress_Value = value;                                  
//        SetTextInt32(5,2,Progress_Value,0,1);                                        //设置文本框的值     
//    }      
}                                                                                

/*!                                                                              
*  \brief  滑动条控件通知                                                       
*  \details  当滑动条改变(或调用GetControlValue)时，执行此函数                  
*  \param screen_id 画面ID                                                      
*  \param control_id 控件ID                                                     
*  \param value 值                                                              
*/                                                                              
void NotifySlider(uint16_t screen_id, uint16_t control_id, uint32_t value)             {                                                                                                                                  
//   uint8_t back[1] = {0};
//    if(screen_id==7&&control_id==2)                                                  //滑块控制
//    {            
//        if(value<100||value>0)                                                       
//        {                                                                            
//            SetProgressValue(7,1,value);                                             //更新进度条数值
//            SetTextInt32(7,3,value,0,1); 
//            sprintf(back,"%c",(255-value*2));                                        //设置背光亮度 背光值范围 0~255，0最亮，255最暗
//            SetBackLight(back[0]);
//        }
//    }
//    if(screen_id==7&&control_id==5)                                                  //滑块控制
//    {                                                                              
//        if(value<100||value>0)                                                       
//        {                                                                            
//            SetProgressValue(7,4,value);                                             //更新进度条数值
//            SetTextInt32(7,6,value,0,1);                                             
//        }
//    }
}

/*! 
*  \brief  仪表控件通知
*  \details  调用GetControlValue时，执行此函数
*  \param screen_id 画面ID
*  \param control_id 控件ID
*  \param value 值
*/
void NotifyMeter(uint16_t screen_id, uint16_t control_id, uint32_t value)
{
    //TODO: 添加用户代码
}

/*! 
*  \brief  菜单控件通知
*  \details  当菜单项按下或松开时，执行此函数
*  \param screen_id 画面ID
*  \param control_id 控件ID
*  \param item 菜单项索引
*  \param state 按钮状态：0松开，1按下
*/
void NotifyMenu(uint16_t screen_id, uint16_t control_id, uint8_t item, uint8_t state){

}

/*! 
*  \brief  选择控件通知
*  \details  当选择控件变化时，执行此函数
*  \param screen_id 画面ID
*  \param control_id 控件ID
*  \param item 当前选项
*/
void NotifySelector(uint16_t screen_id, uint16_t control_id, uint8_t  item)
{
//     if(screen_id == 13&&control_id == 1)                                //获取当前选择控件的值
//    {
//        Select_H =  item;
//    } 
//    if(screen_id == 13&&control_id == 2)                                //获取当前选择控件的值
//    {
//        Select_M =  item;
//    } 

}

/*! 
*  \brief  定时器超时通知处理
*  \param screen_id 画面ID
*  \param control_id 控件ID
*/
void NotifyTimer(uint16_t screen_id, uint16_t control_id)
{

//    if(screen_id==8&&control_id == 7)
//    {
//        SetBuzzer(100);
//    } 
}

/*! 
*  \brief  读取用户FLASH状态返回
*  \param status 0失败，1成功
*  \param _data 返回数据
*  \param length 数据长度
*/
void NotifyReadFlash(uint8_t status,uint8_t *_data,uint16_t length)
{
    //TODO: 添加用户代码
}

/*! 
*  \brief  写用户FLASH状态返回
*  \param status 0失败，1成功
*/
void NotifyWriteFlash(uint8_t status)
{
    //TODO: 添加用户代码
}

/*! 
*  \brief  读取RTC时间，注意返回的是BCD码
*  \param year 年（BCD）
*  \param month 月（BCD）
*  \param week 星期（BCD）
*  \param day 日（BCD）
*  \param hour 时（BCD）
*  \param minute 分（BCD）
*  \param second 秒（BCD）
*/
void NotifyReadRTC(uint8_t year,uint8_t month,uint8_t week,uint8_t day,uint8_t hour,uint8_t minute,uint8_t second)
{
//    int years,months,weeks,days,hours,minutes;
//       
//    sec    =(0xff & (second>>4))*10 +(0xf & second);                                    //BCD码转十进制
//    years   =(0xff & (year>>4))*10 +(0xf & year);                                      
//    months  =(0xff & (month>>4))*10 +(0xf & month);                                     
//    weeks   =(0xff & (week>>4))*10 +(0xf & week);                                      
//    days    =(0xff & (day>>4))*10 +(0xf & day);                                      
//    hours   =(0xff & (hour>>4))*10 +(0xf & hour);                                       
//    minutes =(0xff & (minute>>4))*10 +(0xf & minute);                                      
//   
//    SetTextInt32(8,1,years,1,1);
//    SetTextInt32(8,2,months,1,1);
//    SetTextInt32(8,3,days,1,1);
//    SetTextInt32(8,4,hours,1,1);
//    SetTextInt32(8,5,minutes,1,1);
//    SetTextInt32(8,6,sec,1,1);
//    if(weeks == 0)
//    {
//         SetTextValue(8,7,"星期天");
//    }
//    else if(weeks == 1)
//    {
//         SetTextValue(8,7,"星期一");
//    }
//    else if(weeks == 2)
//    {
//         SetTextValue(8,7,"星期二");
//    }
//    else if(weeks == 3)
//    {
//         SetTextValue(8,7,"星期三");
//    }
//    else if(weeks == 4)
//    {
//         SetTextValue(8,7,"星期四"); 
//    }
//    else if(weeks == 5)
//    { 
//         SetTextValue(8,7,"星期五");
//    }
//    else if(weeks == 6)
//    {
//         SetTextValue(8,7,"星期六");
//    }      
}