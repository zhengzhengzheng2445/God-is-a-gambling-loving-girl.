#define _CRT_SECURE_NO_WARNINGS
#include "fillHandle.h"
#include "dateCheck.h" 
#include <stdio.h>
#include <stdlib.h>   
void fillHandle(char sj[]) {//记得最后必须得返回数字
	char* wj = "date.txt";//相对路径
	int bb = dateCheck();
	if (bb == 2 || bb == 1) {
		FILE* b = fopen(wj, "w");
		if (b == NULL) {
			printf("打不开\n");
			exit(-1);
		}
		printf("该更新日期了\n");
		int ccc = fclose(b);
		if (ccc != 0) {
			printf("你写的破程序出bug关不了文件了1\n");
			exit(-1);
		}
	}
	FILE* n = fopen(wj, "a+");//w+打开就清空了
	if (n == NULL) {
		printf("打不开\n");
		exit(-1);
	}
	int e = fgetc(n);
	if (e == -1)//千万分清int和char和字符串
	{
		char c[] = "20240307";//可以
		printf("请输入这学期开学年月日\n示例:2024年3月7日开学\n20240307\n");
		scanf("%s", &c);
		int nn = fputs(c, n);
		if (nn < 0) {
			printf("写入文件失败\n");
			exit(-1);
		}
		int cc = fclose(n);
		if (cc != 0) {
			printf("你写的破程序出bug关不了文件了55\n");
			exit(-1);
		}
	}
	if (e != -1) {
		int cc = fclose(n);
		if (cc != 0) {
			printf("你写的破程序出bug关不了文件了2\n");
			exit(-1);
		}
	}
	FILE* tt = fopen(wj, "r");
	if (tt == NULL) {
		printf("打不开\n");
		exit(-1);
	}
	char* nt = fgets(sj, 1024, tt);
	int tmp;
	tmp = atoi(sj);
	sprintf(sj, "%d", tmp);
	if (nt == NULL) {
		printf("你写的破程序出bug读不了文件了3\n");
		exit(-1);
	}
	int hhh = fclose(tt);
	if (hhh != 0) {
		printf("你写的破程序出bug关不了文件了4\n");
		exit(-1);
	}
}