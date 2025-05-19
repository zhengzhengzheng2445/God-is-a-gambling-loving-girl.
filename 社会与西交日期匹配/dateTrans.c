#include <stdio.h>
#include "dateTrans.h"
#include "defenceMistake.h"
#define NO 234567890
void datetrans() {
	int month = NO, day = NO;
	defenceMistake(&month, 1, 12);
	defenceMistake(&day, 1, 31);//我相信我不会弱智到输入2月30的,防止输入20240307这种
}