#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
int main() {
	int n = 0;
	int str[] = { 1,2,3,4,5,6,7,8,9 };
	printf("����������Ҫ���ҵ���ֵ��");
	scanf("%d", &n);
	int low = 1;
	int high = sizeof(str) / sizeof(str[0])-1;
	int mid = 0;
	while (low <= high) {
		mid = (low + high) / 2;
		if (str[mid] > n) {
			high = mid - 1;
		}
		else if (str[mid] < n) {
			low = mid + 1;
		}
		else {
			break;
		}
	}
	if (low <= high) {
			printf("�ҵ������±�Ϊ��%d\n", mid);
		}
		else {
			printf("û�ҵ�\n");
		}
	system("pause");
}
