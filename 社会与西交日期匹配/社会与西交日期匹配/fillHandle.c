#define _CRT_SECURE_NO_WARNINGS
#include "fillHandle.h"
#include "dateCheck.h" 
#include <stdio.h>
#include <stdlib.h>   
void fillHandle(char sj[]) {//�ǵ�������÷�������
	char* wj = "date.txt";//���·��
	int bb = dateCheck();
	if (bb == 2 || bb == 1) {
		FILE* b = fopen(wj, "w");
		if (b == NULL) {
			printf("�򲻿�\n");
			exit(-1);
		}
		printf("�ø���������\n");
		int ccc = fclose(b);
		if (ccc != 0) {
			printf("��д���Ƴ����bug�ز����ļ���1\n");
			exit(-1);
		}
	}
	FILE* n = fopen(wj, "a+");//w+�򿪾������
	if (n == NULL) {
		printf("�򲻿�\n");
		exit(-1);
	}
	int e = fgetc(n);
	if (e == -1)//ǧ�����int��char���ַ���
	{
		char c[] = "20240307";//����
		printf("��������ѧ�ڿ�ѧ������\nʾ��:2024��3��7�տ�ѧ\n20240307\n");
		scanf("%s", &c);
		int nn = fputs(c, n);
		if (nn < 0) {
			printf("д���ļ�ʧ��\n");
			exit(-1);
		}
		int cc = fclose(n);
		if (cc != 0) {
			printf("��д���Ƴ����bug�ز����ļ���55\n");
			exit(-1);
		}
	}
	if (e != -1) {
		int cc = fclose(n);
		if (cc != 0) {
			printf("��д���Ƴ����bug�ز����ļ���2\n");
			exit(-1);
		}
	}
	FILE* tt = fopen(wj, "r");
	if (tt == NULL) {
		printf("�򲻿�\n");
		exit(-1);
	}
	char* nt = fgets(sj, 1024, tt);
	int tmp;
	tmp = atoi(sj);
	sprintf(sj, "%d", tmp);
	if (nt == NULL) {
		printf("��д���Ƴ����bug�������ļ���3\n");
		exit(-1);
	}
	int hhh = fclose(tt);
	if (hhh != 0) {
		printf("��д���Ƴ����bug�ز����ļ���4\n");
		exit(-1);
	}
}