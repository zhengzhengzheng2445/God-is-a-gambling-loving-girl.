#define _CRT_SECURE_NO_WARNINGS//����д����ע����,ѡ���tab,�˳�esc
#include <stdio.h>
int main() {
	int m, d, w, r, sum;
s:	m = 0, d = 0, w = 0, r = 0,sum=0;//month,day,week,���������ڼ�,�ܹ�������
	printf("����������(�� ��,����0 0�˳�����):\n");
	
	scanf("%d %d", &m, &d);
	if (m == 0 && d == 0) {
		return 0;
	}
	//int rqs[12] = { 31, 0, 0, 0, 0, 30, 31, 31, 30, 31, 30, 31 };//ÿ���µ�����
	int rqx[7] = { 0, 12, 31, 30, 31, 30, 31};//��ѧ��ÿ���µ�����
	for (int i = 0; i<m-1; i++) {
		sum += rqx[i];
	}
	sum += d;
	int i = 1;
	//for (int i = 1; 1; i++) {//c����,�����������������ʱ��,�ڲ�����,���ҽ��������,�����ڲ��ĳ�����
	for (i = 1; 1; i++) {
		if (sum > 7) {
			sum -= 7;
		}else {
			break;
		}
    }
	printf("��%d����%d\n", i,sum);
	goto s;
	return 0;
}