#define _CRT_SECURE_NO_WARNINGS//你能写中文注释吗,选项卡是tab,退出esc
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int rqpd() {//日期判断
	time_t ti;
	time(&ti);
	struct tm* p;
	p = gmtime(&ti);
	if (p->tm_mon==8&&p->tm_mday==24) {
		return 2;
	}
	else if(p->tm_mon == 1 && p->tm_mday == 29){
		return 1;
	}
	else {
		return 3;
	}
}
void dom(int ab[]) {
	int k[12] = { 0 };
	int ef[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
}
int wjcl() {
	char* wj = "date.txt";//相对路径
	int bb = rqpd();
	if (bb == 2 || bb == 1) {
		FILE* b = fopen(wj, "w");
		printf("该更新日期了\n");
		int c = fclose(b);
		if (c != 0) {
			printf("你写的破程序出bug关不了文件了\n");
			return 0;
		}
	}
	FILE* n = fopen(wj, "r");
	char e = fgetc(n);
	if (e == -1)
	{
		int c[] = { 20240307 };//可以
		printf("请输入这学期开学年月日\n示例:2024年3月7日开学\n20240307\n");
		scanf("%d", &c);
		int nn = fputs(c, n);
		if (nn < 0) {
			printf("写入文件失败\n");
			return 0;
		}
	}
}
int main() {
	int dayOfMonth[12] = { 0, 12, 31, 30, 31, 30, 31,0,0,0,0,0 };//xj每个月的天数,用static数组里未定义的值是零,否则为垃圾值
	int m, d, w, r, sum;
	if (wjcl() == 0) {
		return 0;
	}
s:	m = 0, d = 0, w = 0, r = 0,sum=0;//month,day,week,现在是星期几,总共多少天
	printf("请输入日期(月 日,输入0 0退出程序):\n");
	scanf("%d %d", &m, &d);
	if (m == 0 && d == 0) {
		return 0;
	}
	dom(dayOfMonth);
	for (int i = 0; i<m-1; i++) {
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