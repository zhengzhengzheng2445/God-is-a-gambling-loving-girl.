#include "randNum.h"
#include <stdio.h>
#include <stdlib.h>
void shuffle(int s, int o, int l) {
	int* result = malloc((o - s + 1) * sizeof(int));
	if (result == NULL) {
		printf("�ڴ�����ʧ��\n");
		exit(-1);//��ʾ������˳�
	}
	for (int i = 0; i < o - s + 1; i++) {
		result[i] = s + i;
	}
	for (int i = 0; i < l; i++) {
		int random = rand() % (o - s + 1 - i), temp = 0;
		temp = result[o - s - i];
		result[o - s - i] = result[random];
		printf("%d\t", result[o - s - i]);
		result[random] = temp;
	}
	printf("\n\n\n");
	free(result);
	result = NULL;
}//ϴ��