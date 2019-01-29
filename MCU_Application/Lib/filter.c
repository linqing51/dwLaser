#include "filter.h"
/*****************************************************************************/
void firFilterInit(firFilter_t *st){//FIRÂË²¨Æ÷³õÊ¼»¯
	st->_x[0]=0;
	st->_x[1]=0;
	st->_x[2]=0;
}
int16_t firFilterRun(firFilter_t *st, int16_t dat){//FIRÂË²¨Æ÷ÔËÐÐ
	int32_t tmp;
	st->_x[0] = st->_x[1];
	tmp = ((((dat * 3269048L) >>  2) + ((st->_x[0] * 3701023L) >> 3))+1048576) >> 21;
	st->_x[1]= (int32_t)tmp;
	return (int16_t)(st->_x[0] + st->_x[1]);
}
