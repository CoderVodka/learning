#define  _CRT_SECURE_NO_WARNINGS

#include "mine_sweeper_game.h"

//初始化地雷地图
void InitMineMap(char mineMap[ROWS][COLS], int rows, int cols)
{
	int i = 0;

	for (i = 0; i < rows; i++)
	{
		int j = 0;

		for (j = 0; j < cols; j++)
		{
			mineMap[i][j] = '0';
		}
	}
}

//初始化界面
void InitGameBoard(char gameBoard[ROWS][COLS], int row, int col)
{
	int i = 1;

	for (i = 1; i <= row; i++)
	{
		int j = 1;

		for (j = 1; j <= col; j++)
		{
			gameBoard[i][j] = '#';
		}
	}
}

//布置地雷
void SetMine(char mineMap[ROWS][COLS], int mine[MINE_NUMBER][2], int row, int col, int mineNumber)
{
	int count = 1;

	while (count <= mineNumber)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mineMap[x][y] == '0')
		{
			//将布雷的位置设为'1'
			mineMap[x][y] = '1';
			//记录布雷的位置
			mine[count - 1][0] = x;
			mine[count - 1][1] = y;
			count++;
		}
	}
}

//打印地雷地图，测试用
void DisplayMap(char mineMap[ROWS][COLS], int row, int col)
{
	int i = 1;

	//打印列编号
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");

	for (i = 1; i <= row; i++)
	{
		//打印行编号
		printf("%d ", i);
		int j = 1;

		for (j = 1; j <= col; j++)
		{
			printf("%c ", mineMap[i][j]);
		}

		printf("\n");
	}
}

//打印地雷坐标，测试用
void DisplayMine(int mine[MINE_NUMBER][2], int mineNumber)
{
	int i = 0;
	for (i = 0; i < mineNumber; i++)
	{
		printf("(%d,%d)\n", mine[i][0], mine[i][1]);
	}
}


//打印游戏界面
void DisplayGameBoard(char gameBoard[ROWS][COLS], int row, int col)
{
	int i = 1;

	//打印列编号
	for (i = 0; i <= col; i++)
	{
		printf(" %d  ", i);
	}
	printf("\n");

	//打印第一行分割线
	for (i = 0; i <= col; i++)
	{
		printf("---|");
	}
	printf("\n");

	//逐行打印
	for (i = 1; i <= row; i++)
	{
		//打印行编号
		printf(" %d |", i);
		int j = 1;

		//打印一行
		for (j = 1; j <= col; j++)
		{
			printf(" %c |", gameBoard[i][j]);
		}
		printf("\n");

		//打印行间隔
		for (j = 0; j <= col; j++)
		{
			printf("---|");
		}
		printf("\n");
	}
}

//操作：标记地雷
void MarkMine(char gameBoard[ROWS][COLS], int x, int y, int* markCount)
{
	if (gameBoard[x][y] == '#')
	{
		gameBoard[x][y] = '!';
		(*markCount)++;
	}
	else if (gameBoard[x][y] == '!')
		printf("坐标已标记或排查\n");
}

//操作：取消标记
void UnMarkMine(char gameBoard[ROWS][COLS], int x, int y, int* markCount)
{
	if (gameBoard[x][y] == '!')
	{
		gameBoard[x][y] = '#';
		(*markCount)--;
	}
	else
		printf("坐标未标记或已被排查\n");
}

