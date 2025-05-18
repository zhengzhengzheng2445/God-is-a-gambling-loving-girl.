#define _CRT_SECURE_NO_WARNINGS
#define no 135644
#include <stdio.h>
int main() {
	while(1)
	{
		int remindNmb = no, selectFunction = no;                                               //提醒次数,功能选择
		int tmRecord[8] = {no,no,no,no,no,no,no,no};
		remind(timeGet(tmRecord));
		printf("请选择功能:\n1.转换日期\n2.查看图片\n3.更新修改数据\n0.退出程序");
		selectFunction = defenceMistake(selectFunction, 0, 3);                                 //验证输入是否有效
		if (selectFunction = 1) {
			datetrans();
		}
		else if (selectFunction = 2) {
			photoView();
		}
		else if(selectFunction = 2){
			updateData();
		}
		else {
			break;
		}
	}
	return 0;
}
