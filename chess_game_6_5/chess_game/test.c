#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

//菜单
void Menu()
{
	printf("**********************\n");
	printf("********1.play********\n");
	printf("********2.exit********\n");
	printf("**********************\n");
	printf("请输入1/2选择开始或退出：\n");
}

//游戏
void Game()
{
	char board[ROW][COL] = { 0 };  //棋盘
	int latestPiece[2] = { 0 };    //储存最近下的一颗棋子的坐标
	char judgement = ' ';

	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);

	while (judgement == ' ')
	{
		//玩家下棋
		printf("玩家下棋\n");
		printf("请输入坐标（行，列）：");
		PlayerMove(board, ROW, COL, latestPiece);
		DisplayBoard(board, ROW, COL);
		//判断胜负
		judgement = Judge(board, CONDITION, ROW, COL, latestPiece);
		if (judgement != ' ')
			break;

		//电脑下棋
		printf("电脑下棋\n");
		ComputerMove(board, ROW, COL, latestPiece);
		DisplayBoard(board, ROW, COL);
		judgement = Judge(board, CONDITION, ROW, COL, latestPiece);
	}

	switch (judgement)
	{
	case '*':
		printf("玩家胜利\n");
		break;
	case '#':
		printf("电脑胜利\n");
		break;
	case 'd':
		printf("平局\n");
		break;
	}
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	
	do
	{
		//打印菜单
		Menu();
		//选择开始或退出
		scanf("%d", &input);
			
		switch(input)   //这里使用switch更简洁，一开始使用的if，代码冗长不够清晰
		{ 
		case 1:
			printf("开始游戏\n");
			Game();
			break;
		case 2:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入：");
			break;
		}
	} while (input != 2);
	
	return 0;
}