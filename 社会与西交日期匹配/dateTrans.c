#include <stdio.h>
#include <stdlib.h>//exit
#include "dateTrans.h"
#include "defenceMistake.h"
#include "test.h"
#define NO 234567890
void datetrans() {
	while(1)
	{
		printf("请选择输入类型:\n1.校历\n2.阳历\n3.阴历\n0.退出程序\n4.返回主程序\n");
		int choice = NO;
		defenceMistake(&choice, 0, 4);//哥们你要不要看看函数的定义在写
		if (0 == choice) {
			exit(0);
		}
		else if (1 == choice) {
			int week = NO, wday = NO;
			defenceMistake(&week, 1, 24);
			defenceMistake(&wday, 1, 7);
			int smonth = week, sday = wday;
			weekSolar(&smonth,&sday);
			solarLunar(&smonth, &sday);
		}
		else if (2 == choice) {
			int smonth = NO, sday = NO;
			defenceMistake(&smonth, 1, 12);
			defenceMistake(&sday, 1, 31);
			int week = smonth, wday = sday;
			solarWeek(&week, &wday);
			solarLunar(&smonth, &sday);
		}
		else if (3 == choice) {
			int lmonth = NO, lday = NO;
			defenceMistake(&lmonth, 1, 12);
			defenceMistake(&lday, 1, 31);
			int smonth = lmonth, sday = lday;
		    lunarSolar(&lmonth, &lday);
			solarWeek(&lmonth, &lday);
		}
		else if (4 == choice) {
			break;
		}
	}
}