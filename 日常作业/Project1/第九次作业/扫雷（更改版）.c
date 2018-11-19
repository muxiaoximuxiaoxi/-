#pragma once
#define ROW 10
#define COL 10
#define mine_num 10
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//俩个数组，一个表示给玩家展示的地图（show_map)
//另一个表示雷阵（mine_map）
char show_map[ROW + 2][COL + 2];
char mine_map[ROW + 2][COL + 2];

//对这俩个地图进行初始化
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

//生成雷阵
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

//打印map
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

//计算（x,y）周围雷的个数
int Get_mine_num(char mine_map[ROW + 2][COL + 2],int row, int col) {
	int count = 0;
	//数字对应的ASCII值和数字字符对应的ASCII值相差48，即'0'的ASCII值
	//mine_map[row - 1][col - 1] - '0'  
	//若此位置有雷 则结果为 1 反之为 0
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

//展现功能
//如果知道该点周围无雷，则自动展开该点，同时在该点上标出其周围地雷的数量
void  Open_mine(int row, int col) {
	if (mine_map[row-1][col-1] == '0') {
		show_map[row-1][col-1] = Get_mine_num(mine_map, row-1, col-1) + '0';
		//显示该坐标周围的雷数
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

//计算当前剩余'*'的数量
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
//扫雷
int Sweep_mine(char show_map[ROW + 2][COL + 2],
	char mine_map[ROW + 2][COL + 2]) {
	int x=0, y=0,ret=0,ret1=0,ret2=0;
	int num = 0;
	Init(show_map, mine_map);
	Make_mine(mine_map);
	Display_map(show_map);
	while (1) {
		printf("请输入你认为没有雷的地方：\n");
		ret = scanf("%d %d", &x, &y);
		while (ret != 2) {
			while (getchar() != '\n');
			printf("输入有误，请重新输入：\n");
			ret = scanf("%d %d", &x, &y);
		}
		while (getchar() != '\n');
		if ((x >= 1 && x <= 10) && (y >= 1 && y <= 10)) {
			if(mine_map[x][y] == '1') {
				return 1;//表示踩到雷
			}
			else {
				ret1 = Get_mine_num(mine_map, x, y);
				show_map[x][y] = ret1 + '0';
				Open_mine(x, y);
				Display_map(show_map);
				num = count_show_mine(show_map);
				if (ROW*COL-num == mine_num) {
					return 0;//表示玩家胜利
				}
			}
		}
		else {
			printf("输入有误，请重新输入：\n");
			//continue;可有可无
		}
	}
}
//开始或结束游戏
void Game_mine() {
	printf("************************\n");
	printf("开始游戏：1**结束游戏：2\n");
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
			printf("输入有误，请重新输入：\n");
			ret = scanf("%d", &input);
		}
		while (getchar() != '\n');
		if (input == 1) {
			ret=Sweep_mine(show_map, mine_map);
			if (ret == 1) {
				printf("你踩雷了，游戏结束！！！\n");
				Display_map(mine_map);
			}
			else if (ret == 0) {
				printf("恭喜玩家胜利！！！\n");
				Display_map(mine_map);
			}
			//break;
		}
		else if (input == 2) {
			break;
		}
		else {
			printf("输入有误，请重新输入：\n");
			continue;
		}
		system("pause");
	}
}
