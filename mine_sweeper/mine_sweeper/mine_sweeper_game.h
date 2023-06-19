#pragma once

#include<stdio.h>
#include<stdlib.h>

#define ROW 9           //游戏界面 及 包含地雷的区域 的行列
#define COL 9

#define ROWS ROW + 2    //在判断周围地雷数量及递归展开周围没有雷的格子时，因为要对坐标周围8个格子进行操作，
#define COLS COL + 2    //因此存在越界的可能，因此，在周围增加一圈虚拟的网格来防止越界。

#define MINE_NUMBER 2

/*****************************************************************************************************
* 参数列表：char mineMap[ROWS][COLS]——用于布置地雷
*			char gameBoard[ROWS][COLS]——展示的游戏界面
*			int mine[MINE_NUMBER][2]——储存每个地雷的行列坐标，以二维数组的形式存放，每行为一个坐标
*			int rows, int cols——地雷地图数组和游戏界面数组的实际行列
*			int row, int col——地雷地图可能有地雷的区域的行列，及游戏界面展示的行列
*			int x, int y——每次扫雷操作的坐标
*			int mineNumber——地雷数量
*			int* markCount——记录标记地雷的数量，用于判断通过标记全部地雷获得胜利
*			int* clearCount——记录清扫非雷区域的数量，用于判断通过清扫全部非雷区获得胜利
******************************************************************************************************/

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

//打印游戏界面
void DisplayGameBoard(char gameBoard[ROWS][COLS], int row, int col);

//操作：标记地雷
void MarkMine(char gameBoard[ROWS][COLS], int x, int y, int* markCount);

//操作：取消标记
void UnMarkMine(char gameBoard[ROWS][COLS], int x, int y, int* markCount);

//操作：排查地雷
void Sweeper(char mineMap[ROWS][COLS], char gameBoard[ROWS][COLS], int x, int y, int* clearCount);

//获胜条件：地雷全部正确标记
char AllMineMarked(char gameBoard[ROWS][COLS], int mine[MINE_NUMBER][2], int mineNumber, int* markCount);

//获胜条件：清除全部非雷区
char ClearAllField(char gameBoard[ROWS][COLS], int mine[MINE_NUMBER][2],
	int mineNumber, int row, int col, int* clearCount);

//失败条件：踩到地雷
char GameOver(char mineMap[ROWS][COLS], char gameBoard[ROWS][COLS],
	int mine[MINE_NUMBER][2], int x, int y, int mineNumber);

//扫雷
char Action(char mineMap[ROWS][COLS], char gameBoard[ROWS][COLS], int mine[MINE_NUMBER][2],
	int row, int col, int mineNumber, int* markCount, int* clearCount);