#define ROW 3  //定义棋盘的行
#define COL 3  //定义棋盘的列#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

void menu();

void InitBoard(char board[ROW][COL], int row, int col);

void DisplayBoard(char board[ROW][COL], int row, int col);

int IsFull(char board[ROW][COL], int row, int col);

char IsWin(char board[ROW][COL], int row, int col);

void PlayerMove(char board[ROW][COL], int row, int col);

void ComputerMove(char board[ROW][COL], int row, int col);

void game();