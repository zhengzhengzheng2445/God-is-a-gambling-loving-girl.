#define _CRT_SECURE_NO_WARNINGS
#include "dateCheck.h"
#include <stdio.h>
#include <time.h>
int dateCheck() {
	time_t ti;
	time(&ti);
	struct tm* datep;
	datep = localtime(&ti);//���1900,�¼�1
	//printf("%d %d %d", datep->tm_year+1900, datep->tm_mon+1,datep->tm_mday);
	if ((datep->tm_mon + 1) == 8 && datep->tm_mday == 24) {
		return 2;
	}
	else if ((datep->tm_mon + 1) == 2 && datep->tm_mday == 3) {
		return 1;
	}
	else {
		return 3;
	}
} //�����ж�,�����Ƿ���Ҫ�����ļ