//你能写中文注释吗,选项卡是tab,退出esc
#include <stdio.h>           //头文件包含的库主文件没必要写了
#include "dateCheck.h"          //日期判断,决定是否需要更新文件
#include "dateFill.h"           //填充日期数组
#include "fillHandle.h"

int main() {
	int dayOfMonth[12] = { 0, 12, 31, 30, 31, 30, 31,0,0,0,0,0 };//xj每个月的天数,用static数组里未定义的值是零,否则为垃圾值
	int m, d, w, r, sum;
	char sj[1024];
	fillHandle(sj);
s:	m = 0, d = 0, w = 0, r = 0,sum=0;//month,day,week,现在是星期几,总共多少天
	printf("请输入日期(月 日,输入0 0退出程序):\n");
	dateFill(dayOfMonth, sj);
	scanf("%d %d", &m, &d);
	if (m == 0 && d == 0) {
		return 0;
	}
	for (int i = 0; i < (m+3)%12; i++) {
		sum += dayOfMonth[i];
	}
	sum += d;
	int i = 1;
 	for (i = 1; 1; i++) { //for (int i = 1; 1; i++) {//c语言,函数内外变量重名的时候,内部优先,但我建议你别作,这样内部的出不来
		if (sum > 7) {
			sum -= 7;
		}else {
			break;
		}
    }
	printf("第%d周周%d\n", i,sum);
	goto s;
}