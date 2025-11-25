#include <stdio.h>

char board[11][11];

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

    /* main diagonal */
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

    /* anti-diagonal */
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

void clearBoard(char b[11][11], int size)
{
    for (int r = 0; r < size; ++r)
        for (int c = 0; c < size; ++c)
            b[r][c] = ' ';
}

void printBoard(char gameboard[11][11], int size)
{
    for (int r = 0; r < size; ++r) {
        for (int c = 0; c < size; ++c) {
            char ch = gameboard[r][c];
            if (ch == 'x' || ch == 'o')
                printf(" %c ", ch);
            else
                printf("   ");

            if (c < size - 1)
                printf("|");
        }
        printf("\n");
        if (r < size - 1) {
            for (int c = 0; c < size; ++c) {
                if (c == 0)
                    printf(" - ");
                else
                    printf("  - ");
            }
            printf("\n");
        }
    }
}

int initializeBoard(void)
{
    int size = 0;
    while (1)
    {
        printf("What size board (3 - 10): ");
        scanf("%d", &size);
        printf("\n");

        if (size >= 3 && size <= 10)
            break;

        printf("Invalid Size, Try again!\n");
    }

    return size;
}

int modeSelect(void)
{
    printf("Mode 1 for P2P, 0 for PvAI: ");
    int out;
    scanf("%d", &out);
    printf("\n");
    return out;
}

int main(void)
{
    int size = initializeBoard();
    int mode = modeSelect();

    if (mode) { /* P2P */

        int p1 = 0;   /* score for human 1 */
        int p2 = 0;   /* score for human 2 */

        
        char p1Mark = 'x';
        char p2Mark = 'o';

        while (1) {   

            clearBoard(board, size);

        
            int startingPlayer = (p1Mark == 'x') ? 1 : 2;
            int player = startingPlayer;
            int moves = 0;
            char winner = 'b';

            printf("New game!\n");
            printf("Player 1 is '%c', Player 2 is '%c'.\n", p1Mark, p2Mark);
            printf("Player %d ('x') goes first.\n\n", startingPlayer);

            while (1) {  
                printBoard(board, size);

                int row, col;
                while (1) {
                    printf("Player%d Enter Placement: row col ", player);
                    scanf("%d %d", &row, &col);
                    printf("\n");

                    if (row > 0 && col > 0 &&
                        row <= size && col <= size &&
                        board[row - 1][col - 1] != 'x' &&
                        board[row - 1][col - 1] != 'o') {
                        break;
                    }
                    printf("Not Allowed\n");
                }
                

                char mark = (player == 1) ? p1Mark : p2Mark;
                board[row - 1][col - 1] = mark;
                moves++;

                winner = checkWin(board, size);
                if (winner != 'b' || moves == size * size)
                    break;

                player = 3 - player; 
            }

            printBoard(board, size);

            if (winner == p1Mark) {
                printf("Player 1 (%c) wins!\n", p1Mark);
                p1++;
            } else if (winner == p2Mark) {
                printf("Player 2 (%c) wins!\n", p2Mark);
                p2++;
            } else {
                printf("It's a draw.\n");
            }

            printf("Score: Player1=%d, Player2=%d\n", p1, p2);

            printf("Play again (y/n): ");
            char playagain;
            scanf(" %c", &playagain);  
            if (playagain != 'y' && playagain != 'Y')
                break;

            
            char tmp = p1Mark;
            p1Mark = p2Mark;
            p2Mark = tmp;
        }

    } else {
        int p1 = 0;
        int ai = 0;

        char p1Mark = 'x';
        char aiMark = 'o';

        while (1) {

            clearBoard(board, size);

            int startingPlayer = (p1Mark == 'x') ? 1 : 2;
            int player = startingPlayer;
            int moves = 0;
            char winner = 'b';

            printf("New game!\n");
            printf("Player 1 is '%c', Computer is '%c'.\n", p1Mark, aiMark);
            printf("Player %d ('x') goes first.\n\n", startingPlayer);

            while (1) {
                printBoard(board, size);

                int row, col;

                if (player == 1) {
                    while (1) {
                        printf("Player1 Enter Placement: row col ");
                        scanf("%d %d", &row, &col);
                        printf("\n");

                        if (row > 0 && col > 0 &&
                            row <= size && col <= size &&
                            board[row - 1][col - 1] != 'x' &&
                            board[row - 1][col - 1] != 'o') {
                            break;
                        }
                        printf("Not Allowed\n");
                    }
                } else {
                    // int tries = 0;
                    // while (1) {
                    //     row = (rand() % size) + 1;
                    //     col = (rand() % size) + 1;
                    //     if (board[row - 1][col - 1] != 'x' &&
                    //         board[row - 1][col - 1] != 'o') {
                    //         break;
                    //     }
                    //     tries++;
                    //     if (tries > size * size) break;
                    // }
                    // printf("Computer plays: %d %d\n\n", row, col);
                    
                }

                char mark;
                if (player == 1) mark = p1Mark;
                else mark = aiMark;

                board[row - 1][col - 1] = mark;
                moves++;

                winner = checkWin(board, size);
                if (winner != 'b' || moves == size * size)
                    break;

                if (player == 1) player = 2;
                else player = 1;
            }

            printBoard(board, size);

            if (winner == p1Mark) {
                printf("Player 1 (%c) wins!\n", p1Mark);
                p1++;
            } else if (winner == aiMark) {
                printf("Computer (%c) wins!\n", aiMark);
                ai++;
            } else {
                printf("It's a draw.\n");
            }

            printf("Score: Player1=%d, Computer=%d\n", p1, ai);

            printf("Play again (y/n): ");
            char playagain;
            scanf(" %c", &playagain);
            if (playagain != 'y' && playagain != 'Y')
                break;

            char tmp = p1Mark;
            p1Mark = aiMark;
            aiMark = tmp;
        }
    }

    return 0;
}
