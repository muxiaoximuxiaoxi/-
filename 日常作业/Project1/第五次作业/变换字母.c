#include<stdio.h>
#include<stdlib.h>
int main() {
	int ch = 0;
	printf("�������ַ���\n");
	ch = getchar();
	while (1) {
		ch = getchar();
		if (ch > 'a'&&ch < 'z') {
			printf("%c\t", ch-32);
		}
		else if (ch > 'A'&&ch < 'Z') {
			printf("%c\t", ch+32);
		}
		else {

		};
	}
	system("pasue");
}
