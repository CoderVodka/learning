#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

//�˵�
void Menu()
{
	printf("**********************\n");
	printf("********1.play********\n");
	printf("********2.exit********\n");
	printf("**********************\n");
	printf("������1/2ѡ��ʼ���˳���\n");
}

//��Ϸ
void Game()
{
	char board[ROW][COL] = { 0 };  //����
	int latestPiece[2] = { 0 };    //��������µ�һ�����ӵ�����
	char judgement = ' ';

	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ӡ����
	DisplayBoard(board, ROW, COL);

	while (judgement == ' ')
	{
		//�������
		printf("�������\n");
		printf("���������꣨�У��У���");
		PlayerMove(board, ROW, COL, latestPiece);
		DisplayBoard(board, ROW, COL);
		//�ж�ʤ��
		judgement = Judge(board, CONDITION, ROW, COL, latestPiece);
		if (judgement != ' ')
			break;

		//��������
		printf("��������\n");
		ComputerMove(board, ROW, COL, latestPiece);
		DisplayBoard(board, ROW, COL);
		judgement = Judge(board, CONDITION, ROW, COL, latestPiece);
	}

	switch (judgement)
	{
	case '*':
		printf("���ʤ��\n");
		break;
	case '#':
		printf("����ʤ��\n");
		break;
	case 'd':
		printf("ƽ��\n");
		break;
	}
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	
	do
	{
		//��ӡ�˵�
		Menu();
		//ѡ��ʼ���˳�
		scanf("%d", &input);
			
		switch(input)   //����ʹ��switch����࣬һ��ʼʹ�õ�if�������߳���������
		{ 
		case 1:
			printf("��ʼ��Ϸ\n");
			Game();
			break;
		case 2:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("����������������룺");
			break;
		}
	} while (input != 2);
	
	return 0;
}