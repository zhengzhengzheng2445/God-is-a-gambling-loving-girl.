//����д����ע����,ѡ���tab
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include "randNum.h"
#include "defenceMistake.h"
int main() {
	srand(time(NULL));
	while(1){
		printf("��ѡ��ģʽ:\n0.�˳�����\n1.��ͨģʽ:������ظ��������\n2.ϴ��ģʽ��������ظ��������\n");
		int start = 0, over = 0, length = 0, control = 0,n=0;//n�ظ�����
		defenceMistake(&control,0,2);

		if (control == 0) {
			return 0;
		}
		printf("������������ķ�Χ��ʼ,��β,�������ظ�����,�м��ÿո���\n����:3��100֮��Ҫ�˸�������ظ�ִ��5��,3 100 8 5\n");
		if (control == 2) {
			WIDELY_SCANF_CHECK
			(scanf("%d %d %d %d", &start, &over, &length, &n),
				start >= over || (over - start + 1) < length || n <= 0);//У��������Ч��
			for (int i = 0; i < n;i++) {
				shuffle(start, over, length);
			}
		}else {
			WIDELY_SCANF_CHECK
			(scanf("%d %d %d %d", &start, &over, &length, &n),
				start >= over || n <= 0);//У��������Ч��
			for (int i = 0; i < n; i++) {
				commonExecution(start, over, length);
			}
		}
	}
	return 0;
}