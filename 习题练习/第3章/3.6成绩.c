#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//给出一百分制成绩，要求输出成绩等级’A'、’B’、
//’C'、’D’、’E'。90分以上为’A'，80~89分为’B’，
//70~79分为’C’，60~69分为’D'，60分以下为’E’
int main() {
	int n = 0;
	printf("请输入成绩\n");
	scanf("%d", &n);
	while (n < 0 || n>100) {
		printf("输入有误，请重新输入！\n");
		scanf("%d", &n);
	}
	printf("输入的成绩为%d\n", n);
	switch(n / 10) {
		case 9:
			printf("成绩为A\n");
			break;
		case 8:
			printf("成绩为B\n");
			break;
		case 7:
			printf("成绩为C\n");
			break;
		case 6:
			printf("成绩为D\n");
			break;
		default:
			printf("成绩为E\n");
			break;
	}
	system("pause");
}
