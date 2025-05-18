//#define _CRT_SECURE_NO_WARNINGS//你能写中文注释吗,选项卡是tab,退出esc
//#include <stdio.h>           //头文件包含的库主文件没必要写了
//#include "dateCheck.h"          //日期判断,决定是否需要更新文件
//#include "dateFill.h"           //填充日期数组
//#include "fileHandle.h"
//int main() {
//	int dayOfMonth[12] = { 0, 12, 31, 30, 31, 30, 31,0,0,0,0,0 };//xj每个月的天数,用static数组里未定义的值是零,否则为垃圾值
//	int month=0, day=0, sum;
//	char schoolStartTime[1024];
//	fileHandle(schoolStartTime);
//	while(1)
//	{
//		sum = 0;//month,day,week,现在是星期几,总共多少天
//		printf("请输入日期(月 日,输入0 0退出程序):\n");
//		dateFill(dayOfMonth, schoolStartTime);
//		scanf("%d %d", &month, &day);
//		if (month == 0 && day == 0) {
//			return 0;
//		}
//		for (int i = 0; i < (month + 3) % 12; i++) {
//			sum += dayOfMonth[i];
//		}
//		sum += day;
//		int week = 1;
//		for (week = 1; 1; week++) { //for (int i = 1; 1; i++) {//c语言,函数内外变量重名的时候,内部优先,但我建议你别作,这样内部的出不来
//			if (sum > 7) {
//				sum -= 7;           //求这天星期几
//			}
//			else {
//				break;
//			}
//		}
//		printf("第%d周周%d\n", week, sum);
//	}
//}