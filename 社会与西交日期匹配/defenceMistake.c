#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "defenceMistake.h"
//selectFunction = defenceMistake(selectFunction, 1, 3);
int defenceMistake(int checkVar,int start ,int over){                  //��������,��ʼ,����
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
		printf("���������������������\n");
	}
}