#define _CRT_SECURE_NO_WARNINGS
#define no 135644
#include <stdio.h>
int main() {
	while(1)
	{
		int remindNmb = no, selectFunction = no;                                               //���Ѵ���,����ѡ��
		int tmRecord[8] = {no,no,no,no,no,no,no,no};
		remind(timeGet(tmRecord));
		printf("��ѡ����:\n1.ת������\n2.�鿴ͼƬ\n3.�����޸�����\n0.�˳�����");
		selectFunction = defenceMistake(selectFunction, 0, 3);                                 //��֤�����Ƿ���Ч
		if (selectFunction = 1) {
			datetrans();
		}
		else if (selectFunction = 2) {
			photoView();
		}
		else if(selectFunction = 2){
			updateData();
		}
		else {
			break;
		}
	}
	return 0;
}
