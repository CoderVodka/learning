#define  _CRT_SECURE_NO_WARNINGS

#include "mine_sweeper_game.h"

//��ʼ�����׵�ͼ
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

//��ʼ������
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

//���õ���
void SetMine(char mineMap[ROWS][COLS], int mine[MINE_NUMBER][2], int row, int col, int mineNumber)
{
	int count = 1;

	while (count <= mineNumber)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mineMap[x][y] == '0')
		{
			//�����׵�λ����Ϊ'1'
			mineMap[x][y] = '1';
			//��¼���׵�λ��
			mine[count - 1][0] = x;
			mine[count - 1][1] = y;
			count++;
		}
	}
}

//��ӡ���׵�ͼ��������
void DisplayMap(char mineMap[ROWS][COLS], int row, int col)
{
	int i = 1;

	//��ӡ�б��
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");

	for (i = 1; i <= row; i++)
	{
		//��ӡ�б��
		printf("%d ", i);
		int j = 1;

		for (j = 1; j <= col; j++)
		{
			printf("%c ", mineMap[i][j]);
		}

		printf("\n");
	}
}

//��ӡ�������꣬������
void DisplayMine(int mine[MINE_NUMBER][2], int mineNumber)
{
	int i = 0;
	for (i = 0; i < mineNumber; i++)
	{
		printf("(%d,%d)\n", mine[i][0], mine[i][1]);
	}
}


//��ӡ��Ϸ����
void DisplayGameBoard(char gameBoard[ROWS][COLS], int row, int col)
{
	int i = 1;

	//��ӡ�б��
	for (i = 0; i <= col; i++)
	{
		printf(" %d  ", i);
	}
	printf("\n");

	//��ӡ��һ�зָ���
	for (i = 0; i <= col; i++)
	{
		printf("---|");
	}
	printf("\n");

	//���д�ӡ
	for (i = 1; i <= row; i++)
	{
		//��ӡ�б��
		printf(" %d |", i);
		int j = 1;

		//��ӡһ��
		for (j = 1; j <= col; j++)
		{
			printf(" %c |", gameBoard[i][j]);
		}
		printf("\n");

		//��ӡ�м��
		for (j = 0; j <= col; j++)
		{
			printf("---|");
		}
		printf("\n");
	}
}

//��������ǵ���
void MarkMine(char gameBoard[ROWS][COLS], int x, int y, int* markCount)
{
	if (gameBoard[x][y] == '#')
	{
		gameBoard[x][y] = '!';
		(*markCount)++;
	}
	else if (gameBoard[x][y] == '!')
		printf("�����ѱ�ǻ��Ų�\n");
}

//������ȡ�����
void UnMarkMine(char gameBoard[ROWS][COLS], int x, int y, int* markCount)
{
	if (gameBoard[x][y] == '!')
	{
		gameBoard[x][y] = '#';
		(*markCount)--;
	}
	else
		printf("����δ��ǻ��ѱ��Ų�\n");
}

//�������Ų����
void Sweeper(char mineMap[ROWS][COLS], char gameBoard[ROWS][COLS], int x, int y, int* clearCount)
{
	//���겻������δ���Ų����ʱִ��
	if (mineMap[x][y] == '0' && gameBoard[x][y] == '#')
	{
		//������λ�õ�ֵ��Ϊ��Χ8����׵�����
		gameBoard[x][y] = mineMap[x - 1][y - 1] + mineMap[x - 1][y] + mineMap[x - 1][y + 1]
			+ mineMap[x][y - 1] + mineMap[x][y + 1]
			+ mineMap[x + 1][y - 1] + mineMap[x + 1][y] + mineMap[x + 1][y + 1] - 7 * '0';
		(*clearCount)++;

		//�����Χû�ף�����λ����Ϊ�ո�
		if (gameBoard[x][y] == '0')
		{
			gameBoard[x][y] = ' ';

			//�ݹ���չ��Χû���׵ĸ���
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

//��ʤ����������ȫ����ȷ���
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

//��ʤ���������ȫ��������
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

//ʧ���������ȵ�����
char GameOver(char mineMap[ROWS][COLS], char gameBoard[ROWS][COLS], 
	int mine[MINE_NUMBER][2], int x, int y, int mineNumber)
{
	if (mineMap[x][y] == '1')
	{
		//��ʾȫ������
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

//ɨ��ѡ��
char Action(char mineMap[ROWS][COLS], char gameBoard[ROWS][COLS], int mine[MINE_NUMBER][2],
	int row, int col, int mineNumber, int* markCount, int* clearCount)
{
	//��������
	printf("���������꣨�� �У���");
	int x = 0;
	int y = 0;
	do
	{
		scanf("%d %d", &x, &y);

		if (x < 1 || x > row || y < 1 || y > col)
			printf("��������������������룺");
	}while (x < 1 || x > row || y < 1 || y > col);

	//ѡ���ǵ��ס�ȡ����ǻ��Ų����
	printf("��ѡ��0.ȡ����ǣ�1.��ǵ��ף�2.�Ų����\n");
	int act = 0;

	do
	{
		scanf("%d", &act);

		switch (act)
		{
		case 0:
			printf("ȡ�����\n");
			UnMarkMine(gameBoard, x, y, markCount);
			return AllMineMarked(gameBoard, mine, mineNumber, markCount);
		case 1:
			printf("��ǵ���\n");
			MarkMine(gameBoard, x, y, markCount);
			return AllMineMarked(gameBoard, mine, mineNumber, markCount);
		case 2:
			printf("�Ų����\n");
			if (gameBoard[x][y] == '#')
			{
				//�ж��Ƿ�ը��
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
				printf("�����ѱ�ǻ��Ų�\n");
				return '#';
			}
		default:
			printf("�����������������\n");
			break;
		}
	} while (act != 0 && act != 1 && act != 2);

	return 0;
}


