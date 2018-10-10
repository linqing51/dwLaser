;/****************************************Copyright (c)**************************************************
;**                               ������������Ƭ����չ���޹�˾
;**                                     ��    ��    ��
;**                                        ��Ʒһ�� 
;**
;**                                 http://www.zlgmcu.com
;**
;**--------------�ļ���Ϣ--------------------------------------------------------------------------------
;**��   ��   ��: os_cpu_s.s
;**��   ��   ��: ������
;**����޸�����: 2003��6��19��
;**��        ��: ��COS-II��LPC210x�ϵ���ֲ��������벿�֣���ADS1.2����
;**
;**--------------��ʷ�汾��Ϣ----------------------------------------------------------------------------
;** ������: ������
;** ��  ��: V1.0
;** �ա���: 2003��6��5��
;** �衡��: ԭʼ��
;**
;**------------------------------------------------------------------------------------------------------
;** �޸���: ������
;** ��  ��: V1.1
;** �ա���: 2003��6��11��
;** �衡��: ���Vectors.s����IRQǶ�׵�BUG������Ӧ���޸�
;**
;**------------------------------------------------------------------------------------------------------
;** �޸���: ������
;** ��  ��: V1.2
;** �ա���: 2003��6��13��
;** �衡��: ���զ�COS-II V2.52��Ҫ���޸ģ���ǰ�ǻ��ڦ�COS-II V2.0��
;**
;**------------------------------------------------------------------------------------------------------
;** �޸���: ������
;** ��  ��: V1.3
;** �ա���: 2003��6��19��
;** �衡��: ����ȫ���զ�COS-II V2.52��Ҫ�������Ч��
;**
;**------------------------------------------------------------------------------------------------------
;** �޸���: ������
;** ��  ��: V1.3
;** �ա���: 2004��8��27��
;** �衡��: ���SWI�쳣��������Ч��
;**
;**--------------��ǰ�汾�޶�------------------------------------------------------------------------------
;** �޸���: 
;** �ա���:
;** �衡��:
;**
;**------------------------------------------------------------------------------------------------------
;********************************************************************************************************/

NoInt       EQU 0x80

USR32Mode   EQU 0x10
SVC32Mode   EQU 0x13
SYS32Mode   EQU 0x1f
IRQ32Mode   EQU 0x12
FIQ32Mode   EQU 0x11

;T_bit���ڼ������쳣ǰcpu�Ƿ���THUMB״̬
T_bit               EQU         0x20

    CODE32

    AREA    |subr|, CODE, READONLY

            IMPORT  OSTCBCur                    ;ָ��ǰ����TCB��ָ��
            IMPORT  OSTCBHighRdy                ;ָ��Ҫ���е�����TCB��ָ��
            IMPORT  OSPrioCur                   ;��ǰ��������ȼ�
            IMPORT  OSPrioHighRdy               ;��Ҫ���е���������ȼ�
            IMPORT  OSTaskSwHook                ;�����л��Ĺ��Ӻ���
            IMPORT  OSRunning                   ;uC/OS-II���б�־
            IMPORT  OsEnterSum                  ;���жϼ����������ж��ź�����
            IMPORT  OSIntNesting        
            IMPORT  _OSFunctionAddr
            IMPORT  _UsrFunctionAddr

            IMPORT  _TaskIsARM
            IMPORT  _TaskIsTHUMB
            
            EXPORT  __OSStartHighRdy            
            EXPORT  OSIntCtxSw                  ;�ж��˳�ʱ����ڣ��μ�startup.s�е�IRQ_Handler
            EXPORT  SoftwareInterrupt           ;���ж����


;/*********************************************************************************************************
;** ��������: SoftwareInterrupt
;** ��������: ����жϣ������ṩһЩϵͳ���񣬹��ܲο�os_cpu_c.c�ļ�
;** �䡡��:   �����ܶ���
;** �䡡�� :  �����ܶ���
;** ȫ�ֱ���: ��
;** ����ģ��: SWI_Exception
;** 
;** ������: ������
;** �ա���: 2003��6��5��
;**-------------------------------------------------------------------------------------------------------
;** �ޡ���: ������
;** �ա���: 2003��6��11��
;**-------------------------------------------------------------------------------------------------------
;** �ޡ���: ������
;** �ա���: 2003��6��13��
;**-------------------------------------------------------------------------------------------------------
;** �ޡ���: ������
;** �ա���: 2003��6��19��
;**-------------------------------------------------------------------------------------------------------
;** �ޡ���: ������
;** �ա���: 2004��8��27��
;**-------------------------------------------------------------------------------------------------------
;********************************************************************************************************/

