#pragma once
#define ROW 10
#define COL 10
#define mine_num 10
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//�������飬һ����ʾ�����չʾ�ĵ�ͼ��show_map)
//��һ����ʾ����mine_map��
char show_map[ROW + 2][COL + 2];
char mine_map[ROW + 2][COL + 2];

//����������ͼ���г�ʼ��
void Init(char show_map[ROW + 2][COL + 2],
	      char mine_map[ROW + 2][COL + 2]) {
	srand((unsigned)time(0));
	for (int row = 0;row < ROW+2;++row) {
		for (int col = 0;col < COL+2;++col) {
			show_map[row][col] = '*';
		}
	}
	for (int row = 0;row < ROW+2;++row) {
		for (int col = 0;col < COL+2;++col) {
			mine_map[row][col]='0';
		}
	}
}

//��������
void Make_mine(char mine_map[ROW + 2][COL + 2]) {
	int num = mine_num;
	while (num > 0) {
		int row = rand() % mine_num + 1;
		int col = rand() % mine_num + 1;
		if (mine_map[row][col] == '1') {
			continue;
		}
		mine_map[row][col] = '1';
		--num;
	}
}

//��ӡmap
void Display_map(char show_map[ROW + 2][COL + 2]) {
	printf("================================\n");
	for (int i = 0;i < ROW+1;++i) {
		printf("%02d ", i);
	}
	printf("\n");
	printf("\n");
	for (int row = 1;row < ROW + 1;++row) {
		printf("%02d|", row);
		for (int col = 1;col < COL + 1;++col) {
			printf("%2c ", show_map[row][col]);
		}
		printf("\n");
	}
	printf("================================\n");
	printf("\n");
}

//���㣨x,y����Χ�׵ĸ���
int Get_mine_num(char mine_map[ROW + 2][COL + 2],int row, int col) {
	int count = 0;
	//���ֶ�Ӧ��ASCIIֵ�������ַ���Ӧ��ASCIIֵ���48����'0'��ASCIIֵ
	//mine_map[row - 1][col - 1] - '0'  
	//����λ������ ����Ϊ 1 ��֮Ϊ 0
	count = (mine_map[row - 1][col - 1] - '0')
		  + (mine_map[row - 1][col] - '0')
		  + (mine_map[row - 1][col + 1] - '0')
		  + (mine_map[row][col - 1] - '0')
		  + (mine_map[row][col] - '0')
		  + (mine_map[row][col + 1] - '0')
		  + (mine_map[row + 1][col - 1] - '0')
		  + (mine_map[row + 1][col] - '0')
		  + (mine_map[row + 1][col + 1] - '0');
	return count;
}

//չ�ֹ���
//���֪���õ���Χ���ף����Զ�չ���õ㣬ͬʱ�ڸõ��ϱ������Χ���׵�����
void  Open_mine(int row, int col) {
	if (mine_map[row-1][col-1] == '0') {
		show_map[row-1][col-1] = Get_mine_num(mine_map, row-1, col-1) + '0';
		//��ʾ��������Χ������
	}
	if (mine_map[row-1][col] == '0') {
		show_map[row-1][col] = Get_mine_num(mine_map, row-1, col) + '0';
	}
	if (mine_map[row-1][col+1] == '0') {
		show_map[row-1][col+1] = Get_mine_num(mine_map, row-1, col+1) + '0';
	}
	if (mine_map[row][col-1] == '0') {
		show_map[row][col-1] = Get_mine_num(mine_map, row, col-1) + '0';
	}
	if (mine_map[row][col+1] == '0') {
		show_map[row][col+1] = Get_mine_num(mine_map, row, col+1) + '0';
	}
	if (mine_map[row+1][col-1] == '0') {
		show_map[row+1][col-1] = Get_mine_num(mine_map, row+1, col-1) + '0';
	}
	if (mine_map[row+1][col] == '0') {
		show_map[row+1][col] = Get_mine_num(mine_map, row+1, col) + '0';
	}
	if (mine_map[row+1][col+1] == '0') {
		show_map[row+1][col+1] = Get_mine_num(mine_map, row+1, col+1) + '0';
	}
}

//���㵱ǰʣ��'*'������
int count_show_mine(char show_map[ROW + 2][COL + 2]) {
	int count = 0;
	for (int row = 1;row < ROW + 1;++row) {
		for (int col = 1;col < COL + 1;++col) {
			if (show_map[row][col] != '*')
				++count;
		}
	}
	return count;
}
//ɨ��
int Sweep_mine(char show_map[ROW + 2][COL + 2],
	char mine_map[ROW + 2][COL + 2]) {
	int x=0, y=0,ret=0,ret1=0,ret2=0;
	int num = 0;
	Init(show_map, mine_map);
	Make_mine(mine_map);
	Display_map(show_map);
	while (1) {
		printf("����������Ϊû���׵ĵط���\n");
		ret = scanf("%d %d", &x, &y);
		while (ret != 2) {
			while (getchar() != '\n');
			printf("�����������������룺\n");
			ret = scanf("%d %d", &x, &y);
		}
		while (getchar() != '\n');
		if ((x >= 1 && x <= 10) && (y >= 1 && y <= 10)) {
			if(mine_map[x][y] == '1') {
				return 1;//��ʾ�ȵ���
			}
			else {
				ret1 = Get_mine_num(mine_map, x, y);
				show_map[x][y] = ret1 + '0';
				Open_mine(x, y);
				Display_map(show_map);
				num = count_show_mine(show_map);
				if (ROW*COL-num == mine_num) {
					return 0;//��ʾ���ʤ��
				}
			}
		}
		else {
			printf("�����������������룺\n");
			//continue;���п���
		}
	}
}
//��ʼ�������Ϸ
void Game_mine() {
	printf("************************\n");
	printf("��ʼ��Ϸ��1**������Ϸ��2\n");
	printf("************************\n");
}
int main() {
	int input = 1;
	int ret = 0;
	while (input) {
		Game_mine();
		ret = scanf("%d", &input);
		while (ret != 1) {
			while (getchar() != '\n');
			printf("�����������������룺\n");
			ret = scanf("%d", &input);
		}
		while (getchar() != '\n');
		if (input == 1) {
			ret=Sweep_mine(show_map, mine_map);
			if (ret == 1) {
				printf("������ˣ���Ϸ����������\n");
				Display_map(mine_map);
			}
			else if (ret == 0) {
				printf("��ϲ���ʤ��������\n");
				Display_map(mine_map);
			}
			//break;
		}
		else if (input == 2) {
			break;
		}
		else {
			printf("�����������������룺\n");
			continue;
		}
		system("pause");
	}
}
