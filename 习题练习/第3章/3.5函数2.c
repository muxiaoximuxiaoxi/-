#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//��һ������
//y=-1(x<0)
//y=0(x==0)
//y=-1(x>0) 
//д�����ĳ��� 
int main() {
	int x = 0, y = 0;
	printf("����x\n");
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