;����ж�
SoftwareInterrupt
        CMP     R0, #12
        LDRLO   PC, [PC, R0, LSL #2]
        MOVS    PC, LR

SwiFunction
        DCD     TASK_SW                 ;0
        DCD     ENTER_CRITICAL          ;1
        DCD     EXIT_CRITICAL           ;2
        DCD     ISRBegin                ;3
        DCD     ChangeToSYSMode         ;4
        DCD     ChangeToUSRMode         ;5
        DCD     __OSStartHighRdy        ;6
        DCD     TaskIsARM               ;7
        DCD     TaskIsTHUMB             ;8
        DCD     OSISRNeedSwap           ;9
        DCD     GetOSFunctionAddr       ;10
        DCD     GetUsrFunctionAddr      ;11

TASK_SW
        MRS     R3, SPSR                        ;���������CPSR
        MOV     R2, LR                          ;���������PC
        
        MSR     CPSR_c, #(NoInt | SYS32Mode)    ;�л���ϵͳģʽ
        STMFD   SP!, {R2}                       ;����PC����ջ
        STMFD   SP!, {R0-R12, LR}               ;����R0-R12,LR����ջ
                                                ;��ΪR0~R3û�б����������ݣ����Կ���������
        B       OSIntCtxSw_0                    ;�������������л�

ENTER_CRITICAL
                                                ;OsEnterSum++
        LDR     R1, =OsEnterSum
        LDRB    R2, [R1]
        ADD     R2, R2, #1
        STRB    R2, [R1]
                                                ;���ж�
        MRS     R0, SPSR
        ORR     R0, R0, #NoInt
        MSR     SPSR_c, R0
        MOVS    PC, LR

EXIT_CRITICAL
                                                ;OsEnterSum--
        LDR     R1, =OsEnterSum
        LDRB    R2, [R1]
        SUB     R2, R2, #1
        STRB    R2, [R1]
                                                ;if(OsEnterSum == 0) ���ж�;
        CMP     R2, #0
        MRSEQ   R0, SPSR
        BICEQ   R0, R0, #NoInt
        MSREQ   SPSR_c, R0
        MOVS    PC, LR

ISRBegin
                                                ;OSIntNesting++
        LDR     R1, =OSIntNesting
        LDRB    R2, [R1]
        ADD     R2, R2, #1
        STRB    R2, [R1]
        MOVS    PC, LR

ChangeToSYSMode
                                                ;�л���ϵͳģʽ
        MRS     R0, SPSR
        BIC     R0, R0, #0x1f
        ORR     R0, R0, #SYS32Mode    
        MSR     SPSR_c, R0
        MOVS    PC, LR

ChangeToUSRMode
                                                ;�л����û�ģʽ
        MRS     R0, SPSR
        BIC     R0, R0, #0x1f
        ORR     R0, R0, #USR32Mode    
        MSR     SPSR_c, R0
        MOVS    PC, LR

;_OSStartHighRdy
;        B       __OSStartHighRdy

TaskIsARM
        MSR     CPSR_c, #(NoInt | SYS32Mode)    ; �л���ϵͳģʽ
        MOV     R0, R1
        BL      _TaskIsARM
        MSR     CPSR_c, #(NoInt | SVC32Mode)    ; �л��ع���ģʽ
        MOVS    PC, LR

TaskIsTHUMB
        MSR     CPSR_c, #(NoInt | SYS32Mode)    ; �л���ϵͳģʽ
        MOV     R0, R1
        BL      _TaskIsTHUMB
        MSR     CPSR_c, #(NoInt | SVC32Mode)    ; �л��ع���ģʽ
        MOVS    PC, LR

OSISRNeedSwap
        LDR     R1, =OSTCBHighRdy
        LDR     R2, =OSTCBCur
        CMP     R1, R2
        MOVEQ   R0, #0
        MOVNE   R0, #1
        MOVS    PC, LR

GetOSFunctionAddr
        LDR     R1, =_OSFunctionAddr
        LDR     R0, [R1,R0,LSL #2]
        MOVS    PC, LR
        
GetUsrFunctionAddr
        LDR     R1, =_UsrFunctionAddr
        LDR     R0, [R1,R0,LSL #2]
        MOVS    PC, LR



;/*********************************************************************************************************
;** ��������: OSIntCtxSw
;** ��������: �ж��˳�ʱ�����
;** �䡡��:   R3    :��ǰ�����״̬�Ĵ���CPSR����SPSR��ֵ��
;**           R4-R12:��ǰ�����R4-R11
;**           ��ǰ������ģʽ�Ķ�ջ�ṹ����ջ���򣩣�R0-R3��R12��PC����ǰ����ģ�
;** �䡡�� :  ��
;** ȫ�ֱ���: OSPrioCur,OSPrioHighRdy,OSPrioCur,OSPrioHighRdy
;** ����ģ��: ��
;** 
;** ������: ������
;** �ա���: 2003��6��5��
;**-------------------------------------------------------------------------------------------------------
;** �ޡ���: ������
;** �ա���: 2003��6��11��
;**-------------------------------------------------------------------------------------------------------
;** �ޡ���: ������
;** �ա���: 2003��6��13��
;**-------------------------------------------------------------------------------------------------------
;** �ޡ���: ������
;** �ա���: 2003��6��19��
;**-------------------------------------------------------------------------------------------------------
;********************************************************************************************************/
OSIntCtxSw
                                                    ;����Ϊ�������񻷾�
        LDR     R2, [SP, #20]                       ;��ȡPC
        LDR     R12, [SP, #16]                      ;��ȡR12
        MRS     R0, CPSR

        MSR     CPSR_c, #(NoInt | SYS32Mode)
        MOV     R1, LR
        STMFD   SP!, {R1-R2}                        ;����LR,PC
        STMFD   SP!, {R4-R12}                       ;����R4-R12

        MSR     CPSR_c, R0
        LDMFD   SP!, {R4-R7}                        ;��ȡR0-R3
        ADD     SP, SP, #8                          ;��ջR12,PC
        
        MSR     CPSR_c, #(NoInt | SYS32Mode)
        STMFD   SP!, {R4-R7}                        ;����R0-R3
        
OSIntCtxSw_0        
        LDR     R1, =OsEnterSum                     ;��ȡOsEnterSum
        LDR     R2, [R1]
        STMFD   SP!, {R2, R3}                       ;����CPSR,OsEnterSum

                                                    ;���浱ǰ�����ջָ�뵽��ǰ�����TCB
        LDR     R1, =OSTCBCur
        LDR     R1, [R1]
        STR     SP, [R1]

        BL      OSTaskSwHook                        ;���ù��Ӻ���
                                                    ;OSPrioCur <= OSPrioHighRdy
        LDR     R4, =OSPrioCur
        LDR     R5, =OSPrioHighRdy
        LDRB    R6, [R5]
        STRB    R6, [R4]
                                                    ;OSTCBCur <= OSTCBHighRdy
        LDR     R6, =OSTCBHighRdy
        LDR     R6, [R6]
        LDR     R4, =OSTCBCur
        STR     R6, [R4]
OSIntCtxSw_1
                                                    ;��ȡ�������ջָ��
        LDR     R4, [R6]
        ADD     SP, R4, #68                         ;17�Ĵ���CPSR,OsEnterSum,R0-R12,LR,SP
        LDR     LR, [SP, #-8]
        MSR     CPSR_c, #(NoInt | SVC32Mode)        ;�������ģʽ
        MOV     SP, R4                              ;���ö�ջָ��

        LDMFD   SP!, {R4, R5}                       ;CPSR,OsEnterSum
                                                    ;�ָ��������OsEnterSum
        LDR     R3, =OsEnterSum
        STR     R4, [R3]
    
        MSR     SPSR_cxsf, R5                       ;�ָ�CPSR
        LDMFD   SP!, {R0-R12, LR, PC }^             ;����������

;/*********************************************************************************************************
;** ��������: __OSStartHighRdy
;** ��������: uC/OS-II����ʱʹ��OSStartHighRdy���е�һ������,
;**           OSStartHighRdy�����__OSStartHighRdy
;** �䡡��:   ��
;** �䡡�� :  ��
;** ȫ�ֱ���: OSRunning,OSTCBCur,OSTCBHighRdy,OsEnterSum
;** ����ģ��: OSTaskSwHook
;** 
;** ������: ������
;** �ա���: 2003��6��5��
;**-------------------------------------------------------------------------------------------------------
;** �ޡ���: ������
;** �ա���: 2003��6��13��
;**-------------------------------------------------------------------------------------------------------
;********************************************************************************************************/

__OSStartHighRdy
        MSR     CPSR_c, #(NoInt | SYS32Mode)
                                                ;����uC/OS-II�����Ѿ�����
        LDR     R4, =OSRunning
        MOV     R5, #1
        STRB    R5, [R4]

        BL      OSTaskSwHook                    ;���ù��Ӻ���

        LDR     R6, =OSTCBHighRdy
        LDR     R6, [R6]
        B       OSIntCtxSw_1

    END
;/*********************************************************************************************************
;**                            End Of File
;********************************************************************************************************/
