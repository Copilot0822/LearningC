#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[11][11] = {' '};

int initializeBoard()
{
    int size = 0;
    while (1)
    {

        printf("What size board: ");
        scanf("%d", &size);
        printf("\n");

        if (size <= 10 && size >= 3)
        {
            break;
        }
        printf("Invalid Size, Try again!\n");
    }

    return size;
}
int checkWin(char gameboard[11][11], int size){
    for(int i = 0;i<size+1;i++){
        for(int j = 0;size+1>j;i++){
            
        }
    }

}
void printBoard(char gameboard[11][11])
{
    int column = 0;
    int row = 0;

    while (1)
    {
        if (gameboard[row][column] == 'x' || gameboard[row][column] == 'o')
        {
            printf(" %c ", gameboard[row][column]);
        }
        else if (gameboard[row][column] != ',')
        {
            printf("   ");
        }

        // printf("%c", gameboard[row][column]);
        column++;
        if (gameboard[row][column] == ',')
        {
            row++;
            // column;
            printf("\n");
            int count = 0;
            while (1)
            {
                if (column == 0 || gameboard[row][0] == ',')
                {
                    column = 0;
                    break;
                }
                // printf("----");
                if (count == 0)
                {
                    printf(" - ");
                }
                else
                {
                    printf("  - ");
                }

                count++;
                column--;
            }
            printf("\n");
        }
        else
        {
            printf("|");
        }
        if (column < 3 && gameboard[row][column] == ',')
        {
            break;
        }
    }
}
int modeSelect()
{
    printf("Mode 1 for P2P, 0 for PvAI: ");
    int out;
    scanf("%d", &out);
    printf("\n");
    return out;
}
int main(int argc, char const *argv[])
{
    int size = initializeBoard();
    // int size = 10;
    for (size_t i = 0; i <= size; i++)
    {
        board[i][size] = ',';
        /* code */
    }
    for (size_t i = 0; i <= size; i++)
    {
        board[size][i] = ',';
        /* code */
    }

    int mode = modeSelect();

    if (mode)
    { // p2p
        int player = 1;
        while (1)
        {
            printBoard(board);
            int row, col;
            while (1)
            {
                printf("Player%d Enter Placement: (RowColumn)", player);
                int input;

                scanf("%d", &input);
                printf("\n");

                row = input / 10;
                col = input % 10;

                if (col > 0 && row > 0 && col <= size && row <= size && board[row - 1][col - 1] != 'x' && board[row - 1][col - 1] != 'o')
                {
                    break;
                }
                printf("Not Allowed\n");
            }
            if (player == 1)
            {
                board[row - 1][col - 1] = 'x';
                player = 2;
            }
            else
            {
                board[row - 1][col - 1] = 'o';
                player = 1;
            }
            printBoard(board);
        }
        // printBoard(board);
    }
    else
    {

    }

    // board[1][0] = 'o';

    printBoard(board);

    /* code */
    return 0;
}
