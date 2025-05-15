#define _CRT_SECURE_NO_WARNINGS
#include "fileHandle.h"
#include "dateCheck.h" 
#include <stdio.h>
#include <stdlib.h>   
void fileHandle(char schoolStartTime[]) {//记得最后必须得返回数字
	char* filePath = "date.txt";//相对路径
	int tem = dateCheck(), fcloseResult, fputsResult;
	if (tem == 2 || tem == 1) {
		FILE* writeFile = fopen(filePath, "w");
		if (writeFile == NULL) {
			printf("打不开\n");
			exit(-1);
		}
		printf("该更新日期了\n");
		fcloseResult = fclose(writeFile);
		if (fcloseResult != 0) {
			printf("你写的破程序出bug关不了文件了1\n");
			exit(-1);
		}
	}
	FILE* updateFile = fopen(filePath, "a+");//w+打开就清空了
	if (updateFile == NULL) {
		printf("打不开\n");
		exit(-1);
	}
	int fileCheck = fgetc(updateFile);
	if (fileCheck == -1)//千万分清int和char和字符串
	{
		char schoolStartInput[] = "20240307";//可以
		printf("请输入这学期开学年月日\n示例:2024年3月7日开学\n20240307\n");
		scanf("%s", &schoolStartInput);
		fputsResult = fputs(schoolStartInput, updateFile);
		if (fputsResult < 0) {
			printf("写入文件失败\n");
			exit(-1);
		}
		int cc = fclose(updateFile);
		if (cc != 0) {
			printf("你写的破程序出bug关不了文件了55\n");
			exit(-1);
		}
	}
	if (fileCheck != -1) {
		fcloseResult = fclose(updateFile);
		if (fcloseResult != 0) {
			printf("你写的破程序出bug关不了文件了2\n");
			exit(-1);
		}
	}
	FILE* readFile = fopen(filePath, "r");
	if (readFile == NULL) {
		printf("打不开\n");
		exit(-1);
	}
	char* fgetsResult = fgets(schoolStartTime, 1024, readFile);
	int tmp;
	tmp = atoi(schoolStartTime);
	sprintf(schoolStartTime, "%d", tmp);
	if (fgetsResult == NULL) {
		printf("你写的破程序出bug读不了文件了3\n");
		exit(-1);
	}
	fcloseResult = fclose(readFile);
	if (fcloseResult != 0) {
		printf("你写的破程序出bug关不了文件了4\n");
		exit(-1);
	}
}