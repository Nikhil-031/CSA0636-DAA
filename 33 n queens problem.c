#include <stdio.h>
#include <stdbool.h>
void printBoard(int board[], int N) 
{
    for (int i = 0; i < N; i++) 
	{
        for (int j = 0; j < N; j++) 
		{
            if (board[i] == j) 
			{
                printf("Q ");
            } else {
                printf("_ ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int board[], int row, int col) 
{
    for (int i = 0; i < row; i++) 
	{
        if (board[i] == col || (abs(board[i] - col) == abs(i - row))) 
		{
            return false;
        }
    }
    return true;
}

bool solveNQueens(int board[], int N, int row) 
{
    if (row >= N) 
	{
        return true;
    }

    for (int col = 0; col < N; col++) 
	{
        if (isSafe(board, row, col)) 
		{
            board[row] = col;
            if (solveNQueens(board, N, row + 1)) 
			{
                return true;
            }
            board[row] = -1;
        }
    }

    return false;
}
int main() 
{
    int N;
    printf("Enter the board size (N): ");
    scanf("%d", &N);
    int board[N];
    for (int i = 0; i < N; i++) 
	{
        board[i] = -1; 
    }
    if (solveNQueens(board, N, 0)) 
	{
        printf("Solution:\n");
        printBoard(board, N);
    } 
	else 
	{
        printf("Solution does not exist.\n");
    }
    return 0;
}
