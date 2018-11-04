#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void game() {
	int random_num = rand() % 100 + 1;
	int input = 0;
	while (1) {
		printf("请你输入你猜的数字：\n");
			scanf("%d", &input);
		if (input > random_num) {
			printf("大了\n");
		}
		else if (input < random_num) {
			printf("小了\n");
		}
		else{
			printf("恭喜，你猜对！\n");
			break;
		}
	}
}

void output() {
	printf("*******************\n");
	printf("开始游戏：1\n");
	printf("终止游戏：2");
	printf("*******************\n");
}
int main() {
	int input = 0;
	srand((int)time(0));
	do {
		output();
		printf("请选择\n");
		scanf("%d", &input);
		if (input == 1) {
			game();
		}
		else if (input == 2) {
			break;
		}
		else {
			printf("输入错误，请重新输入！\n");
		}
	} while (input);
}
