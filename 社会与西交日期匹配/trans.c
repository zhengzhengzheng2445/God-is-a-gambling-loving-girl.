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
    if (1 == ldate.reserved) {                                  //反正阴历就这么规定的,闰月就是闰月
        printf("阴历:闰%d月%d日\n", *lmonth,*lday);
    }
    else {
        printf("阴历:%d月%d日\n", *lmonth, *lday);
    }
    }

void solarWeek(int* week, int* wday) {
}

void lunarSolar(int* lmonth, int* lday, int year) {
    
}