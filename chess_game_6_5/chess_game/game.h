#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define ROW 3        //����
#define COL 3        //����
#define CONDITION 3  //ʤ������

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//��ʼ������
void InitBoard(char board[ROW][COL], int row, int col);

//��ӡ����
void DisplayBoard(char board[ROW][COL], int row, int col);

//�������
void PlayerMove(char board[ROW][COL], int row, int col, int pieceSite[]);

//��������
void ComputerMove(char board[ROW][COL], int row, int col, int pieceSite[]);


//�ж���Ӯ
char Judge(char board[ROW][COL], int condition, int row, int col, int pieceSite[]);