//操作：排查地雷
void Sweeper(char mineMap[ROWS][COLS], char gameBoard[ROWS][COLS], int x, int y, int* clearCount)
{
	//坐标不是雷且未被排查或标记时执行
	if (mineMap[x][y] == '0' && gameBoard[x][y] == '#')
	{
		//将坐标位置的值改为周围8格地雷的数量
		gameBoard[x][y] = mineMap[x - 1][y - 1] + mineMap[x - 1][y] + mineMap[x - 1][y + 1]
			+ mineMap[x][y - 1] + mineMap[x][y + 1]
			+ mineMap[x + 1][y - 1] + mineMap[x + 1][y] + mineMap[x + 1][y + 1] - 7 * '0';
		(*clearCount)++;

		//如果周围没雷，将该位置设为空格
		if (gameBoard[x][y] == '0')
		{
			gameBoard[x][y] = ' ';

			//递归扩展周围没有雷的格子
			Sweeper(mineMap, gameBoard, x - 1, y - 1, clearCount);
			Sweeper(mineMap, gameBoard, x - 1, y, clearCount);
			Sweeper(mineMap, gameBoard, x - 1, y + 1, clearCount);
			Sweeper(mineMap, gameBoard, x, y - 1, clearCount);
			Sweeper(mineMap, gameBoard, x, y + 1, clearCount);
			Sweeper(mineMap, gameBoard, x + 1, y - 1, clearCount);
			Sweeper(mineMap, gameBoard, x + 1, y, clearCount);
			Sweeper(mineMap, gameBoard, x + 1, y + 1, clearCount);
		}
	}
}

//获胜条件：地雷全部正确标记
char AllMineMarked(char gameBoard[ROWS][COLS], int mine[MINE_NUMBER][2], int mineNumber, int* markCount)
{
	int i = 0;
	int count = 0;
	
	if ((*markCount) == mineNumber)
	{
		for (i = 0; i < mineNumber; i++)
		{
			if (gameBoard[mine[i][0]][mine[i][1]] == '!')
				count++;
		}
	}

	if (count == mineNumber)
		return '!';
	else
		return '#';
}

//获胜条件：清除全部非雷区
char ClearAllField(char gameBoard[ROWS][COLS], int mine[MINE_NUMBER][2], 
	int mineNumber, int row, int col, int* clearCount)
{
	if ((*clearCount) == (row * col - mineNumber))
	{
		int i = 0;

		for (i = 0; i < mineNumber; i++)
		{
			gameBoard[mine[i][0]][mine[i][1]] = '*';
		}

		return '*';
	}
	else
		return '#';
}

//失败条件：踩到地雷
char GameOver(char mineMap[ROWS][COLS], char gameBoard[ROWS][COLS], 
	int mine[MINE_NUMBER][2], int x, int y, int mineNumber)
{
	if (mineMap[x][y] == '1')
	{
		//显示全部地雷
		int i = 0;
		for (i = 0; i < mineNumber; i++)
		{
			gameBoard[mine[i][0]][mine[i][1]] = 'B';
		}
		return 'B';
	}
	else
		return '#';
}

//扫雷选项
char Action(char mineMap[ROWS][COLS], char gameBoard[ROWS][COLS], int mine[MINE_NUMBER][2],
	int row, int col, int mineNumber, int* markCount, int* clearCount)
{
	//输入坐标
	printf("请输入坐标（行 列）：");
	int x = 0;
	int y = 0;
	do
	{
		scanf("%d %d", &x, &y);

		if (x < 1 || x > row || y < 1 || y > col)
			printf("输入坐标错误，请重新输入：");
	}while (x < 1 || x > row || y < 1 || y > col);

	//选择标记地雷、取消标记或排查地雷
	printf("请选择：0.取消标记；1.标记地雷；2.排查地雷\n");
	int act = 0;

	do
	{
		scanf("%d", &act);

		switch (act)
		{
		case 0:
			printf("取消标记\n");
			UnMarkMine(gameBoard, x, y, markCount);
			return AllMineMarked(gameBoard, mine, mineNumber, markCount);
		case 1:
			printf("标记地雷\n");
			MarkMine(gameBoard, x, y, markCount);
			return AllMineMarked(gameBoard, mine, mineNumber, markCount);
		case 2:
			printf("排查地雷\n");
			if (gameBoard[x][y] == '#')
			{
				//判断是否炸死
				if (mineMap[x][y] == '1')
					return GameOver(mineMap, gameBoard, mine, x, y, mineNumber);
				else
				{
					Sweeper(mineMap, gameBoard, x, y, clearCount);
					return ClearAllField(gameBoard, mine, mineNumber, row, col, clearCount);
				}
			}
			else
			{
				printf("坐标已标记或排查\n");
				return '#';
			}
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (act != 0 && act != 1 && act != 2);

	return 0;
}


