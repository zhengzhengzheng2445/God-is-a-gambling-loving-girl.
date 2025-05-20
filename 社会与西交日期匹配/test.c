#include <stdio.h>
#include "test.h"


void photoView() {
    printf("桩函数：图片查看功能被调用\n");
}

void updateData() {
    printf("桩函数：数据更新功能被调用\n");
}


void timeGet(int tmRecord[]) {
    printf("桩函数：timeGet被调用\n");
}

void remind(int a[]){
    printf("桩函数：remind被调用\n");
}

void weekSolar(int* smonth, int* sday) {
    printf("桩函数：weekMonth被调用\n");
}

void solarLunar(int* lmonth, int* lday) {
    printf("桩函数：solarLunar被调用\n");
}

void solarWeek(int* week, int* wday){
    printf("桩函数：solarWeek被调用\n");
}

void lunarSolar(int* lmonth, int* lday) {
    printf("桩函数：lunarSolar被调用\n");
}