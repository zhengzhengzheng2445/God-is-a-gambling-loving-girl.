#define _CRT_SECURE_NO_WARNINGS
#include "fileHandle.h"
#include "dateCheck.h" 
#include <stdio.h>
#include <stdlib.h>   
void fileHandle(char schoolStartTime[]) {//�ǵ�������÷�������
	char* filePath = "date.txt";//���·��
	int tem = dateCheck(), fcloseResult, fputsResult;
	if (tem == 2 || tem == 1) {
		FILE* writeFile = fopen(filePath, "w");
		if (writeFile == NULL) {
			printf("�򲻿�\n");
			exit(-1);
		}
		printf("�ø���������\n");
		fcloseResult = fclose(writeFile);
		if (fcloseResult != 0) {
			printf("��д���Ƴ����bug�ز����ļ���1\n");
			exit(-1);
		}
	}
	FILE* updateFile = fopen(filePath, "a+");//w+�򿪾������
	if (updateFile == NULL) {
		printf("�򲻿�\n");
		exit(-1);
	}
	int fileCheck = fgetc(updateFile);
	if (fileCheck == -1)//ǧ�����int��char���ַ���
	{
		char schoolStartInput[] = "20240307";//����
		printf("��������ѧ�ڿ�ѧ������\nʾ��:2024��3��7�տ�ѧ\n20240307\n");
		scanf("%s", &schoolStartInput);
		fputsResult = fputs(schoolStartInput, updateFile);
		if (fputsResult < 0) {
			printf("д���ļ�ʧ��\n");
			exit(-1);
		}
		int cc = fclose(updateFile);
		if (cc != 0) {
			printf("��д���Ƴ����bug�ز����ļ���55\n");
			exit(-1);
		}
	}
	if (fileCheck != -1) {
		fcloseResult = fclose(updateFile);
		if (fcloseResult != 0) {
			printf("��д���Ƴ����bug�ز����ļ���2\n");
			exit(-1);
		}
	}
	FILE* readFile = fopen(filePath, "r");
	if (readFile == NULL) {
		printf("�򲻿�\n");
		exit(-1);
	}
	char* fgetsResult = fgets(schoolStartTime, 1024, readFile);
	int tmp;
	tmp = atoi(schoolStartTime);
	sprintf(schoolStartTime, "%d", tmp);
	if (fgetsResult == NULL) {
		printf("��д���Ƴ����bug�������ļ���3\n");
		exit(-1);
	}
	fcloseResult = fclose(readFile);
	if (fcloseResult != 0) {
		printf("��д���Ƴ����bug�ز����ļ���4\n");
		exit(-1);
	}
}