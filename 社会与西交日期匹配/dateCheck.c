#define _CRT_SECURE_NO_WARNINGS
#include "dateCheck.h"
#include <stdio.h>
#include <time.h>
int dateCheck() {
	time_t ti;
	time(&ti);
	struct tm* datep;
	datep = gmtime(&ti);
	if (datep->tm_mon == 8 && datep->tm_mday == 24) {
		return 2;
	}
	else if (datep->tm_mon == 2 && datep->tm_mday == 3) {
		return 1;
	}
	else {
		return 3;
	}
} //日期判断,决定是否需要更新文件