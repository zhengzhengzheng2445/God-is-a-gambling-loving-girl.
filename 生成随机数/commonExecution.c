#include "randNum.h"
#include <stdio.h>
#include <stdlib.h>
void commonExecution(int s, int o, int l) {
	for (int i = 0; i < l; i++) {
		printf("%d\t", rand() % (o - s + 1) + s);
	}
	printf("\n\n\n");
}//ÆÕÍ¨Ö´ÐÐ