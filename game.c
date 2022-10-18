#include"game.h"


void menu()
{
	printf("**************************************\n");
	printf("****     1.play       0.exit      ****\n");
	printf("**************************************\n");
}


//��ʼ������
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

//��ӡ����
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < ROW; i++)
	{
		//��ӡ����
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
				//��ӡ�ָ���
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
				return 0;//û��
		}
	}
	return 1;//����
}

//1.���Ӯ *
//2.����Ӯ #
//3.ƽ�� Q
//4.���� C

//   |   |   
//---|---|---
//   |   |   
//---|---|---
//   |   |   



char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < ROW; i++)//��������һ��
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][1] != ' ')
			return board[i][1];
	}
	for (i = 0; i < COL; i++)//��������һ��
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][1] != ' ')
			return board[i][1];
	}
	//б��1
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] != ' ')
		return board[0][0];
	//б��2
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] != ' ')
		return board[0][2];
	//ƽ��
	if (1 == IsFull(board, ROW, COL))
	{
		return 'Q';
	}
	return 'C';//����

}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("�����:>\n");
	while (1)
	{
		printf("����������:>\n");
		scanf_s("%d%d", &i, &j);
		if (i >= 1 && i <= ROW && j >= 1 && j <= COL)
		{
			//�ж�������û�б�ռ��
			if (board[i - 1][j - 1] == ' ')
			{
				board[i - 1][j - 1] = '*';
				break;
			}
			else if (board[i - 1][j - 1] != ' ')
			{
				printf("�����걻ռ��\n");
				printf("����������:>\n");
			}
		}
		else
			printf("�����������������:>\n");
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
	printf("��ӭ������Ϸ\n");
	//���飬������̵���Ϣ
	char board[ROW][COL] = { 0 };
	//��ʼ������,�����飬�У���
	InitBoard(board, ROW, COL);
	//��ӡ���̣������飬�У���
	DisplayBoard(board, ROW, COL);
	char ret = 0;
	while (1)
	{
		//�������
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//��������
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
		printf("���Ӯ\n");
	else if (ret == '#')
		printf("����Ӯ\n");
	else if (ret == 'Q')
		printf("ƽ��\n");

}