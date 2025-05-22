//你能写中文注释吗,选项卡是tab,退出esc
#include <stdio.h>           //头文件包含的库主文件没必要写了
#include <stdlib.h>
#include "dateCheck.h"          //日期判断,决定是否需要更新文件
#include "dateFill.h"           //填充日期数组
#include "fileHandle.h"
#include "defenceMistake.h"
int main() {
	int dayOfMonth[12] = { 0, 12, 31, 30, 31, 30, 31,0,0,0,0,0 };//xj每个月的天数,用static数组里未定义的值是零,否则为垃圾值
	int month=0, day=0, sum;
	char schoolStartTime[1024];
	fileHandle(schoolStartTime);
	printf("隐藏功能:\n0 2打开校历\n0 1更新开学日期\n\n");
	while(1)
	{
		sum = 0;//month,day,week,现在是星期几,总共多少天
		printf("请输入日期(月 日,输入0 0退出程序):\n");
		dateFill(dayOfMonth, schoolStartTime);
		defenceMistake(&month, 0, 12);
		defenceMistake(&day, 0, 31);
		if (month == 0 && day == 0) {
			return 0;
		}
		else if (month == 0 && day == 1) {
			char filepath[] = "date.txt";
			FILE* tofile = fopen(filepath, "w");
			if (NULL == tofile) {
				printf("日期更新出错\n");
				return 0;
			}
			int cresult=fclose(tofile);
			if (0 != cresult) {
				printf("更新关闭出错\n");
				return 0;
			}
		}
		else if (month == 0 && day == 2) {
			system("schoolcalendar.jpg");
		}
		else{
			for (int i = 0; i < (month + 3) % 12; i++) {
				sum += dayOfMonth[i];
			}
			sum += day;
			int week = 1;
			for (week = 1; 1; week++) { //for (int i = 1; 1; i++) {//c语言,函数内外变量重名的时候,内部优先,但我建议你别作,这样内部的出不来
				if (sum > 7) {
					sum -= 7;           //求这天星期几
				}
				else {
					break;
				}
			}
			printf("第%d周周%d\n", week, sum);
		}
	}
}