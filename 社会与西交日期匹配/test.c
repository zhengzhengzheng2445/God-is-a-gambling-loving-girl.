#include <stdio.h>
#include "test.h"


void photoView() {
    printf("桩函数：图片查看功能被调用\n");
}

void updateData() {
    printf("桩函数：数据更新功能被调用\n");
}


void timeGet(int tmRecord[]) {
    printf("桩函数：b被调用\n");
}

void remind(int a[]){
    printf("桩函数：c被调用\n");
}