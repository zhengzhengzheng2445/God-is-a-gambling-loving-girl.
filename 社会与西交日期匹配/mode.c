//����д����ע����,ѡ���tab,�˳�esc
#include <stdio.h>           //ͷ�ļ������Ŀ����ļ�û��Ҫд��
#include <stdlib.h>
#include "dateCheck.h"          //�����ж�,�����Ƿ���Ҫ�����ļ�
#include "dateFill.h"           //�����������
#include "fileHandle.h"
#include "defenceMistake.h"
int main() {
	int dayOfMonth[12] = { 0, 12, 31, 30, 31, 30, 31,0,0,0,0,0 };//xjÿ���µ�����,��static������δ�����ֵ����,����Ϊ����ֵ
	int month=0, day=0, sum;
	char schoolStartTime[1024];
	fileHandle(schoolStartTime);
	printf("���ع���:\n0 2��У��\n0 1���¿�ѧ����\n\n");
	while(1)
	{
		sum = 0;//month,day,week,���������ڼ�,�ܹ�������
		printf("����������(�� ��,����0 0�˳�����):\n");
		dateFill(dayOfMonth, schoolStartTime);
		defenceMistake(&month, 0, 12);
		defenceMistake(&day, 0, 31);
		if (month == 0 && day == 0) {
			return 0;
		}
		else if (month == 0 && day == 1) {
			char filepath[] = "date.txt";
			FILE* tofile = fopen(filepath, "w");
			if (NULL == tofile) {
				printf("���ڸ��³���\n");
				return 0;
			}
			int cresult=fclose(tofile);
			if (0 != cresult) {
				printf("���¹رճ���\n");
				return 0;
			}
		}
		else if (month == 0 && day == 2) {
			system("schoolcalendar.jpg");
		}
		else{
			for (int i = 0; i < (month + 3) % 12; i++) {
				sum += dayOfMonth[i];
			}
			sum += day;
			int week = 1;
			for (week = 1; 1; week++) { //for (int i = 1; 1; i++) {//c����,�����������������ʱ��,�ڲ�����,���ҽ��������,�����ڲ��ĳ�����
				if (sum > 7) {
					sum -= 7;           //���������ڼ�
				}
				else {
					break;
				}
			}
			printf("��%d����%d\n", week, sum);
		}
	}
}