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
	int ef[12] = { 30,31,30,31,31,28,31,30,31,30,31,31 };//һ���ǳ���,һ��������.�ҷ���
	char year[5],month[3],day[3];
	strncpy(year, sj + 0, 4);
	year[4] = '\0';
	strncpy(month, sj + 4, 2);
	month[2] = '\0';
	strncpy(day, sj +6, 2);//ԭ����ַ���
	day[2] = '\0';//��0��ʼ
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
int wjcl(char sj[]) {//�ǵ�������÷�������
	char* wj = "date.txt";//���·��
	int bb = rqpd();
	if (bb == 2 || bb == 1) {
		FILE* b = fopen(wj, "w");
		if (b == NULL) {
			printf("�򲻿�\n");
			return 0;
		}
		printf("�ø���������\n");
		int ccc = fclose(b);
		if (ccc != 0) {
			printf("��д���Ƴ����bug�ز����ļ���1\n");
			return 0;
		}
	}
	FILE* n = fopen(wj, "a+");//w+�򿪾������
	if (n== NULL) {
		printf("�򲻿�\n");
		return 0;
	}
	int e = fgetc(n);
	if (e == -1)//ǧ�����int��char���ַ���
	{
		char c[] = "20240307";//����
		printf("��������ѧ�ڿ�ѧ������\nʾ��:2024��3��7�տ�ѧ\n20240307\n");
		scanf("%s", &c);
		int nn = fputs(c,n);
		if (nn < 0) {
			printf("д���ļ�ʧ��\n");
			return 0;
		}
		int cc = fclose(n);
		if (cc != 0) {
			printf("��д���Ƴ����bug�ز����ļ���55\n");
			return 0;
		}
	}
	if (e!=-1) {
		int cc = fclose(n);
		if (cc != 0) {
			printf("��д���Ƴ����bug�ز����ļ���2\n");
			return 0;
		}
	}
		FILE* tt = fopen(wj, "r");
		if (tt == NULL) {
			printf("�򲻿�\n");
			return 0;
		}
	char* nt = fgets(sj,1024,tt);
	int tmp;
	tmp = atoi(sj);
	sprintf(sj, "%d", tmp);
	if (nt == NULL) {
		printf("��д���Ƴ����bug�������ļ���3\n");
		return 0;
	}
	int hhh = fclose(tt);
	if (hhh != 0) {
		printf("��д���Ƴ����bug�ز����ļ���4\n");
		return 0;
	}
	return 1;
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