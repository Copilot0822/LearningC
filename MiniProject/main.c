#include <stdio.h>
#include <stdlib.h>

char board[11][11];

#define WIN_NONE 0
#define WIN_ROW 1
#define WIN_COL 2
#define WIN_MAIN_DIAG 3
#define WIN_ANTI_DIAG 4

typedef struct
{
    int games_played;
    int wins_player1;
    int wins_player2;
    int draws;
    int *win_patterns; // Dynamic array : tracks HOW games were won
    int pattern_count;
    int pattern_capacity;
} GameStats;

// Required functions :
GameStats *createGameStats();
void updateStats(GameStats *stats, char winner, int win_type);
void freeGameStats(GameStats *stats);
void printStatistics(const GameStats *stats);

int last_win_type = WIN_NONE;
char currentP1 = 'x';
char currentP2 = 'o';

char checkWin(char gameboard[11][11], int size)
{
    int i, j;

    /* check rows */
    for (i = 0; i < size; i++)
    {
        int allX = 1;
        int allO = 1;

        for (j = 0; j < size; j++)
        {
            char c = gameboard[i][j];
            if (c != 'x')
                allX = 0;
            if (c != 'o')
                allO = 0;
        }

        if (allX)
        {
            last_win_type = WIN_ROW;
            return 'x';
        }
        if (allO)
        {
            last_win_type = WIN_ROW;
            return 'o';
        }
    }

    /* check columns */
    for (j = 0; j < size; j++)
    {
        int allX = 1;
        int allO = 1;

        for (i = 0; i < size; i++)
        {
            char c = gameboard[i][j];
            if (c != 'x')
                allX = 0;
            if (c != 'o')
                allO = 0;
        }

        if (allX)
        {
            last_win_type = WIN_COL;
            return 'x';
        }
        if (allO)
        {
            last_win_type = WIN_COL;
            return 'o';
        }
    }

    /* main diagonal */
    {
        int allX = 1;
        int allO = 1;

        for (i = 0; i < size; i++)
        {
            char c = gameboard[i][i];
            if (c != 'x')
                allX = 0;
            if (c != 'o')
                allO = 0;
        }

        if (allX)
        {
            last_win_type = WIN_MAIN_DIAG;
            return 'x';
        }
        if (allO)
        {
            last_win_type = WIN_MAIN_DIAG;
            return 'o';
        }
    }

    /* anti-diagonal */
    {
        int allX = 1;
        int allO = 1;

        for (i = 0; i < size; i++)
        {
            char c = gameboard[i][size - 1 - i];
            if (c != 'x')
                allX = 0;
            if (c != 'o')
                allO = 0;
        }

        if (allX)
        {
            last_win_type = WIN_ANTI_DIAG;
            return 'x';
        }
        if (allO)
        {
            last_win_type = WIN_ANTI_DIAG;
            return 'o';
        }
    }

    last_win_type = WIN_NONE;
    return 'b'; /* no winner */
}

void clearBoard(char b[11][11], int size)
{
    for (int r = 0; r < size; ++r)
        for (int c = 0; c < size; ++c)
            b[r][c] = ' ';
}

void printBoard(char gameboard[11][11], int size)
{
    for (int r = 0; r < size; ++r)
    {
        for (int c = 0; c < size; ++c)
        {
            char ch = gameboard[r][c];
            if (ch == 'x' || ch == 'o')
                printf(" %c ", ch);
            else
                printf("   ");

            if (c < size - 1)
                printf("|");
        }
        printf("\n");
        if (r < size - 1)
        {
            for (int c = 0; c < size; ++c)
            {
                if (c == 0)
                    printf(" - ");
                else
                    printf("  - ");
            }
            printf("\n");
        }
    }
}

GameStats *createGameStats()
{
    GameStats *s = malloc(sizeof(GameStats));
    if (!s)
        return NULL;
    s->games_played = 0;
    s->wins_player1 = 0;
    s->wins_player2 = 0;
    s->draws = 0;
    s->pattern_capacity = 10;
    s->pattern_count = 0;
    s->win_patterns = malloc(sizeof(int) * s->pattern_capacity);
    if (!s->win_patterns)
    {
        free(s);
        return NULL;
    }
    return s;
}

void updateStats(GameStats *stats, char winner, int win_type)
{
    if (!stats)
        return;

    stats->games_played++;

    if (winner == 'b')
        stats->draws++;
    else if (winner == currentP1)
        stats->wins_player1++;
    else if (winner == currentP2)
        stats->wins_player2++;

    if (win_type != WIN_NONE)
    {
        if (stats->pattern_count == stats->pattern_capacity)
        {
            int newCap = stats->pattern_capacity * 2;
            int *tmp = realloc(stats->win_patterns, sizeof(int) * newCap);
            if (tmp)
            {
                stats->win_patterns = tmp;
                stats->pattern_capacity = newCap;
            }
        }
        if (stats->pattern_count < stats->pattern_capacity)
        {
            stats->win_patterns[stats->pattern_count] = win_type;
            stats->pattern_count++;
        }
    }
}

void freeGameStats(GameStats *stats)
{
    if (!stats)
        return;
    free(stats->win_patterns);
    free(stats);
}

