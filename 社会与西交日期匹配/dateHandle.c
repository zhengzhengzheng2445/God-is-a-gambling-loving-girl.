#define _CRT_SECURE_NO_WARNINGS
#include "dateHandle.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void dateHandle(int specificmonth,int specificday, char schoolStartTime[]) {
	int dayOfXjMonth[12] = { 30,31,30,31,31,28,31,30,31,30,31,31 }, MonthlyDayInTerm[12] = { 0 };//一个是长度,一个是索引.我服了//xj每个月的天数,用static数组里未定义的值是零,否则为垃圾值,后面的数组是西交这学期每个月的天数
	char year[5], month[3], day[3];
	strncpy(year, schoolStartTime + 0, 4);
	year[4] = '\0';                                     //获取年份
	strncpy(month, schoolStartTime + 4, 2);
	month[2] = '\0';
	strncpy(day, schoolStartTime + 6, 2);              //原理见字符串
	day[2] = '\0';                                     //索引从0开始
	int yearNum, monthNum, dayNum,sum=0;
	yearNum = atoi(year), monthNum = atoi(month), dayNum = atoi(day);   //你没包含他的头文件,用crtl看不了这个函数写的啥
	for (int i = 0; i < (monthNum + 3) % 12; i++) {
		MonthlyDayInTerm[i] = 0;
	}
	MonthlyDayInTerm[(monthNum + 3) % 12] = dayOfXjMonth[(monthNum + 3) % 12] - dayNum + 1;
	for (int i = 11; i > (monthNum + 3) % 12; i--) {
		MonthlyDayInTerm[i] = dayOfXjMonth[i];
	}
	if ((yearNum % 4 == 0&& yearNum%100!=0)||(yearNum % 400 == 0)) {
		MonthlyDayInTerm[5] += 1;
	}

	for (int i = 0; i < (specificmonth + 3) % 12; i++) {
		sum += MonthlyDayInTerm[i];
	}
	sum += specificday;
	int week = 1;
	for (week = 1; 1; week++) { //for (int i = 1; 1; i++) {//c语言,函数内外变量重名的时候,内部优先,但我建议你别作,这样内部的出不来
		if (sum > 7) {
			sum -= 7;           //求这天星期几
		}
		else {
			break;
		}
	}
	printf("第%d周周%d\n", week, sum);
}
