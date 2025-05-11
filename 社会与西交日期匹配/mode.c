#define _CRT_SECURE_NO_WARNINGS//你能写中文注释吗,选项卡是tab,退出esc
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int rqpd() {//日期判断
	time_t ti;
	time(&ti);
	struct tm* p;
	p = gmtime(&ti);
	if (p->tm_mon==8&&p->tm_mday==24) {
		return 2;
	}
	else if(p->tm_mon == 2 && p->tm_mday == 3){
		return 1;
	}
	else {
		return 3;
	}
}
void dom(int ab[], char sj[]) {
	int ef[12] = { 30,31,30,31,31,28,31,30,31,30,31,31 };//一个是长度,一个是索引.我服了
	char year[5],month[3],day[3];
	strncpy(year, sj + 0, 4);
	year[4] = '\0';
	strncpy(month, sj + 4, 2);
	month[2] = '\0';
	strncpy(day, sj +6, 2);//原理见字符串
	day[2] = '\0';//从0开始
	int yy, mm, dd;
	yy = atoi(year), mm = atoi(month), dd = atoi(day);
	for (int i = 0; i < (mm+3)%12; i++) {
			ab[i] = 0;
		}
	ab[(mm+3)%12] = ef[(mm + 3) % 12] - dd + 1;
	for (int i = 11; i > (mm + 3) % 12; i--) {
			ab[i] = ef[i];
		}
	if (yy % 4 == 0) {
		ab[5] += 1;
	}

}
int wjcl(char sj[]) {//记得最后必须得返回数字
	char* wj = "date.txt";//相对路径
	int bb = rqpd();
	if (bb == 2 || bb == 1) {
		FILE* b = fopen(wj, "w");
		if (b == NULL) {
			printf("打不开\n");
			return 0;
		}
		printf("该更新日期了\n");
		int ccc = fclose(b);
		if (ccc != 0) {
			printf("你写的破程序出bug关不了文件了1\n");
			return 0;
		}
	}
	FILE* n = fopen(wj, "a+");//w+打开就清空了
	if (n== NULL) {
		printf("打不开\n");
		return 0;
	}
	int e = fgetc(n);
	if (e == -1)//千万分清int和char和字符串
	{
		char c[] = "20240307";//可以
		printf("请输入这学期开学年月日\n示例:2024年3月7日开学\n20240307\n");
		scanf("%s", &c);
		int nn = fputs(c,n);
		if (nn < 0) {
			printf("写入文件失败\n");
			return 0;
		}
		int cc = fclose(n);
		if (cc != 0) {
			printf("你写的破程序出bug关不了文件了55\n");
			return 0;
		}
	}
	if (e!=-1) {
		int cc = fclose(n);
		if (cc != 0) {
			printf("你写的破程序出bug关不了文件了2\n");
			return 0;
		}
	}
		FILE* tt = fopen(wj, "r");
		if (tt == NULL) {
			printf("打不开\n");
			return 0;
		}
	char* nt = fgets(sj,1024,tt);
	int tmp;
	tmp = atoi(sj);
	sprintf(sj, "%d", tmp);
	if (nt == NULL) {
		printf("你写的破程序出bug读不了文件了3\n");
		return 0;
	}
	int hhh = fclose(tt);
	if (hhh != 0) {
		printf("你写的破程序出bug关不了文件了4\n");
		return 0;
	}
	return 1;
}
int main() {
	int dayOfMonth[12] = { 0, 12, 31, 30, 31, 30, 31,0,0,0,0,0 };//xj每个月的天数,用static数组里未定义的值是零,否则为垃圾值
	int m, d, w, r, sum;
	char sj[1024];
	if (wjcl(sj) == 0) {
		return 0;
	}
s:	m = 0, d = 0, w = 0, r = 0,sum=0;//month,day,week,现在是星期几,总共多少天
	printf("请输入日期(月 日,输入0 0退出程序):\n");
	dom(dayOfMonth, sj);
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