#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "defenceMistake.h"
//selectFunction = defenceMistake(selectFunction, 1, 3);
void defenceMistake(int* checkVar,int start ,int over){ //待检查变量,开始,结束
	if (start > over) {
		int tem = start;
		start = over;
		over = tem;
	}
	while (1) 
	{
		while (1) {
			int result = scanf("%d", checkVar);
			if (1 == result) {
				break;
			}
			printf("数据输入错误请重新输入66\n示例:\n6月5日\n6 5\n");
			cleanCache();
		}
		if ((*checkVar) <= over && (*checkVar) >= start) {
			break;
		}else{
			printf("数据输入错误请重新输入\n");
		}
	}
}

void cleanCache() {
	int result = 56789;
	while (1) {
		result = getchar();
		if (10 == result) {//回车的asc,你总不可能不按回车吧,除非程序或文件结束 不然不可能返回-1
			break;
		}
	}
}