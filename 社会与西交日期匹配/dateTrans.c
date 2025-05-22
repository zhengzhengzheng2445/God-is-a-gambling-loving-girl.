#include <stdio.h>
#include <stdlib.h>//exit
#include <time.h>
#include "dateTrans.h"
#include "defenceMistake.h"
#include "test.h"
#include "trans.h"
#define NO 234567890
void datetrans() {
	time_t now;
	struct tm* p;
	time(&now);
	p = localtime(&now);
	int year = 1900 + p->tm_year;
	while(1)
	{
		printf("��ѡ����������:\n1.У��\n2.����\n3.����\n0.�˳�����\n4.����������\n");
		int choice = NO;
		defenceMistake(&choice, 0, 4);//������Ҫ��Ҫ���������Ķ�����д
		if (0 == choice) {
			exit(0);
		}
		else if (1 == choice) {
			int week = NO, wday = NO;
			defenceMistake(&week, 1, 24);
			defenceMistake(&wday, 1, 7);
			int smonth = week, sday = wday;
			weekSolar(&smonth,&sday);
			solarLunar(&smonth, &sday,year);
		}
		else if (2 == choice) {
			int smonth = NO, sday = NO;
			defenceMistake(&smonth, 1, 12);
			defenceMistake(&sday, 1, 31);
			int week = smonth, wday = sday;
			solarWeek(&week, &wday);
			solarLunar(&smonth, &sday,year);
		}
		else if (3 == choice) {
			int lmonth = NO, lday = NO;
			defenceMistake(&lmonth, 1, 12);
			defenceMistake(&lday, 1, 31);
			int smonth = lmonth, sday = lday;
		    lunarSolar(&lmonth, &lday,year);
			solarWeek(&lmonth, &lday);
		}
		else if (4 == choice) {
			break;
		}
	}
}