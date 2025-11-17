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
    scanf("%d", out);
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

    if(mode){ // p2p
        int player = 1;
        while(1){
            printBoard(board);
            printf("Player1 Enter Placement: (RowColumn)");
            int input;
            scanf("%d", input);
            


        }
        // printBoard(board);

    }
    else{

    }


    // board[1][0] = 'o';

    printBoard(board);
    
    /* code */
    return 0;
}
