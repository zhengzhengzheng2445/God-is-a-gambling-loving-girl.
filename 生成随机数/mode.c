//����д����ע����,ѡ���tab
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void shuffle(int s,int o,int l){
	int* result = malloc((o - s + 1) * sizeof(int));
	if (result == NULL) {
		printf("�ڴ�����ʧ��\n");
		exit(-1);//��ʾ������˳�
	}
	for (int i = 0; i <o-s+1; i++) {
		result[i] = s + i;
	}
	for (int i = 0; i < l; i++) {
		int random = rand() % (o - s+1 - i), temp = 0;
		temp = result[o-s-i];
		result[o - s - i] = result[random];
		printf("%d\t", result[o - s - i]);
		result[random] = temp;
	}
	printf("\n\n\n");
	free(result);
	result = NULL;
}//ϴ��
void commonExecution(int s, int o, int l) {
	for (int i = 0; i <l; i++) {
		printf("%d\t",rand() % (o - s +1) + s);
	}
	printf("\n\n\n");
}//��ִͨ��
int main() {
	srand(time(NULL));
	while(1){
		printf("��ѡ��ģʽ:\n0.�˳�����\n1.��ͨģʽ:������ظ��������\n2.ϴ��ģʽ��������ظ��������\n");
		int start = 0, over = 0, length = 0, control = 0,n=0;//n�ظ�����
		while (1) {
			scanf("%d", &control);
			if (control > 2) {
				printf("�������\n");
			}
			else {
				break;
			}
		}//У��control��Ч��
		if (control == 0) {
			return 0;
		}
		printf("������������ķ�Χ��ʼ,��β,�������ظ�����,�м��ÿո���\n����:3��100֮��Ҫ�˸�������ظ�ִ��5��,3 100 8 5\n");
		if (control == 2) {
			while (1) {
				scanf("%d %d %d %d", &start, &over, &length, &n);
				if (start >= over || (over - start) < length || n <= 0) {
					printf("�����������\n");
				}
				else {
					break;
				}
			}//У��������Ч��
			for (int i = 0; i < n;i++) {
				shuffle(start, over, length);
			}
		}else {
			while (1) {
				scanf("%d %d %d %d", &start, &over, &length, &n);
				if (start >= over || n <= 0) {
					printf("�����������\n");
				}
				else {
					break;
				}
			}//У��������Ч��
			for (int i = 0; i < n; i++) {
				commonExecution(start, over, length);
			}
		}
	}
	return 0;
}