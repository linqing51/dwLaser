#include "sPlcFunMLC.h"
/*****************************************************************************/
//���ָ��
//void XTAB(int16_t *distY, int16_t *srcX, int16_t *index, int16_t *length) reentrant{//���Բ���X����Yֵ
//	xdata fp32_t x0, x1, y0, y1, k, b, x, y;
//	xdata uint16_t i;
//	for(i = 0;i < *length;i ++){
//		if(*(index + i) >= *srcX){
//			break;
//		}
//	}
//	if(i == 0){
//		*distY = *(index + *length);//��ʼλ��
//	}
//	else if(i >= *length){//����Ϊֹ
//		*distY = *(index + *length + *length);
//	}
//	else{//�м�岹λ��
//		x0 = (fp32_t)*(index + i);
//		x1 = (fp32_t)*(index + i + 1);
//		y0 = (fp32_t)*(index + i + *length);
//		y1 = (fp32_t)*(index + i + 1 + *length);
//		//���ֱ�߷���
//		k = (y1 - y0) / (x1 - x0);
//		b = y0 - k * x0;
//		x = (fp32_t)(*srcX);
//		y = k * x + b;
//		*distY = (int16_t)y;
//	}
//}
//void YTAB(int16_t *distX, int16_t *srcY, int16_t *index, int16_t *length) reentrant{//���Բ���Y����Xֵ
//	xdata int16_t x0, x1, y0, y1;
//	xdata uint16_t i;
//	fp32_t k, b, x, y;
//	for(i = 0;i < *length;i ++){
//		if(*(index + *length + i) >= *srcY){
//			break;
//		}
//	}
//	if(i == 0){
//		*distX = *index;//��ʼλ��
//	}
//	else if(i >= *length){//����Ϊֹ
//		*distX = *(index + *length);
//	}
//	else{//�м�岹λ��
//		x0 = *(index + i);
//		x1 = *(index + i + 1);
//		y0 = *(index + i + *length);
//		y1 = *(index + i + 1 + *length);
//		//���ֱ�߷���
//		k = ((fp32_t)y1 - (fp32_t)y0) / ((fp32_t)x1 - (fp32_t)x0);
//		b = y0 - k * x0;
//		y = (fp32_t)(*srcY);
//		x = (y - b) / k;
//		*distX = (int16_t)x;
//	}
//}

