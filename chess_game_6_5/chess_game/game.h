#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define ROW 3        //棋盘行数
#define COL 3        //棋盘列数
#define CONDITION 3  //胜利条件

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/********************************************************
* 参数列表：char board[ROW][COL]——棋盘
*			int row, int col——棋盘行列
*			int pieceSite[2]——储存最后一个棋子位置的数组
*			int condition——胜利的条件（同线棋子的数量）
********************************************************/

//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);

//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);

//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col, int pieceSite[2]);

//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col, int pieceSite[2]);


//判断输赢
char Judge(char board[ROW][COL], int condition, int row, int col, int pieceSite[2]);