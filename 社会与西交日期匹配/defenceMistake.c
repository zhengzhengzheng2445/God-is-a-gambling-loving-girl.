#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "defenceMistake.h"
//selectFunction = defenceMistake(selectFunction, 1, 3);
void defenceMistake(int* checkVar,int start ,int over){ //��������,��ʼ,����
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
			printf("���������������������66\nʾ��:\n6��5��\n6 5\n");
			cleanCache();
		}
		if ((*checkVar) <= over && (*checkVar) >= start) {
			break;
		}else{
			printf("���������������������\n");
		}
	}
}

void cleanCache() {
	int result = 56789;
	while (1) {
		result = getchar();
		if (10 == result) {//�س���asc,���ܲ����ܲ����س���,���ǳ�����ļ����� ��Ȼ�����ܷ���-1
			break;
		}
	}
}