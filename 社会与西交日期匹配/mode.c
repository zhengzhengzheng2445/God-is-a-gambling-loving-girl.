//����д����ע����,ѡ���tab,�˳�esc
#include <stdio.h>           //ͷ�ļ������Ŀ����ļ�û��Ҫд��
#include <stdlib.h>
#include "dateCheck.h"          //�����ж�,�����Ƿ���Ҫ�����ļ�
#include "dateHandle.h"           //�����������
#include "fileHandle.h"
#include "defenceMistake.h"
int main() {
	int month = 0, day = 0;
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
			FILE_CHECK(NULL == tofile, "���ڸ��³���");
			int cresult = fclose(tofile);
			FILE_CHECK(0 != cresult, "���¹رճ���");
		}
		else if (month == 0 && day == 2) {
			system("schoolcalendar.jpg");
		}
		else {
			dateHandle(month, day, schoolStartTime);
		}
	}
}