#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define X 3
#define Y 3
//创建并初始化棋盘
char arr[X][Y];
void Init_Board(char arr[X][Y]) {
	srand((unsigned)time(0));
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < Y; j++) {
			arr[i][j] = ' ';
		}
	}
}
//打印棋盘
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
//玩家落子
void Player_Chess(char arr[X][Y]) {
	int i = 0, j = 0;
	int retu=0;
	printf("请玩家落子，输入落子的位置，先输入横坐标：X，在输入纵坐标：Y，并中间用空格隔开\n");
	while (1) {
		retu=scanf("%d %d", &i, &j);//将scanf的返回值赋给retu
		//清空界面
		while (retu != 2) {//当retu不为2的时候循环开始
			while (getchar() != '\n');//清空输入缓冲区中的非法字符
			printf("输入有误，请重新输入\n");
			retu = scanf("%d %d", &i, &j);
		}
		while (getchar() != '\n');//无论输入啥都进行一次，清空缓冲区
		if ((i >= 0 && i < X) && (j >= 0 && j < Y)) {
			if (arr[i][j] == ' ') {
				arr[i][j] = 'x';
				break;
			}
			else {
				printf("该位置已有棋子，请你重新落子\n");
			}
		}
		else {
			printf("输入有误，请重新输入\n");
			//break;不能跳出
		}
	}
}
//电脑落子
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
//判断棋盘是否已满
//返回1为满，0为未满
int Is_full(char arr[X][Y]) {
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < Y; j++) {
			if (arr[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
//判断输赢
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
//开始或结束游戏
void Game_board() {
	printf("************************\n");
	printf("开始游戏：1**结束游戏：2\n");
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
			while (getchar() != '\n');//清空输入缓冲区中的非法字符
			printf("输入有误，请重新输入\n");
			retu = scanf("%d", &input);
		}
		if (input == 1) {
			Init_Board(arr);
			do {
				Print_Board(arr);//打印棋盘
				Player_Chess(arr);//玩家下棋
				Print_Board(arr);
				//每次下完棋后都判断一次，是否有人胜出
				if (Is_Winner(arr) != ' ') {
					ret = Is_Winner(arr);
					break;
				}
				Computer_Chess(arr);//电脑下棋
				ret = Is_Winner(arr);
			} while (ret == ' ');
			Print_Board(arr);
			if (ret == 'x') {
				printf("玩家胜！\n");
			}
			else if (ret == 'o') {
				printf("电脑胜！\n");
			}
			else if (ret == 'p') {
				printf("和棋！！\n");
			}
		}
		else if (input == 2) {
			break;
		}
		else {
			printf("输入有误，请重新输入\n");
			continue;
		}
	}
	system("pause");
	return 0;
}
