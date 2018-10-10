   pc.c是移植于μCOS-II的PC服务代码（pc.c）
   主要改动：
1、#include "includes.h"改为"config.h"  
2、在屏幕上显示改为向UART0发送数据，在电脑上显示，影响的函数：
   PC_DispChar()、PC_DispClrCol()、PC_DispClrRow()、PC_DispClrScr()和PC_DispStr()
3、获取键值改为从UART0获取，影响的函数：PC_GetKey()
4、因为没有dos环境所作的修改，影响的函数：
   PC_DOSReturn()、PC_DOSSaveReturn()、PC_SetTickRate()（删除）、PC_VectGet()（删除）和
   PC_VectSet（删除）。
5、因为定时器不同所作的修改，影响的函数：
   PC_ElapsedStart()和PC_ElapsedStop()。
6、因为实时时钟不同所作的修改，影响的函数：PC_GetDateTime()。