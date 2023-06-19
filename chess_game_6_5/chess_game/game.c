#include "game.h"

#define _CRT_SECURE_NO_WARNINGS


//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	
	for (i = 0; i < row; i++)
	{
		int j = 0;

		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	// B | B | B      每行以这种形式打印，B代表数组内对应行列的元素
	//---|---|---     两行之间打印分割线
	for (i = 0; i < row; i++)
	{
		int j = 0;
		//打印一行
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);

			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");

		//打印分割线
		for (j = 0; j < col; j++)
		{
			printf("---");

			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
	}
}

//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col, int pieceSite[2])
{
	while (1)
	{
		int y = 0;
		int x = 0;
		scanf("%d %d", &y, &x);

		if (y > 0 && y <= row && x > 0 && x <= col)
		{
			if (board[y - 1][x - 1] == ' ')
			{
				board[y - 1][x - 1] = '*';
				pieceSite[0] = y - 1;
				pieceSite[1] = x - 1;
				break;
			}
			else
			{
				printf("当前格子已有棋子，请重新输入：");
			}
		}
		else
		{
			printf("输入有误，请重新输入：");
		}
	}
}

//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col, int pieceSite[2])
{
	while (1)
	{
		int y = rand() % ROW;
		int x = rand() % COL;

		if (board[y][x] == ' ')
		{
			board[y][x] = '#';
			pieceSite[0] = y;
			pieceSite[1] = x;
			break;
		}
	}
}

//判断输赢
char Judge(char board[ROW][COL], int condition, int row, int col, int pieceSite[2])  //condition是胜利条件，pieceSite[]是最近下的一颗棋子的坐标
{
	int x = 0;
	int y = 0;
	int z = 0;
	int count = 1;

	//横向判断
	//向右寻找相邻同色棋子
	for (x = 1; pieceSite[1] + x < col; x++)  //目标坐标不超过边界时进入循环
	{
		if (board[pieceSite[0]][pieceSite[1]] == board[pieceSite[0]][pieceSite[1] + x])  //比较两个坐标的棋子
		{
			count++;

			if (count == condition)
				return board[pieceSite[0]][pieceSite[1]];
		}
		else
			break;

	}

	//向左寻找相邻同色棋子
	for (x = 1; pieceSite[1] - x >= 0; x++)
	{
		if (board[pieceSite[0]][pieceSite[1]] == board[pieceSite[0]][pieceSite[1] - x])
		{
			count++;

			if (count == condition)
				return board[pieceSite[0]][pieceSite[1]];
		}
		else
			break;
	}

	//重置计数器
	count = 1;

	//纵向判断
	//向下寻找相邻同色棋子
	for (y = 1; pieceSite[0] + y < row; y++)
	{
		if (board[pieceSite[0]][pieceSite[1]] == board[pieceSite[0] + y][pieceSite[1]])
		{
			count++;

			if (count == condition)
				return board[pieceSite[0]][pieceSite[1]];
		}
		else
			break;

	}

	//向上寻找相邻同色棋子
	for (x = 1; pieceSite[0] - y >= 0; y++)
	{
		if (board[pieceSite[0]][pieceSite[1]] == board[pieceSite[0] - y][pieceSite[1]])
		{
			count++;

			if (count == condition)
				return board[pieceSite[0]][pieceSite[1]];
		}
		else
			break;
	}

	count = 1;

	//左上-右下斜向对比
	//向右下寻找相邻同色棋子
	for (y = 1, x = 1; (pieceSite[0] + y < row) && (pieceSite[1] + x < col); y++, x++)
	{
		if (board[pieceSite[0]][pieceSite[1]] == board[pieceSite[0] + y][pieceSite[1] + x])
		{
			count++;

			if (count == condition)
				return board[pieceSite[0]][pieceSite[1]];
		}
		else
			break;

	}

	//向左上寻找相邻同色棋子
	for (y = 1, x = 1; (pieceSite[0] - y >= 0) && (pieceSite[1] - x >= 0); y++, x++)
	{
		if (board[pieceSite[0]][pieceSite[1]] == board[pieceSite[0] - y][pieceSite[1] - x])
		{
			count++;

			if (count == condition)
				return board[pieceSite[0]][pieceSite[1]];
		}
		else
			break;
	}

	count = 1;

	//左下-右上斜向对比
	//向右上寻找相邻同色棋子
	for (y = 1, x = 1; (pieceSite[0] - y >= 0) && (pieceSite[1] + x < col); y++, x++)
	{
		if (board[pieceSite[0]][pieceSite[1]] == board[pieceSite[0] - y][pieceSite[1] + x])
		{
			count++;

			if (count == condition)
				return board[pieceSite[0]][pieceSite[1]];
		}
		else
			break;

	}

	//向左下寻找相邻同色棋子
	for (y = 1, x = 1; (pieceSite[0] + y < row) && (pieceSite[1] - x >= 0); y++, x++)
	{
		if (board[pieceSite[0]][pieceSite[1]] == board[pieceSite[0] + y][pieceSite[1] - x])
		{
			count++;

			if (count == condition)
				return board[pieceSite[0]][pieceSite[1]];
		}
		else
			break;
	}


	//判断平局
	for (y = 0; y < row; y++)
	{
		for (x = 0; x < col; x++)
		{
			if (board[y][x] == ' ')  //判断是否有空格
			{
				return ' ';
			}
		}
	}

	return 'd';
}
