#ifndef DEFENCEMISTAKE_H
#define DEFENCEMISTAKE_H

#define WIDELY_SCANF_CHECK(input,judgeCondition)\
do{\
while (1) {\
	input;\
	cleanCache();\
	if (judgeCondition) {\
		printf("�����������\n");\
	}\
	else {\
		break;\
	}\
}\
}while(0)

#define FILE_CHECK(judgeCondition,tip)	\
do{\
    if (judgeCondition) {\
          printf("%s\n",(tip));\
          exit(-1);\
     }\
}while(0)  /*do,whileû��ɶ������Ǹ�����,�������ֱ���滻,���Ǻ�������*/ 
/*ԭʼ�궨���е� printf("tip\n") �ᵼ��ֱ������ַ��� "tip"�����Ǵ������ʾ����.
������Ϊ tip ��������˫�����У��������Ὣ����Ϊ��ͨ�ַ��������Ǻ����*/

void defenceMistake(int* checkVar, int start, int over);
void cleanCache();

#endif // !DEFENCEMISTAKE_H
//ֻ���ж�����