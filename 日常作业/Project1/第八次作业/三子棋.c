#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define X 3
#define Y 3
//��������ʼ������
char arr[X][Y];
void Init_Board(char arr[X][Y]) {
	srand((unsigned)time(0));
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < Y; j++) {
			arr[i][j] = ' ';
		}
	}
}
//��ӡ����
void Print_Board(char arr[X][Y]) {
	int i = 0;
	for (i = 0; i < X; i++) {
		printf(" %c | %c | %c \n", arr[i][0], arr[i][1],arr[i][2]);
		if (i < 2) {
			printf("---|---|---");
		}
		printf("\n");
	}
}
//�������
void Player_Chess(char arr[X][Y]) {
	int i = 0, j = 0;
	int retu=0;
	printf("��������ӣ��������ӵ�λ�ã�����������꣺X�������������꣺Y�����м��ÿո����\n");
	while (1) {
		retu=scanf("%d %d", &i, &j);//��scanf�ķ���ֵ����retu
		//��ս���
		while (retu != 2) {//��retu��Ϊ2��ʱ��ѭ����ʼ
			while (getchar() != '\n');//������뻺�����еķǷ��ַ�
			printf("������������������\n");
			retu = scanf("%d %d", &i, &j);
		}
		while (getchar() != '\n');//��������ɶ������һ�Σ���ջ�����
		if ((i >= 0 && i < X) && (j >= 0 && j < Y)) {
			if (arr[i][j] == ' ') {
				arr[i][j] = 'x';
				break;
			}
			else {
				printf("��λ���������ӣ�������������\n");
			}
		}
		else {
			printf("������������������\n");
			//break;��������
		}
	}
}
//��������
void Computer_Chess(char arr[X][Y]) {
	while (1) {
		int i = rand() % 3;
		int j = rand() % 3;
		if (arr[i][j] != ' ') {
			continue;
		}
		else {
			arr[i][j] = 'o';
			break;
		}
	}
}
//�ж������Ƿ�����
//����1Ϊ����0Ϊδ��
int Is_full(char arr[X][Y]) {
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < Y; j++) {
			if (arr[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
//�ж���Ӯ
char Is_Winner(char arr[X][Y]) {
	int ret = 0;
	for (int i = 0; i < X; i++) {
		if ((arr[i][0] == arr[i][1]) && (arr[i][0] == arr[i][2])&&arr[i][0]!=' ')
			return arr[i][0];
	}
	for (int j = 0; j < X; j++) {
		if ((arr[0][j] == arr[1][j]) && (arr[0][j] == arr[2][j])&&arr[0][j]!=' ')
			return arr[0][j];
	}
	if ((arr[0][0] == arr[1][1]) && (arr[0][0] == arr[2][2])&&arr[0][0]!=' ')
		return arr[0][0];
	if ((arr[2][0] == arr[1][1]) && (arr[2][0] == arr[0][2])&&arr[1][1]!=' ')
		return arr[2][0];
	ret = Is_full(arr);
	if (ret == 1) {
		return 'p';
	}
	return ' ';
}
//��ʼ�������Ϸ
void Game_board() {
	printf("************************\n");
	printf("��ʼ��Ϸ��1**������Ϸ��2\n");
	printf("************************\n");
}
int main() {
	int input = 1;
	while (input) {
		Game_board();
		char ret = 0;
		int retu=0;
		retu=scanf("%d", &input);
		while (retu != 1) {
			while (getchar() != '\n');//������뻺�����еķǷ��ַ�
			printf("������������������\n");
			retu = scanf("%d", &input);
		}
		if (input == 1) {
			Init_Board(arr);
			do {
				Print_Board(arr);//��ӡ����
				Player_Chess(arr);//�������
				Print_Board(arr);
				//ÿ����������ж�һ�Σ��Ƿ�����ʤ��
				if (Is_Winner(arr) != ' ') {
					ret = Is_Winner(arr);
					break;
				}
				Computer_Chess(arr);//��������
				ret = Is_Winner(arr);
			} while (ret == ' ');
			Print_Board(arr);
			if (ret == 'x') {
				printf("���ʤ��\n");
			}
			else if (ret == 'o') {
				printf("����ʤ��\n");
			}
			else if (ret == 'p') {
				printf("���壡��\n");
			}
		}
		else if (input == 2) {
			break;
		}
		else {
			printf("������������������\n");
			continue;
		}
	}
	system("pause");
	return 0;
}
