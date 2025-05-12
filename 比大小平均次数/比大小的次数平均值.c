////别用这个,这个办法有猜不出来的数,小明提示大小,小红使用去尾法二分法,我不想介绍我那愚蠢的方法,你看的明白就看,以及这个找不到200
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//int rrand() {
//	return rand() % 200 + 1;
//}//随机数
//int erfen(int s, int o) {//c参考值,s起点,o终点
//	return (s + o) / 2;
//}//我这里不算水字数,主要是把q和a都封成函数,以后情况有变的
//int ares() {
//	int q = rrand();//q问题,a答案
//	//printf("%d", q);
//	int i = 1, a = 100, s = 1, o = 200;//i次数,s起点,o终点
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
////}//计算每次实验的所用次数
//int main() {
//	srand(time(NULL));//种子//引入随机数
//	float sum = 0, res;// 总数,每次结果
//	for (int i = 0; i < 8000000; i++) {
//		res = ares();
//		sum += res;
//	}
//	printf("平均次数为%f\n", sum / 8000000);
//	return 0;
//}
//

//小明提示大小,小红使用标准二分法
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int rrand() {
	return rand() % 200 + 1;
}//随机数
int erfen(int s,int o) {//c参考值,s起点,o终点
			return (s+o)/2;
}//我这里不算水字数,主要是把q和a都封成函数,以后情况有变的话好维护,提供代码复用性
int ares() {
	int q = rrand();//q问题,a答案
	//printf("%d", q);
	int i = 1,a = 100,s=1,o=200;//i次数,s起点,o终点
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
}//计算每次实验的所用次数
int main() {
	srand(time(NULL));//种子//引入随机数
	float sum = 0;  int res;// 总数,每次结果
	for (int i = 0; i < 8000000; i++) {
		res = ares();
		sum += res;
	}
	printf("平均次数为%f\n", sum / 8000000);
	return 0;
}


//小明只提示对错,小红不重复猜的概率
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//int rrand() {
//	return rand() % 200 + 1;
//}//随机数
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
//	int q = rrand();//q问题,a答案
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
//	srand(time(NULL));//种子//引入随机数
//	float sum = 0, res;// 总数,每次结果
//	for (int i = 0; i < 800000; i++) {
//		res = ares();
//		sum += res;
//	}
//	printf("平均次数为%f\n", sum / 800000);
//	return 0;
//}


//小明只提示对错,小红可重复猜的概率
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//int ares() {
//    int q = rand() % 200 + 1; // 目标数字
//    int i = 0;
//    for (; ; ) {
//        int a = rand() % 200 + 1; // 猜测的数字
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
//    srand(time(NULL)); // 初始化随机数种子
//    float sum = 0;
//    for (int i = 0; i < 100; i++) {
//        sum += ares();
//    }
//    printf("平均次数为 %f\n", sum / 100);
//    return 0;
//}


/*调试模式下, ctrl + alt + i立即窗口可以试一些小东西比如sum = rrand(); 类似于python那
种一个指令一个结果,不过不能新建变量或者函数什么的,*/