#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "defenceMistake.h"
//selectFunction = defenceMistake(selectFunction, 1, 3);
int defenceMistake(int checkVar,int start ,int over){                  //待检查变量,开始,结束
	if (start > over) {
		int tem = start;
		start = over;
		over = tem;
	}
	while (1) 
	{
		scanf("%d", &checkVar);
		if (checkVar<=over&& checkVar>=start) {
			return checkVar;
		}
		printf("数据输入错误请重新输入\n");
	}
}