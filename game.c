#include"game.h"


void menu()
{
	printf("**************************************\n");
	printf("****     1.play       0.exit      ****\n");
	printf("**************************************\n");
}


//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col)
{
	int j = 0;
	int i = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			board[i][j] = ' ';
		}
	}
}


//   |   |   
//---|---|---
//   |   |   
//---|---|---
//   |   |   

//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < ROW; i++)
	{
		//打印数据
		int j = 0;
		for (j = 0; j < COL; j++)
		{
			printf(" %C ", board[i][j]);
			if (j < COL - 1)
				printf("|");
		}
		printf("\n");
		int z = 0;
		if (i < ROW - 1)
		{
			for (z = 0; z < COL; z++)
			{
				//打印分割线
				printf("---");
				if (z < COL - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}


int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (board[i][j] == ' ')
				return 0;//没满
		}
	}
	return 1;//满了
}

//1.玩家赢 *
//2.电脑赢 #
//3.平局 Q
//4.继续 C

//   |   |   
//---|---|---
//   |   |   
//---|---|---
//   |   |   



char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < ROW; i++)//三横行连一线
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][1] != ' ')
			return board[i][1];
	}
	for (i = 0; i < COL; i++)//三纵列连一线
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][1] != ' ')
			return board[i][1];
	}
	//斜线1
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] != ' ')
		return board[0][0];
	//斜线2
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] != ' ')
		return board[0][2];
	//平局
	if (1 == IsFull(board, ROW, COL))
	{
		return 'Q';
	}
	return 'C';//继续

}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("玩家走:>\n");
	while (1)
	{
		printf("请输入坐标:>\n");
		scanf_s("%d%d", &i, &j);
		if (i >= 1 && i <= ROW && j >= 1 && j <= COL)
		{
			//判断坐标有没有被占用
			if (board[i - 1][j - 1] == ' ')
			{
				board[i - 1][j - 1] = '*';
				break;
			}
			else if (board[i - 1][j - 1] != ' ')
			{
				printf("该坐标被占用\n");
				printf("请重新输入:>\n");
			}
		}
		else
			printf("输入错误，请重新输入:>\n");
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	while (1)
	{
		i = rand() % 3;
		j = rand() % 3;
		if (board[i][j] == ' ')
		{
			board[i][j] = '#';
			printf("\n");
			break;
		}
	}
}


void game()
{
	printf("欢迎进入游戏\n");
	//数组，存放棋盘的信息
	char board[ROW][COL] = { 0 };
	//初始化棋盘,传数组，行，列
	InitBoard(board, ROW, COL);
	//打印棋盘，传数组，行，列
	DisplayBoard(board, ROW, COL);
	char ret = 0;
	while (1)
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
		printf("玩家赢\n");
	else if (ret == '#')
		printf("电脑赢\n");
	else if (ret == 'Q')
		printf("平局\n");

}