#define _CRT_SECURE_NO_WARNINGS//����д����ע����,ѡ���tab,�˳�esc
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int rqpd() {//�����ж�
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
	int ef[12] = { 30,31,30,31,31,28,31,30,31,30,31,31 };
	char year[5],month[3],day[3];
	strncpy(year, sj + 1, 4);
	strncpy(month, sj + 5, 2);
	strncpy(day, sj + 7, 2);
	year[5] = '\0', month[3] = '\0', day[3] = '\0';
	int yy = year,mm=month,dd=day;
	for (int i = 0; i < (mm+4)-1; i++) {
			ab[i] = 0;
		}
		ab[mm+4] = ab[mm+4] - dd + 1;
		for (int i = 0; i > mm; i++) {
			ab[i] = ef[i];
		}
}
int wjcl(char sj[]) {
	char* wj = "date.txt";//���·��
	int bb = rqpd();
	if (bb == 2 || bb == 1) {
		FILE* b = fopen(wj, "w");
		printf("�ø���������\n");
		int c = fclose(b);
		if (c != 0) {
			printf("��д���Ƴ����bug�ز����ļ���\n");
			return 0;
		}
	}
	FILE* n = fopen(wj, "r");
	char e = fgetc(n);
	if (e == -1)
	{
		int c[] = { 20240307 };//����
		printf("��������ѧ�ڿ�ѧ������\nʾ��:2024��3��7�տ�ѧ\n20240307\n");
		scanf("%d", &c);
		int nn = fputs(c, n);
		if (nn < 0) {
			printf("д���ļ�ʧ��\n");
			return 0;
		}
		int cc = fclose(n);
		if (cc != 0) {
			printf("��д���Ƴ����bug�ز����ļ���\n");
			return 0;
		}
	}
	char* nt = fgets(sj,1024,n);
	if (nt == NULL) {
		printf("��д���Ƴ����bug�������ļ���\n");
		return 0;
	}
	int c = fclose(n);
	if (c != 0) {
		printf("��д���Ƴ����bug�ز����ļ���\n");
		return 0;
	}
}
int main() {
	int dayOfMonth[12] = { 0, 12, 31, 30, 31, 30, 31,0,0,0,0,0 };//xjÿ���µ�����,��static������δ�����ֵ����,����Ϊ����ֵ
	int m, d, w, r, sum;
	char sj[1024];
	if (wjcl(sj) == 0) {
		return 0;
	}
s:	m = 0, d = 0, w = 0, r = 0,sum=0;//month,day,week,���������ڼ�,�ܹ�������
	printf("����������(�� ��,����0 0�˳�����):\n");
	scanf("%d %d", &m, &d);
	if (m == 0 && d == 0) {
		return 0;
	}
	dom(dayOfMonth,sj);
	for (int i = 0; i < (m+4)%12-1; i++) {
		sum += dayOfMonth[i];
	}
	sum += d;
	int i = 1;
 	for (i = 1; 1; i++) { //for (int i = 1; 1; i++) {//c����,�����������������ʱ��,�ڲ�����,���ҽ��������,�����ڲ��ĳ�����
		if (sum > 7) {
			sum -= 7;
		}else {
			break;
		}
    }
	printf("��%d����%d\n", i,sum);
	goto s;
}