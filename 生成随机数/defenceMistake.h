#ifndef DEFENCEMISTAKE_H
#define DEFENCEMISTAKE_H

#define WIDELY_SCANF_CHECK(input,judgeCondition)\
do{\
while (1) {\
	input;\
	cleanCache();\
	if (judgeCondition) {\
		printf("数据输入错误\n");\
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
}while(0)  /*do,while没有啥含义就是个夹子,另外宏是直接替换,不是函数传参*/ 
/*原始宏定义中的 printf("tip\n") 会导致直接输出字符串 "tip"，而非传入的提示参数.
这是因为 tip 被包裹在双引号中，编译器会将其视为普通字符串，而非宏参数*/

void defenceMistake(int* checkVar, int start, int over);
void cleanCache();

#endif // !DEFENCEMISTAKE_H
//只能判断整数