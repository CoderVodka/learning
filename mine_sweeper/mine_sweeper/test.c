#define  _CRT_SECURE_NO_WARNINGS

#include<time.h>
#include "mine_sweeper_game.h"

//菜单
void Menu()
{
	printf("**********************\n");
	printf("********1.play********\n");
	printf("********0.exit********\n");
	printf("**********************\n");
	printf("请输入1/0选择开始或退出：\n");
}

//扫雷游戏
void MineSweeper()
{
	char judgement = '#';  //判断胜利的参数
	char map[ROWS][COLS] = { 0 };     //布雷地图所用的数组
	int mine[MINE_NUMBER][2] = { 0 }; //储存地雷的坐标
	int markNumber = 0;               //统计标记地雷数量
	int clearNumber = 0;              //统计清除区域的数量
	char board[ROWS][COLS] = { 0 };   //显示界面所用的数组
	//初始化地雷图并布置地雷
	InitMineMap(map, ROWS, COLS);
	SetMine(map, mine, ROW, COL, MINE_NUMBER);
	DisplayMap(map, ROW, COL);
	//初始化界面并打印
	InitGameBoard(board, ROW, COL);
	DisplayGameBoard(board, ROW, COL);

	while(judgement == '#')
	{
		judgement = Action(map, board, mine, ROW, COL, MINE_NUMBER, &markNumber, &clearNumber);
		DisplayGameBoard(board, ROW, COL);
	}

	if (judgement == '!')
		printf("标记全部地雷，获胜\n");
	else if (judgement == '*')
		printf("清除全部非雷区，获胜\n");
	else if (judgement == 'B')
		printf("Game Over\n");
}


int main()
{
	int input = 1;
	srand((unsigned int)time(NULL));

	while (input)
	{
		Menu();
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			printf("开始游戏\n");
			MineSweeper();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	}

	return 0;
}