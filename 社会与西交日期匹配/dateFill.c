#define _CRT_SECURE_NO_WARNINGS
#include "dateFill.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void dateFill(int ab[], char sj[]) {
	int dayOfXjMonth[12] = { 30,31,30,31,31,28,31,30,31,30,31,31 };//一个是长度,一个是索引.我服了
	char year[5], month[3], day[3];
	strncpy(year, sj + 0, 4);
	year[4] = '\0';                                     //获取年份
	strncpy(month, sj + 4, 2);
	month[2] = '\0';
	strncpy(day, sj + 6, 2);                            //原理见字符串
	day[2] = '\0';                                     //索引从0开始
	int yearNum, monthNum, dayNum;
	yearNum = atoi(year), monthNum = atoi(month), dayNum = atoi(day);   //你没包含他的头文件,用crtl看不了这个函数写的啥
	for (int i = 0; i < (monthNum + 3) % 12; i++) {
		ab[i] = 0;
	}
	ab[(monthNum + 3) % 12] = dayOfXjMonth[(monthNum + 3) % 12] - dayNum + 1;
	for (int i = 11; i > (monthNum + 3) % 12; i--) {
		ab[i] = dayOfXjMonth[i];
	}
	if (yearNum % 4 == 0) {
		ab[5] += 1;
	}
}