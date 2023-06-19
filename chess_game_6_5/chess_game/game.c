#include "game.h"

#define _CRT_SECURE_NO_WARNINGS


//��ʼ������
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

//��ӡ����
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	// B | B | B      ÿ����������ʽ��ӡ��B���������ڶ�Ӧ���е�Ԫ��
	//---|---|---     ����֮���ӡ�ָ���
	for (i = 0; i < row; i++)
	{
		int j = 0;
		//��ӡһ��
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);

			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");

		//��ӡ�ָ���
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

//�������
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
				printf("��ǰ�����������ӣ����������룺");
			}
		}
		else
		{
			printf("�����������������룺");
		}
	}
}

//��������
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

//�ж���Ӯ
char Judge(char board[ROW][COL], int condition, int row, int col, int pieceSite[2])  //condition��ʤ��������pieceSite[]������µ�һ�����ӵ�����
{
	int x = 0;
	int y = 0;
	int z = 0;
	int count = 1;

	//�����ж�
	//����Ѱ������ͬɫ����
	for (x = 1; pieceSite[1] + x < col; x++)  //Ŀ�����겻�����߽�ʱ����ѭ��
	{
		if (board[pieceSite[0]][pieceSite[1]] == board[pieceSite[0]][pieceSite[1] + x])  //�Ƚ��������������
		{
			count++;

			if (count == condition)
				return board[pieceSite[0]][pieceSite[1]];
		}
		else
			break;

	}

	//����Ѱ������ͬɫ����
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

	//���ü�����
	count = 1;

	//�����ж�
	//����Ѱ������ͬɫ����
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

	//����Ѱ������ͬɫ����
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

	//����-����б��Ա�
	//������Ѱ������ͬɫ����
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

	//������Ѱ������ͬɫ����
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

	//����-����б��Ա�
	//������Ѱ������ͬɫ����
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

	//������Ѱ������ͬɫ����
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


	//�ж�ƽ��
	for (y = 0; y < row; y++)
	{
		for (x = 0; x < col; x++)
		{
			if (board[y][x] == ' ')  //�ж��Ƿ��пո�
			{
				return ' ';
			}
		}
	}

	return 'd';
}
