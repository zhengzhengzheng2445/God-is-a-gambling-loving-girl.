#define _CRT_SECURE_NO_WARNINGS
#define NO 135644
#include <stdio.h>
#include "test.h"
#include "defenceMistake.h"
#include "dateTrans.h"
int main() {
	while(1)
	{
		printf("请选择功能:\n1.转换日期\n2.查看图片\n3.更新修改数据\n0.退出程序\n");
		int remindNmb = NO, selectFunction = NO;                                               //提醒次数,功能选择
		int tmRecord[8] = {NO,NO,NO,NO,NO,NO,NO,NO};
		timeGet(tmRecord);
		remind(tmRecord);
		defenceMistake(&selectFunction, 0, 3);                                 //验证输入是否有效
		if (selectFunction == 1) {
			datetrans();
		}
		else if (selectFunction == 2) {
			photoView();
		}
		else if(selectFunction == 3){
			updateData();
		}
		else {
		  break;
		}
	}
	return 0;
}
