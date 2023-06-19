#pragma once

#include<stdio.h>
#include<stdlib.h>

#define ROW 9           //��Ϸ���� �� �������׵����� ������
#define COL 9

#define ROWS ROW + 2    //���ж���Χ�����������ݹ�չ����Χû���׵ĸ���ʱ����ΪҪ��������Χ8�����ӽ��в�����
#define COLS COL + 2    //��˴���Խ��Ŀ��ܣ���ˣ�����Χ����һȦ�������������ֹԽ�硣

#define MINE_NUMBER 2

/*****************************************************************************************************
* �����б�char mineMap[ROWS][COLS]�������ڲ��õ���
*			char gameBoard[ROWS][COLS]����չʾ����Ϸ����
*			int mine[MINE_NUMBER][2]��������ÿ�����׵��������꣬�Զ�ά�������ʽ��ţ�ÿ��Ϊһ������
*			int rows, int cols�������׵�ͼ�������Ϸ���������ʵ������
*			int row, int col�������׵�ͼ�����е��׵���������У�����Ϸ����չʾ������
*			int x, int y����ÿ��ɨ�ײ���������
*			int mineNumber������������
*			int* markCount������¼��ǵ��׵������������ж�ͨ�����ȫ�����׻��ʤ��
*			int* clearCount������¼��ɨ��������������������ж�ͨ����ɨȫ�����������ʤ��
******************************************************************************************************/

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

//��ӡ��Ϸ����
void DisplayGameBoard(char gameBoard[ROWS][COLS], int row, int col);

//��������ǵ���
void MarkMine(char gameBoard[ROWS][COLS], int x, int y, int* markCount);

//������ȡ�����
void UnMarkMine(char gameBoard[ROWS][COLS], int x, int y, int* markCount);

//�������Ų����
void Sweeper(char mineMap[ROWS][COLS], char gameBoard[ROWS][COLS], int x, int y, int* clearCount);

//��ʤ����������ȫ����ȷ���
char AllMineMarked(char gameBoard[ROWS][COLS], int mine[MINE_NUMBER][2], int mineNumber, int* markCount);

//��ʤ���������ȫ��������
char ClearAllField(char gameBoard[ROWS][COLS], int mine[MINE_NUMBER][2],
	int mineNumber, int row, int col, int* clearCount);

//ʧ���������ȵ�����
char GameOver(char mineMap[ROWS][COLS], char gameBoard[ROWS][COLS],
	int mine[MINE_NUMBER][2], int x, int y, int mineNumber);

//ɨ��
char Action(char mineMap[ROWS][COLS], char gameBoard[ROWS][COLS], int mine[MINE_NUMBER][2],
	int row, int col, int mineNumber, int* markCount, int* clearCount);