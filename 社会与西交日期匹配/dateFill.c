#define _CRT_SECURE_NO_WARNINGS
#include "dateFill.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void dateFill(int ab[], char sj[]) {
	int dayOfXjMonth[12] = { 30,31,30,31,31,28,31,30,31,30,31,31 };//һ���ǳ���,һ��������.�ҷ���
	char year[5], month[3], day[3];
	strncpy(year, sj + 0, 4);
	year[4] = '\0';                                     //��ȡ���
	strncpy(month, sj + 4, 2);
	month[2] = '\0';
	strncpy(day, sj + 6, 2);                            //ԭ����ַ���
	day[2] = '\0';                                     //������0��ʼ
	int yearNum, monthNum, dayNum;
	yearNum = atoi(year), monthNum = atoi(month), dayNum = atoi(day);   //��û��������ͷ�ļ�,��crtl�������������д��ɶ
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