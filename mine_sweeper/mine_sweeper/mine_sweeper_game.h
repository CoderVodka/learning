#pragma once

#include<stdio.h>
#include<stdlib.h>

#define ROW 9
#define COL 9

#define ROWS ROW + 2
#define COLS COL + 2

#define MINE_NUMBER 2

//��ʼ�����׵�ͼ
void InitMineMap(char mineMap[ROWS][COLS], int rows, int cols);

//��ʼ������
void InitGameBoard(char gameBoard[ROWS][COLS], int row, int col);

//���õ���
void SetMine(char mineMap[ROWS][COLS], int mine[MINE_NUMBER][2], int row, int col, int mineNumber);

//��ӡ���׵�ͼ��������
void DisplayMap(char mineMap[ROWS][COLS], int row, int col);

//��ӡ�������꣬������
void DisplayMine(int mine[MINE_NUMBER][2], int mineNumber);

//��ӡ����
void DisplayGameBoard(char gameBoard[ROWS][COLS], int row, int col);

//��ǵ���
void MarkMine(char gameBoard[ROWS][COLS], int x, int y, int* markCount);

//ȡ�����
void UnMarkMine(char gameBoard[ROWS][COLS], int x, int y, int* markCount);

//�Ų����
void Sweeper(char mineMap[ROWS][COLS], char gameBoard[ROWS][COLS], int x, int y, int* clearCount);

//��ʤ����������ȫ����ȷ���
char AllMineMarked(char gameBoard[ROWS][COLS], int mine[MINE_NUMBER][2], int mineNumber, int* markCount);

//��ʤ���������ȫ��������
char ClearAllField(char gameBoard[ROWS][COLS], int mine[MINE_NUMBER][2],
	int mineNumber, int row, int col, int* clearCount);

//ɨ���ж�
char GameOver(char mineMap[ROWS][COLS], char gameBoard[ROWS][COLS],
	int mine[MINE_NUMBER][2], int x, int y, int mineNumber);

//ɨ��
char Action(char mineMap[ROWS][COLS], char gameBoard[ROWS][COLS], int mine[MINE_NUMBER][2],
	int row, int col, int mineNumber, int* markCount, int* clearCount);