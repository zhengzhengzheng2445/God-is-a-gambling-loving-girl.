////�������,����취�в²���������,С����ʾ��С,С��ʹ��ȥβ�����ַ�,�Ҳ�����������޴��ķ���,�㿴�����׾Ϳ�,�Լ�����Ҳ���200
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//int rrand() {
//	return rand() % 200 + 1;
//}//�����
//int erfen(int s, int o) {//c�ο�ֵ,s���,o�յ�
//	return (s + o) / 2;
//}//�����ﲻ��ˮ����,��Ҫ�ǰ�q��a����ɺ���,�Ժ�����б��
//int ares() {
//	int q = rrand();//q����,a��
//	//printf("%d", q);
//	int i = 1, a = 100, s = 1, o = 200;//i����,s���,o�յ�
//	for (int h = 0; h < 200; h++) {
//		// printf("%d,%d", q, a);
//		if (q > a)
//		{
//			i++;
//			s = a ;
//		}
//		else if (q < a) {
//			i++;
//			o = a ;
//		}
//		else {
//			i++;
//			return i;
//		}
//		a = erfen(s, o);
//	}
////}//����ÿ��ʵ������ô���
//int main() {
//	srand(time(NULL));//����//���������
//	float sum = 0, res;// ����,ÿ�ν��
//	for (int i = 0; i < 8000000; i++) {
//		res = ares();
//		sum += res;
//	}
//	printf("ƽ������Ϊ%f\n", sum / 8000000);
//	return 0;
//}
//

//С����ʾ��С,С��ʹ�ñ�׼���ַ�
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int rrand() {
	return rand() % 200 + 1;
}//�����
int erfen(int s,int o) {//c�ο�ֵ,s���,o�յ�
			return (s+o)/2;
}//�����ﲻ��ˮ����,��Ҫ�ǰ�q��a����ɺ���,�Ժ�����б�Ļ���ά��,�ṩ���븴����
int ares() {
	int q = rrand();//q����,a��
	//printf("%d", q);
	int i = 1,a = 100,s=1,o=200;//i����,s���,o�յ�
	for (int h = 0; h < 200; h++) {
		// printf("%d,%d", q, a);
		if (q > a)
		{
			i++;
			s = a+1;
		}else if(q < a) {
			i++;
			o=a-1;
		}
		else {
			i++;
			return i;
		}
		a = erfen(s,o);
	}	
}//����ÿ��ʵ������ô���
int main() {
	srand(time(NULL));//����//���������
	float sum = 0;  int res;// ����,ÿ�ν��
	for (int i = 0; i < 8000000; i++) {
		res = ares();
		sum += res;
	}
	printf("ƽ������Ϊ%f\n", sum / 8000000);
	return 0;
}


//С��ֻ��ʾ�Դ�,С�첻�ظ��µĸ���
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//int rrand() {
//	return rand() % 200 + 1;
//}//�����
//int rrrand(int fc[], int h) {
//	int a;
//	for (;;) {
//hh:		a = rrand();
//		for (int i = 0; i < h + 1; i++) {
//			//printf("%d\n", *(fc + i));
//			if (a == *(fc + i)) {
//				goto hh;
//			}
//		}
//		return a;
//	}
//}
//int ares() {
//	int fc[200] = { 0 };
//	int q = rrand();//q����,a��
//	//printf("%d", q);
//	int i = 0;
//	for (int h = 0; h < 200; h++) {
//		int a = rrrand(fc, h);
//		fc[h] = a;
//		// printf("%d,%d", q, a);
//		if (q != a)
//		{
//			i++;
//		}else {
//			i++;
//			break;
//		}
//	}
//	return i;
//}
//int main() {
//	srand(time(NULL));//����//���������
//	float sum = 0, res;// ����,ÿ�ν��
//	for (int i = 0; i < 800000; i++) {
//		res = ares();
//		sum += res;
//	}
//	printf("ƽ������Ϊ%f\n", sum / 800000);
//	return 0;
//}


//С��ֻ��ʾ�Դ�,С����ظ��µĸ���
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//int ares() {
//    int q = rand() % 200 + 1; // Ŀ������
//    int i = 0;
//    for (; ; ) {
//        int a = rand() % 200 + 1; // �²������
//        printf("%d,%d\n", q, a);
//        if (q != a) {
//            i++;
//        }
//        else {
//            i++;
//            break;
//        }
//    }
//    return i;
//}
//int main() {
//    srand(time(NULL)); // ��ʼ�����������
//    float sum = 0;
//    for (int i = 0; i < 100; i++) {
//        sum += ares();
//    }
//    printf("ƽ������Ϊ %f\n", sum / 100);
//    return 0;
//}


/*����ģʽ��, ctrl + alt + i�������ڿ�����һЩС��������sum = rrand(); ������python��
��һ��ָ��һ�����,���������½��������ߺ���ʲô��,*/