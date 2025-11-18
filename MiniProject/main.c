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
char checkWin(char gameboard[11][11], int size)
{
    int i, j;

    /* check rows */
    for (i = 0; i < size; i++) {
        int allX = 1;
        int allO = 1;

        for (j = 0; j < size; j++) {
            char c = gameboard[i][j];
            if (c != 'x') allX = 0;
            if (c != 'o') allO = 0;
        }

        if (allX) return 'x';
        if (allO) return 'o';
    }

    /* check columns */
    for (j = 0; j < size; j++) {
        int allX = 1;
        int allO = 1;

        for (i = 0; i < size; i++) {
            char c = gameboard[i][j];
            if (c != 'x') allX = 0;
            if (c != 'o') allO = 0;
        }

        if (allX) return 'x';
        if (allO) return 'o';
    }

    /* check main diagonal (0,0) -> (size-1,size-1) */
    {
        int allX = 1;
        int allO = 1;

        for (i = 0; i < size; i++) {
            char c = gameboard[i][i];
            if (c != 'x') allX = 0;
            if (c != 'o') allO = 0;
        }

        if (allX) return 'x';
        if (allO) return 'o';
    }

    /* check anti-diagonal (0,size-1) -> (size-1,0) */
    {
        int allX = 1;
        int allO = 1;

        for (i = 0; i < size; i++) {
            char c = gameboard[i][size - 1 - i];
            if (c != 'x') allX = 0;
            if (c != 'o') allO = 0;
        }

        if (allX) return 'x';
        if (allO) return 'o';
    }

    return 'b';  /* no winner */
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
        int p1 = 0;
        int p2 = 0;


        while(1)
        {
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
                if(checkWin(board, size) == 'x'){
                    p1++;
                    break;

                }
                else if(checkWin(board, size) == 'o'){
                    p2++;
                    break;
                }

                // printBoard(board);
                // printf("\n%c\n", checkWin(board, size));
            }


            printf("Play again: (y/n): ");
            char playagain;
            scanf("%c", &playagain);
            printf("player1: %d, player2: %d", p1, p2);
            if(playagain == 'y'){
                player = 2;
            }
            else{
                break;
            }
            
            
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
                    board[row - 1][col - 1] = 'o';
                    player = 2;
                }
                else
                {
                    board[row - 1][col - 1] = 'x';
                    player = 1;
                }
                if(checkWin(board, size) == 'x'||checkWin(board, size) == 'o') ;

                // printBoard(board);
                // printf("\n%c\n", checkWin(board, size));
            }
            

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
