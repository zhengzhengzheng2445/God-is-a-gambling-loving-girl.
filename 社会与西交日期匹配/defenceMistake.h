#ifndef DEFENCEMISTAKE_H
#define DEFENCEMISTAKE_H
#define FILE_CHECK(ptr,tip)	\
do{\
    if (ptr) {\
          printf("%s\n",(tip));\
          exit(-1);\
     }\
}while(0)  /*do,whileû��ɶ������Ǹ�����,�������ֱ���滻,���Ǻ�������*/ 
/*ԭʼ�궨���е� printf("tip\n") �ᵼ��ֱ������ַ��� "tip"�����Ǵ������ʾ������
������Ϊ tip ��������˫�����У��������Ὣ����Ϊ��ͨ�ַ��������Ǻ����*/
void defenceMistake(int* checkVar, int start, int over);
#endif // !DEFENCEMISTAKE_H
//ֻ���ж�����