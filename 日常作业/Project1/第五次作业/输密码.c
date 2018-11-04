#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main() {
	int str[100] = { 0,0,0,0,0,0, };
		int i = 0;
	for (i = 0; i < 3; i++) {
		printf("请输入密码:\n");
		scanf("%s", str);
		if (strcmp(str, "123456") == 0) {
			break;
		}
	}
	if (i >= 3) {
		printf("输入密码错误以达三次，退出程序\n");
	}
	else {
		printf("登录成功！！！\n");
	}
	system("pause");
}
