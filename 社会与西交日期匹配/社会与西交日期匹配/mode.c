//你能写中文注释吗,选项卡是tab,退出esc
#include <stdio.h>           //头文件包含的库主文件没必要写了
#include <stdlib.h>
#include "dateCheck.h"          //日期判断,决定是否需要更新文件
#include "dateHandle.h"           //填充日期数组
#include "fileHandle.h"
#include "defenceMistake.h"
int main() {
	int month = 0, day = 0;
	char schoolStartTime[1024];
	printf("隐藏功能:\n0 1更新开学日期\n0 2打开校历\n\n");
	while (1)
	{
		fileHandle(schoolStartTime);//month,day,week,现在是星期几,总共多少天
		printf("请输入日期(月 日,输入0 0退出程序):\n");
		defenceMistake(&month, 0, 12);
		defenceMistake(&day, 0, 31);
		if (month == 0 && day == 0) {
			return 0;
		}
		else if (month == 0 && day == 1) {
			char filepath[] = "date.txt";
			FILE* tofile = fopen(filepath, "w");
			FILE_CHECK(NULL == tofile, "日期更新出错");
			int cresult = fclose(tofile);
			FILE_CHECK(0 != cresult, "更新关闭出错");
		}
		else if (month == 0 && day == 2) {
			system("schoolcalendar.jpg");
		}
		else {
			dateHandle(month, day, schoolStartTime);
		}
	}
}