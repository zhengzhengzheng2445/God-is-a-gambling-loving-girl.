#define _CRT_SECURE_NO_WARNINGS
#define FILE_CHECK(ptr,tip)	\
do{\
    if (ptr) {\
          printf("%s\n",(tip));\
          exit(-1);\
     }\
}while(0)  /*do,while没有啥含义就是个夹子,另外宏是直接替换,不是函数传参*/ 
/*原始宏定义中的 printf("tip\n") 会导致直接输出字符串 "tip"，而非传入的提示参数。
这是因为 tip 被包裹在双引号中，编译器会将其视为普通字符串，而非宏参数*/
#include "fileHandle.h"
#include "dateCheck.h" 
#include <stdio.h>
#include <stdlib.h>   

void fileHandle(char schoolStartTime[]) {//记得最后必须得返回数字
	char* filePath = "date.txt";//相对路径
	int tem = dateCheck(), fcloseResult, fputsResult;//这里很巧妙,统一在最上面命名接收变量
	if (tem == 2 || tem == 1) {
		FILE* writeFile = fopen(filePath, "w");
		FILE_CHECK(writeFile==NULL, "打不开1");
		printf("该更新日期了\n");
		fcloseResult = fclose(writeFile);
		FILE_CHECK(fcloseResult!=0, "你写的破程序出bug关不了文件了1");
	}

	FILE* updateFile = fopen(filePath, "a+");//w+打开就清空了
	FILE_CHECK(updateFile==NULL, "打不开2");

	int fileCheck = fgetc(updateFile);
	if (fileCheck == -1)//千万分清int和char和字符串
	{
		char schoolStartInput[] = "20240307";//可以
		printf("请输入这学期开学年月日\n示例:2024年3月7日开学\n20240307\n");
		scanf("%8s", schoolStartInput);//用户输入8字符 → 自动追加\0（共占9字节，安全）用户输入 > 8字符 → 自动截断前8字符（安全）
		fputsResult = fputs(schoolStartInput, updateFile);
		FILE_CHECK(fputsResult < 0, "写入文件失败");
	}

	rewind(updateFile);
	int fres=fflush(updateFile);
	FILE_CHECK(fres != 0, "刷新失败");

	char* fgetsResult = fgets(schoolStartTime, 1024, updateFile);
	int tmp;
	tmp = atoi(schoolStartTime);
	sprintf(schoolStartTime, "%d", tmp);
	FILE_CHECK(fgetsResult==NULL, "你写的破程序出bug读不了文件了3");
	fcloseResult = fclose(updateFile);
	FILE_CHECK(fcloseResult!=0, "你写的破程序出bug关不了文件了4");
}