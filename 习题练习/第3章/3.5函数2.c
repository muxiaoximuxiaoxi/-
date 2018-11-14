#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//有一函数：
//y=-1(x<0)
//y=0(x==0)
//y=-1(x>0) 
//写出它的程序 
int main() {
	int x = 0, y = 0;
	printf("输入x\n");
	scanf("%d", &x);
	if (x < 0) {
		printf("x=%d\n", x);
		printf("y=-1\n");
	}
	else if (x == 0) {
		printf("x=%d\n", x);
		printf("y=0\n");
	}
	else {
		printf("x=%d\n", x);
		printf("y=1\n");
	}
	system("pause");
}
