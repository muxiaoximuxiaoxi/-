#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void game() {
	int random_num = rand() % 100 + 1;
	int input = 0;
	while (1) {
		printf("����������µ����֣�\n");
			scanf("%d", &input);
		if (input > random_num) {
			printf("����\n");
		}
		else if (input < random_num) {
			printf("С��\n");
		}
		else{
			printf("��ϲ����¶ԣ�\n");
			break;
		}
	}
}

void output() {
	printf("*******************\n");
	printf("��ʼ��Ϸ��1\n");
	printf("��ֹ��Ϸ��2");
	printf("*******************\n");
}
int main() {
	int input = 0;
	srand((int)time(0));
	do {
		output();
		printf("��ѡ��\n");
		scanf("%d", &input);
		if (input == 1) {
			game();
		}
		else if (input == 2) {
			break;
		}
		else {
			printf("����������������룡\n");
		}
	} while (input);
}
