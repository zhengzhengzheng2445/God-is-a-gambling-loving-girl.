//����д����ע����,ѡ���tab,�˳�esc
#include <stdio.h>           //ͷ�ļ������Ŀ����ļ�û��Ҫд��
#include "dateCheck.h"          //�����ж�,�����Ƿ���Ҫ�����ļ�
#include "dateFill.h"           //�����������
#include "fillHandle.h"

int main() {
	int dayOfMonth[12] = { 0, 12, 31, 30, 31, 30, 31,0,0,0,0,0 };//xjÿ���µ�����,��static������δ�����ֵ����,����Ϊ����ֵ
	int m, d, w, r, sum;
	char sj[1024];
	fillHandle(sj);
s:	m = 0, d = 0, w = 0, r = 0,sum=0;//month,day,week,���������ڼ�,�ܹ�������
	printf("����������(�� ��,����0 0�˳�����):\n");
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