#define _CRT_SECURE_NO_WARNINGS
#define NO 135644
#include <stdio.h>
#include "test.h"
#include "defenceMistake.h"
#include "dateTrans.h"
int main() {
	while(1)
	{
		printf("��ѡ����:\n1.ת������\n2.�鿴ͼƬ\n3.�����޸�����\n0.�˳�����\n");
		int remindNmb = NO, selectFunction = NO;                                               //���Ѵ���,����ѡ��
		int tmRecord[8] = {NO,NO,NO,NO,NO,NO,NO,NO};
		timeGet(tmRecord);
		remind(tmRecord);
		defenceMistake(&selectFunction, 0, 3);                                 //��֤�����Ƿ���Ч
		if (selectFunction == 1) {
			datetrans();
		}
		else if (selectFunction == 2) {
			photoView();
		}
		else if(selectFunction == 3){
			updateData();
		}
		else {
		  break;
		}
	}
	return 0;
}
