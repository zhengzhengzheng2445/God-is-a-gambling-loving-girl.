#define _CRT_SECURE_NO_WARNINGS
#include "fileHandle.h"
#include "dateCheck.h" 
#include "defenceMistake.h"
#include <stdio.h>
#include <stdlib.h>   

void fileHandle(char schoolStartTime[]) {//�ǵ�������÷�������
	char* filePath = "date.txt";//���·��
	int tem = dateCheck(), fcloseResult, fputsResult;//���������,ͳһ���������������ձ���
	if (tem == 2 || tem == 1) {
		FILE* writeFile = fopen(filePath, "w");
		FILE_CHECK(writeFile==NULL, "�򲻿�1");
		printf("�ø���������\n");
		fcloseResult = fclose(writeFile);
		FILE_CHECK(fcloseResult!=0, "��д���Ƴ����bug�ز����ļ���1");
	}

	FILE* updateFile = fopen(filePath, "a+");//w+�򿪾������
	FILE_CHECK(updateFile==NULL, "�򲻿�2");

	int fileCheck = fgetc(updateFile);
	if (fileCheck == -1)//ǧ�����int��char���ַ���
	{
		char schoolStartInput[] = "20240307";//����
		printf("��������ѧ�ڿ�ѧ������\nʾ��:2024��3��7�տ�ѧ\n20240307\n");
		scanf("%8s", schoolStartInput);//�û�����8�ַ� �� �Զ�׷��\0����ռ9�ֽڣ���ȫ���û����� > 8�ַ� �� �Զ��ض�ǰ8�ַ�����ȫ��
		fputsResult = fputs(schoolStartInput, updateFile);
		FILE_CHECK(fputsResult < 0, "д���ļ�ʧ��");
	}

	rewind(updateFile);
	int fres=fflush(updateFile);
	FILE_CHECK(fres != 0, "ˢ��ʧ��");

	char* fgetsResult = fgets(schoolStartTime, 1024, updateFile);
	int tmp;
	tmp = atoi(schoolStartTime);
	sprintf(schoolStartTime, "%d", tmp);
	FILE_CHECK(fgetsResult==NULL, "��д���Ƴ����bug�������ļ���3");
	fcloseResult = fclose(updateFile);
	FILE_CHECK(fcloseResult!=0, "��д���Ƴ����bug�ز����ļ���4");
}