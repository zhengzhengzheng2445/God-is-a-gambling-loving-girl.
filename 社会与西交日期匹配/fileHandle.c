#define _CRT_SECURE_NO_WARNINGS
#define FILE_CHECK(ptr,tip,standard)	\
do{\
    if ((ptr) == (standard)) {\
          printf("%s\n",(tip));\
          exit(-1);\
     }\
}while(0)  /*do,whileû��ɶ������Ǹ�����,�������ֱ���滻,���Ǻ�������*/ 
/*ԭʼ�궨���е� printf("tip\n") �ᵼ��ֱ������ַ��� "tip"�����Ǵ������ʾ������
������Ϊ tip ��������˫�����У��������Ὣ����Ϊ��ͨ�ַ��������Ǻ����*/
#include "fileHandle.h"
#include "dateCheck.h" 
#include <stdio.h>
#include <stdlib.h>   
void fileHandle(char schoolStartTime[]) {//�ǵ�������÷�������
	char* filePath = "date.txt";//���·��
	int tem = dateCheck(), fcloseResult, fputsResult;
	if (tem == 2 || tem == 1) {
		FILE* writeFile = fopen(filePath, "w");
		FILE_CHECK(writeFile, "�򲻿�1",NULL);
		printf("�ø���������\n");
		fcloseResult = fclose(writeFile);
		FILE_CHECK(fcloseResult, "��д���Ƴ����bug�ز����ļ���1", 0);
	}
	FILE* updateFile = fopen(filePath, "a+");//w+�򿪾������
	FILE_CHECK(updateFile, "�򲻿�2",NULL);
	int fileCheck = fgetc(updateFile);
	if (fileCheck == -1)//ǧ�����int��char���ַ���
	{
		char schoolStartInput[] = "20240307";//����
		printf("��������ѧ�ڿ�ѧ������\nʾ��:2024��3��7�տ�ѧ\n20240307\n");
		scanf("%s", schoolStartInput);
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
	FILE_CHECK(readFile, "�򲻿�3",NULL);
	char* fgetsResult = fgets(schoolStartTime, 1024, readFile);
	int tmp;
	tmp = atoi(schoolStartTime);
	sprintf(schoolStartTime, "%d", tmp);
	FILE_CHECK(fgetsResult, "��д���Ƴ����bug�������ļ���3", NULL);
	fcloseResult = fclose(readFile);
	FILE_CHECK(fcloseResult, "��д���Ƴ����bug�ز����ļ���4", 0);
}