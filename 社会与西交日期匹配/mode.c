//#define _CRT_SECURE_NO_WARNINGS//����д����ע����,ѡ���tab,�˳�esc
//#include <stdio.h>           //ͷ�ļ������Ŀ����ļ�û��Ҫд��
//#include "dateCheck.h"          //�����ж�,�����Ƿ���Ҫ�����ļ�
//#include "dateFill.h"           //�����������
//#include "fileHandle.h"
//int main() {
//	int dayOfMonth[12] = { 0, 12, 31, 30, 31, 30, 31,0,0,0,0,0 };//xjÿ���µ�����,��static������δ�����ֵ����,����Ϊ����ֵ
//	int month=0, day=0, sum;
//	char schoolStartTime[1024];
//	fileHandle(schoolStartTime);
//	while(1)
//	{
//		sum = 0;//month,day,week,���������ڼ�,�ܹ�������
//		printf("����������(�� ��,����0 0�˳�����):\n");
//		dateFill(dayOfMonth, schoolStartTime);
//		scanf("%d %d", &month, &day);
//		if (month == 0 && day == 0) {
//			return 0;
//		}
//		for (int i = 0; i < (month + 3) % 12; i++) {
//			sum += dayOfMonth[i];
//		}
//		sum += day;
//		int week = 1;
//		for (week = 1; 1; week++) { //for (int i = 1; 1; i++) {//c����,�����������������ʱ��,�ڲ�����,���ҽ��������,�����ڲ��ĳ�����
//			if (sum > 7) {
//				sum -= 7;           //���������ڼ�
//			}
//			else {
//				break;
//			}
//		}
//		printf("��%d����%d\n", week, sum);
//	}
//}