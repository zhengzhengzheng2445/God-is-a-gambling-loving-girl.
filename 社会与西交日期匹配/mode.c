#define _CRT_SECURE_NO_WARNINGS//你能写中文注释吗,选项卡是tab,退出esc
#include <stdio.h>
int main() {
	int m, d, w, r, sum;
s:	m = 0, d = 0, w = 0, r = 0,sum=0;//month,day,week,现在是星期几,总共多少天
	printf("请输入日期(月 日,输入0 0退出程序):\n");
	
	scanf("%d %d", &m, &d);
	if (m == 0 && d == 0) {
		return 0;
	}
	//int rqs[12] = { 31, 0, 0, 0, 0, 30, 31, 31, 30, 31, 30, 31 };//每个月的天数
	int rqx[7] = { 0, 12, 31, 30, 31, 30, 31};//下学期每个月的天数
	for (int i = 0; i<m-1; i++) {
		sum += rqx[i];
	}
	sum += d;
	int i = 1;
	//for (int i = 1; 1; i++) {//c语言,函数内外变量重名的时候,内部优先,但我建议你别作,这样内部的出不来
	for (i = 1; 1; i++) {
		if (sum > 7) {
			sum -= 7;
		}else {
			break;
		}
    }
	printf("第%d周周%d\n", i,sum);
	goto s;
	return 0;
}