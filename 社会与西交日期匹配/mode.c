#define _CRT_SECURE_NO_WARNINGS//����д����ע����,ѡ���tab,�˳�esc
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int rqpd() {//�����ж�
	time_t ti;
	struct tm* p;
	p = gmtime(&ti);
	time(&ti);
	if (p->tm_mon==8&&p->tm_mday==24) {
		return 2;
	}
	else if(p->tm_mon == 1 && p->tm_mday == 16){
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
int main() {
	int dayOfMonth[12] = { 0, 12, 31, 30, 31, 30, 31,0,0,0,0,0 };//xjÿ���µ�����,��static������δ�����ֵ����,����Ϊ����ֵ
	char* wj = "date.txt";
	int bb = rqpd();
	if (bb==2 || bb==1) {
		FILE* b = fopen(wj,"w");
		printf("�ø���������\n");
		int c[] = {20240307};//����
		printf("��������ѧ�ڿ�ѧ������\nʾ��:2024��3��7�տ�ѧ\n20240307\n");
		scanf("%d",&c);
		fputs(c,b);
     fclose(b);
	}
	int m, d, w, r, sum;
s:	m = 0, d = 0, w = 0, r = 0,sum=0;//month,day,week,���������ڼ�,�ܹ�������
	printf("����������(�� ��,����0 0�˳�����):\n");
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