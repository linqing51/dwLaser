#include "firmwareUpdata.h"
/*****************************************************************************/

/*****************************************************************************/
typedef struct firmwareInfo_t{
	uint16_t fw_ver;//�̼��汾
	uint16_t hw_ver;//Ӳ���汾
	uint16_t fw_crc;//�̼�CRCУ����
	uint32_t fw_size;//�̼�����
	uint8_t  fw_type;//�̼����� 
};


void	host( ) {
	UINT8	i, s;
	UINT8	TotalCount;
	UINT16	RealCount;
	P_FAT_DIR_INFO	pDir;

	s = mInitCH376Host( );  /* ��ʼ��CH376 */
	mStopIfError( s );
/* ������·��ʼ�� */

	while ( 1 ) {
		printf( "Wait Udisk/SD\n" );
		while ( CH376DiskConnect( ) != USB_INT_SUCCESS ) {  /* ���U���Ƿ�����,�ȴ�U�̲���,����SD��,�����ɵ�Ƭ��ֱ�Ӳ�ѯSD�����Ĳ��״̬���� */
			if ( IsKeyPress( ) ) {  /* �м����� */
				printf( "Exit USB host mode\n" );
				return;
			}
			mDelaymS( 100 );  /* û��ҪƵ����ѯ */
		}
		LED_UDISK_IN( );  /* LED�� */
		mDelaymS( 200 );  /* ��ʱ,��ѡ����,�е�USB�洢����Ҫ��ʮ�������ʱ */

/* ���ڼ�⵽USB�豸��,���ȴ�100*50mS,��Ҫ�����ЩMP3̫��,���ڼ�⵽USB�豸��������DISK_MOUNTED��,���ȴ�5*50mS,��Ҫ���DiskReady������ */
		for ( i = 0; i < 100; i ++ ) {  /* ��ȴ�ʱ��,100*50mS */
			mDelaymS( 50 );
			printf( "Ready ?\n" );
			s = CH376DiskMount( );  /* ��ʼ�����̲����Դ����Ƿ���� */
			if ( s == USB_INT_SUCCESS ) break;  /* ׼���� */
			else if ( s == ERR_DISK_DISCON ) break;  /* ��⵽�Ͽ�,���¼�Ⲣ��ʱ */
			if ( CH376GetDiskStatus( ) >= DEF_DISK_MOUNTED && i >= 5 ) break;  /* �е�U�����Ƿ���δ׼����,�������Ժ���,ֻҪ�佨������MOUNTED�ҳ���5*50mS */
		}
		if ( s == ERR_DISK_DISCON ) {  /* ��⵽�Ͽ�,���¼�Ⲣ��ʱ */
			printf( "Device gone\n" );
			continue;
		}
		if ( CH376GetDiskStatus( ) < DEF_DISK_MOUNTED ) {  /* δ֪USB�豸,����USB���̡���ӡ���� */
			printf( "Unknown device\n" );
			goto UnknownUsbDevice;
		}
		i = CH376ReadBlock( buf );  /* �����Ҫ,���Զ�ȡ���ݿ�CH376_CMD_DATA.DiskMountInq,���س��� */
		if ( i == sizeof( INQUIRY_DATA ) ) {  /* U�̵ĳ��̺Ͳ�Ʒ��Ϣ */
			buf[ i ] = 0;
			printf( "UdiskInfo: %s\n", ((P_INQUIRY_DATA)buf) -> VendorIdStr );
		}

/* ��ȡԭ�ļ� */
		printf( "Open\n" );
		strcpy( buf, "\\C51\\CH376HFT.C" );  /* Դ�ļ���,�༶Ŀ¼�µ��ļ�����·�������븴�Ƶ�RAM���ٴ���,����Ŀ¼���ߵ�ǰĿ¼�µ��ļ���������RAM����ROM�� */
		s = CH376FileOpenPath( buf );  /* ���ļ�,���ļ���C51��Ŀ¼�� */
		if ( s == ERR_MISS_DIR || s == ERR_MISS_FILE ) {  /* û���ҵ�Ŀ¼����û���ҵ��ļ� */
/* �г��ļ�,����ö�ٿ��Բο�EXAM13ȫ��ö�� */
			if ( s == ERR_MISS_DIR ) strcpy( buf, "\\*" );  /* C51��Ŀ¼���������г���Ŀ¼�µ��ļ� */
			else strcpy( buf, "\\C51\\CH376*" );  /* CH376HFT.C�ļ����������г�\C51��Ŀ¼�µ���CH376��ͷ���ļ� */
			printf( "List file %s\n", buf );
			s = CH376FileOpenPath( buf );  /* ö�ٶ༶Ŀ¼�µ��ļ�����Ŀ¼,���뻺����������RAM�� */
			while ( s == USB_INT_DISK_READ ) {  /* ö�ٵ�ƥ����ļ� */
				CH376ReadBlock( buf );  /* ��ȡö�ٵ����ļ���FAT_DIR_INFO�ṹ,���س�������sizeof( FAT_DIR_INFO ) */
				pDir = (P_FAT_DIR_INFO)buf;  /* ��ǰ�ļ�Ŀ¼��Ϣ */
				if ( pDir -> DIR_Name[0] != '.' ) {  /* ���Ǳ��������ϼ�Ŀ¼�������,������붪�������� */
					if ( pDir -> DIR_Name[0] == 0x05 ) pDir -> DIR_Name[0] = 0xE5;  /* �����ַ��滻 */
					pDir -> DIR_Attr = 0;  /* ǿ���ļ����ַ��������Ա��ӡ��� */
					printf( "*** EnumName: %s\n", pDir -> DIR_Name );  /* ��ӡ����,ԭʼ8+3��ʽ,δ����ɺ�С����ָ��� */
				}
				xWriteCH376Cmd( CMD0H_FILE_ENUM_GO );  /* ����ö���ļ���Ŀ¼ */
				xEndCH376Cmd( );
				s = Wait376Interrupt( );
			}
			if ( s != ERR_MISS_FILE ) mStopIfError( s );  /* �������� */
		}
		else {  /* �ҵ��ļ����߳��� */
			mStopIfError( s );
			TotalCount = 200;  /* ׼����ȡ�ܳ��� */
			printf( "���ļ��ж�����ǰ%d���ַ���:\n",(UINT16)TotalCount );
			while ( TotalCount ) {  /* ����ļ��Ƚϴ�,һ�ζ�����,�����ٵ���CH376ByteRead������ȡ,�ļ�ָ���Զ�����ƶ� */
				if ( TotalCount > sizeof(buf) ) i = sizeof(buf);  /* ʣ�����ݽ϶�,���Ƶ��ζ�д�ĳ��Ȳ��ܳ�����������С */
				else i = TotalCount;  /* ���ʣ����ֽ��� */
				s = CH376ByteRead( buf, i, &RealCount );  /* ���ֽ�Ϊ��λ��ȡ���ݿ�,���ζ�д�ĳ��Ȳ��ܳ�����������С,�ڶ��ε���ʱ���Ÿղŵ����� */
				mStopIfError( s );
				TotalCount -= (UINT8)RealCount;  /* ����,��ȥ��ǰʵ���Ѿ��������ַ��� */
				for ( s=0; s!=RealCount; s++ ) printf( "%C", buf[s] );  /* ��ʾ�������ַ� */
				if ( RealCount < i ) {  /* ʵ�ʶ������ַ�������Ҫ��������ַ���,˵���Ѿ����ļ��Ľ�β */
					printf( "\n" );
					printf( "�ļ��Ѿ�����\n" );
					break;
				}
			}
			printf( "Close\n" );
			s = CH376FileClose( FALSE );  /* �ر��ļ� */
			mStopIfError( s );
		}

UnknownUsbDevice:
		printf( "Take out\n" );
		while ( CH376DiskConnect( ) == USB_INT_SUCCESS ) {  /* ���U���Ƿ�����,�ȴ�U�̰γ� */
			mDelaymS( 100 );
		}
		LED_UDISK_OUT( );  /* LED�� */
		mDelaymS( 100 );
	}
}
