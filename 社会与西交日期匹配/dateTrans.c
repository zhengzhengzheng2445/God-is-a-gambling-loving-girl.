#include <stdio.h>
#include "dateTrans.h"
#include "defenceMistake.h"
#define NO 234567890
void datetrans() {
	int month = NO, day = NO;
	defenceMistake(&month, 1, 12);
	defenceMistake(&day, 1, 31);//�������Ҳ������ǵ�����2��30��,��ֹ����20240307����
}