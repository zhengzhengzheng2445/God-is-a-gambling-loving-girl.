#include <stdio.h>
#include <time.h>
#include "trans.h"
#include "solarLunarTrans.h"

void weekSolar(int* smonth, int* sday) {
    
}

void solarLunar(int* lmonth, int* lday, int year) {
    Mydate sdate;
    sdate.month = *lmonth;
    sdate.day = *lday;
    sdate.year = year;
    Mydate ldate=toLunar(sdate);
    *lmonth = ldate.month;
    *lday = ldate.day;
    if (1 == ldate.reserved) {                                  //������������ô�涨��,���¾�������
        printf("����:��%d��%d��\n", *lmonth,*lday);
    }
    else {
        printf("����:%d��%d��\n", *lmonth, *lday);
    }
    }

void solarWeek(int* week, int* wday) {
}

void lunarSolar(int* lmonth, int* lday, int year) {
    
}