void printStatistics(const GameStats *stats)
{
    if (!stats)
        return;
    printf("\n=== Game statistics ===\n");
    printf("Games played: %d\n", stats->games_played);
    printf("Player1 wins: %d\n", stats->wins_player1);
    printf("Player2 wins: %d\n", stats->wins_player2);
    printf("Draws: %d\n", stats->draws);

    int r = 0, c = 0, d1 = 0, d2 = 0;
    for (int i = 0; i < stats->pattern_count; i++)
    {
        if (stats->win_patterns[i] == WIN_ROW)
            r++;
        else if (stats->win_patterns[i] == WIN_COL)
            c++;
        else if (stats->win_patterns[i] == WIN_MAIN_DIAG)
            d1++;
        else if (stats->win_patterns[i] == WIN_ANTI_DIAG)
            d2++;
    }
    printf("Row wins: %d\n", r);
    printf("Column wins: %d\n", c);
    printf("Main diagonal wins: %d\n", d1);
    printf("Anti-diagonal wins: %d\n", d2);
    printf("=======================\n\n");
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

    GameStats *stats = createGameStats();
    if (!stats)
    {
        printf("could not alloc stats\n");
        return 1;
    }

    if (mode)
    { /* P2P */

        int p1 = 0; /* score for human 1 */
        int p2 = 0; /* score for human 2 */

        char p1Mark = 'x';
        char p2Mark = 'o';

        while (1)
        {

            clearBoard(board, size);

            currentP1 = p1Mark;
            currentP2 = p2Mark;

            int startingPlayer = (p1Mark == 'x') ? 1 : 2;
            int player = startingPlayer;
            int moves = 0;
            char winner = 'b';

            printf("New game!\n");
            printf("Player 1 is '%c', Player 2 is '%c'.\n", p1Mark, p2Mark);
            printf("Player %d ('x') goes first.\n\n", startingPlayer);

            while (1)
            {
                printBoard(board, size);

                int row, col;
                while (1)
                {
                    printf("Player%d Enter Placement: row col ", player);
                    scanf("%d %d", &row, &col);
                    printf("\n");

                    if (row > 0 && col > 0 &&
                        row <= size && col <= size &&
                        board[row - 1][col - 1] != 'x' &&
                        board[row - 1][col - 1] != 'o')
                    {
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

            if (winner == p1Mark)
            {
                printf("Player 1 (%c) wins!\n", p1Mark);
                p1++;
            }
            else if (winner == p2Mark)
            {
                printf("Player 2 (%c) wins!\n", p2Mark);
                p2++;
            }
            else
            {
                printf("It's a draw.\n");
            }

            updateStats(stats, winner, last_win_type);

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
    }
    else
    {
        int p1 = 0;
        int ai = 0;

        char p1Mark = 'x';
        char aiMark = 'o';

        while (1)
        {

            clearBoard(board, size);

            currentP1 = p1Mark;
            currentP2 = aiMark;

            int startingPlayer = (p1Mark == 'x') ? 1 : 2;
            int player = startingPlayer;
            int moves = 0;
            char winner = 'b';

            printf("New game!\n");
            printf("Player 1 is '%c', Computer is '%c'.\n", p1Mark, aiMark);
            printf("Player %d ('x') goes first.\n\n", startingPlayer);

            while (1)
            {
                printBoard(board, size);

                int row, col;

                if (player == 1)
                {
                    while (1)
                    {
                        printf("Player1 Enter Placement: row col ");
                        scanf("%d %d", &row, &col);
                        printf("\n");

                        if (row > 0 && col > 0 &&
                            row <= size && col <= size &&
                            board[row - 1][col - 1] != 'x' &&
                            board[row - 1][col - 1] != 'o')
                        {
                            break;
                        }
                        printf("Not Allowed\n");
                    }
                }
                else
                {
                    if (player == 1)
                    {
                        while (1)
                        {
                            printf("Player1 Enter Placement: row col ");
                            scanf("%d %d", &row, &col);
                            printf("\n");

                            if (row > 0 && col > 0 &&
                                row <= size && col <= size &&
                                board[row - 1][col - 1] != 'x' &&
                                board[row - 1][col - 1] != 'o')
                            {
                                break;
                            }
                            printf("Not Allowed\n");
                        }
                    }
                    else
                    {
                        int rowBlock = -1, colBlock = -1;
                        for (int r = 0; r < size; r++)
                        {
                            for (int c = 0; c < size; c++)
                            {
                                if (board[r][c] != 'x' && board[r][c] != 'o')
                                {
                                    board[r][c] = p1Mark;
                                    if (checkWin(board, size) == p1Mark)
                                    {
                                        rowBlock = r;
                                        colBlock = c;
                                    }
                                    board[r][c] = ' ';
                                    if (rowBlock != -1)
                                        break;
                                }
                            }
                            if (rowBlock != -1)
                                break;
                        }

                        if (rowBlock != -1)
                        {
                            row = rowBlock + 1;
                            col = colBlock + 1;
                        }
                        else
                        {
                            int tries = 0;
                            while (1)
                            {
                                row = (rand() % size) + 1;
                                col = (rand() % size) + 1;
                                if (board[row - 1][col - 1] != 'x' &&
                                    board[row - 1][col - 1] != 'o')
                                {
                                    break;
                                }
                                tries++;
                                if (tries > size * size)
                                    break;
                            }
                        }

                        printf("Computer plays: %d %d\n\n", row, col);
                    }
                }

                char mark;
                if (player == 1)
                    mark = p1Mark;
                else
                    mark = aiMark;

                board[row - 1][col - 1] = mark;
                moves++;

                winner = checkWin(board, size);
                if (winner != 'b' || moves == size * size)
                    break;

                if (player == 1)
                    player = 2;
                else
                    player = 1;
            }

            printBoard(board, size);

            if (winner == p1Mark)
            {
                printf("Player 1 (%c) wins!\n", p1Mark);
                p1++;
            }
            else if (winner == aiMark)
            {
                printf("Computer (%c) wins!\n", aiMark);
                ai++;
            }
            else
            {
                printf("It's a draw.\n");
            }

            updateStats(stats, winner, last_win_type);

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

    printStatistics(stats);
    freeGameStats(stats);

    return 0;
}
