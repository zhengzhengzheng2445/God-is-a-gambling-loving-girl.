//����д����ע����,ѡ���tab,�˳�esc
#include <stdio.h>           //ͷ�ļ������Ŀ����ļ�û��Ҫд��
#include <stdlib.h>
#include "dateCheck.h"          //�����ж�,�����Ƿ���Ҫ�����ļ�
#include "dateFill.h"           //�����������
#include "fileHandle.h"
#include "defenceMistake.h"
int main() {
	int month = 0, day = 0, sum;
	char schoolStartTime[1024];
	printf("���ع���:\n0 1���¿�ѧ����\n0 2��У��\n\n");
	while (1)
	{
		fileHandle(schoolStartTime);//month,day,week,���������ڼ�,�ܹ�������
		printf("����������(�� ��,����0 0�˳�����):\n");
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
			int cresult = fclose(tofile);
			if (0 != cresult) {
				printf("���¹رճ���\n");
				return 0;
			}
		}
		else if (month == 0 && day == 2) {
			system("schoolcalendar.jpg");
		}
		else {
			dateHandle(month, day, schoolStartTime);
		}
	}
}