#define _CRT_SECURE_NO_WARNINGS
#include "dateHandle.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void dateHandle(int specificmonth,int specificday, char schoolStartTime[]) {
	int dayOfXjMonth[12] = { 30,31,30,31,31,28,31,30,31,30,31,31 }, MonthlyDayInTerm[12] = { 0 };//һ���ǳ���,һ��������.�ҷ���//xjÿ���µ�����,��static������δ�����ֵ����,����Ϊ����ֵ,�����������������ѧ��ÿ���µ�����
	char year[5], month[3], day[3];
	strncpy(year, schoolStartTime + 0, 4);
	year[4] = '\0';                                     //��ȡ���
	strncpy(month, schoolStartTime + 4, 2);
	month[2] = '\0';
	strncpy(day, schoolStartTime + 6, 2);              //ԭ����ַ���
	day[2] = '\0';                                     //������0��ʼ
	int yearNum, monthNum, dayNum,sum=0;
	yearNum = atoi(year), monthNum = atoi(month), dayNum = atoi(day);   //��û��������ͷ�ļ�,��crtl�������������д��ɶ
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
	for (week = 1; 1; week++) { //for (int i = 1; 1; i++) {//c����,�����������������ʱ��,�ڲ�����,���ҽ��������,�����ڲ��ĳ�����
		if (sum > 7) {
			sum -= 7;           //���������ڼ�
		}
		else {
			break;
		}
	}
	printf("��%d����%d\n", week, sum);
}
