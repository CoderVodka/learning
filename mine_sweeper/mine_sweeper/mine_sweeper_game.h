#pragma once

#include<stdio.h>
#include<stdlib.h>

#define ROW 9
#define COL 9

#define ROWS ROW + 2
#define COLS COL + 2

#define MINE_NUMBER 2

//初始化地雷地图
void InitMineMap(char mineMap[ROWS][COLS], int rows, int cols);

//初始化界面
void InitGameBoard(char gameBoard[ROWS][COLS], int row, int col);

//布置地雷
void SetMine(char mineMap[ROWS][COLS], int mine[MINE_NUMBER][2], int row, int col, int mineNumber);

//打印地雷地图，测试用
void DisplayMap(char mineMap[ROWS][COLS], int row, int col);

//打印地雷坐标，测试用
void DisplayMine(int mine[MINE_NUMBER][2], int mineNumber);

//打印界面
void DisplayGameBoard(char gameBoard[ROWS][COLS], int row, int col);

//标记地雷
void MarkMine(char gameBoard[ROWS][COLS], int x, int y, int* markCount);

//取消标记
void UnMarkMine(char gameBoard[ROWS][COLS], int x, int y, int* markCount);

//排查地雷
void Sweeper(char mineMap[ROWS][COLS], char gameBoard[ROWS][COLS], int x, int y, int* clearCount);

//获胜条件：地雷全部正确标记
char AllMineMarked(char gameBoard[ROWS][COLS], int mine[MINE_NUMBER][2], int mineNumber, int* markCount);

//获胜条件：清除全部非雷区
char ClearAllField(char gameBoard[ROWS][COLS], int mine[MINE_NUMBER][2],
	int mineNumber, int row, int col, int* clearCount);

//扫雷判断
char GameOver(char mineMap[ROWS][COLS], char gameBoard[ROWS][COLS],
	int mine[MINE_NUMBER][2], int x, int y, int mineNumber);

//扫雷
char Action(char mineMap[ROWS][COLS], char gameBoard[ROWS][COLS], int mine[MINE_NUMBER][2],
	int row, int col, int mineNumber, int* markCount, int* clearCount);