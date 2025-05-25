//你能写中文注释吗,选项卡是tab
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include "randNum.h"
#include "defenceMistake.h"
int main() {
	srand(time(NULL));
	while(1){
		printf("请选择模式:\n0.退出程序\n1.普通模式:输出可重复的随机数\n2.洗牌模式输出不可重复的随机数\n");
		int start = 0, over = 0, length = 0, control = 0,n=0;//n重复次数
		defenceMistake(&control,0,2);

		if (control == 0) {
			return 0;
		}
		printf("请输入随机数的范围开始,结尾,数量和重复次数,中间用空格间隔\n例如:3到100之间要八个随机数重复执行5次,3 100 8 5\n");
		if (control == 2) {
			WIDELY_SCANF_CHECK
			(scanf("%d %d %d %d", &start, &over, &length, &n),
				start >= over || (over - start + 1) < length || n <= 0);//校验输入有效性
			for (int i = 0; i < n;i++) {
				shuffle(start, over, length);
			}
		}else {
			WIDELY_SCANF_CHECK
			(scanf("%d %d %d %d", &start, &over, &length, &n),
				start >= over || n <= 0);//校验输入有效性
			for (int i = 0; i < n; i++) {
				commonExecution(start, over, length);
			}
		}
	}
	return 0;
}