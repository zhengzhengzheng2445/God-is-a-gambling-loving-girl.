#include <stdio.h>
#include "test.h"
void datetrans() {
    printf("桩函数：日期转换功能被调用\n");
}

void photoView() {
    printf("桩函数：图片查看功能被调用\n");
}

void updateData() {
    printf("桩函数：数据更新功能被调用\n");
}

int defenceMistake(int checkVar, int start, int over) {
    printf("桩函数：a被调用\n");
    return 0;
}

void timeGet(int tmRecord[]) {
    printf("桩函数：b被调用\n");
}

void remind(int a[]){
    printf("桩函数：c被调用\n");
}