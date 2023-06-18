#define  _CRT_SECURE_NO_WARNINGS

#include<time.h>
#include "mine_sweeper_game.h"

//�˵�
void Menu()
{
	printf("**********************\n");
	printf("********1.play********\n");
	printf("********0.exit********\n");
	printf("**********************\n");
	printf("������1/0ѡ��ʼ���˳���\n");
}

//ɨ����Ϸ
void MineSweeper()
{
	char judgement = '#';  //�ж�ʤ���Ĳ���
	char map[ROWS][COLS] = { 0 };     //���׵�ͼ���õ�����
	int mine[MINE_NUMBER][2] = { 0 }; //������׵�����
	int markNumber = 0;               //ͳ�Ʊ�ǵ�������
	int clearNumber = 0;              //ͳ��������������
	char board[ROWS][COLS] = { 0 };   //��ʾ�������õ�����
	//��ʼ������ͼ�����õ���
	InitMineMap(map, ROWS, COLS);
	SetMine(map, mine, ROW, COL, MINE_NUMBER);
	DisplayMap(map, ROW, COL);
	//��ʼ�����沢��ӡ
	InitGameBoard(board, ROW, COL);
	DisplayGameBoard(board, ROW, COL);

	while(judgement == '#')
	{
		judgement = Action(map, board, mine, ROW, COL, MINE_NUMBER, &markNumber, &clearNumber);
		DisplayGameBoard(board, ROW, COL);
	}

	if (judgement == '!')
		printf("���ȫ�����ף���ʤ\n");
	else if (judgement == '*')
		printf("���ȫ������������ʤ\n");
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
			printf("��ʼ��Ϸ\n");
			MineSweeper();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	}

	return 0;
}