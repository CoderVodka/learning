#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define ROW 3        //行数
#define COL 3        //列数
#define CONDITION 3  //胜利条件

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);

//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);

//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col, int pieceSite[]);

//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col, int pieceSite[]);


//判断输赢
char Judge(char board[ROW][COL], int condition, int row, int col, int pieceSite[]);