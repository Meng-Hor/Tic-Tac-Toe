#include <stdio.h>

typedef struct
{
    int playerNum;
    char symbol;
} Player;

void print_board(char board[3][3]);
void playerMoveStruct(char board[3][3], Player *player);
int checkWin(char board[3][3]);

int main()
{
    char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}};

    Player p1 = {1, 'X'};
    Player p2 = {2, 'O'};

    Player *currentPlayer = &p1; // Player 1 starts
    int turns = 0;
    int gameStatus = 0; // 0 = ongoing, 1 = win, 2 = tie

    printf("--- Welcome to Tic-Tac-Toe ---\n");

    while (gameStatus == 0)
    {
        print_board(board);

        // Get the current player's move
        playerMoveStruct(board, currentPlayer);
        turns++;

        if (checkWin(board))
        {
            gameStatus = 1; // Someone won!
            break;
        }
        if (turns == 9)
        {
            gameStatus = 2; // Tie game
            break;
        }

        if (currentPlayer == &p1)
        {
            currentPlayer = &p2;
        }
        else
        {
            currentPlayer = &p1;
        }
    }
    print_board(board);
    printf("\n--- GAME OVER ---\n");
    if (gameStatus == 1)
    {
        printf("Congratulations! Player %d (%c) wins the game!\n", currentPlayer->playerNum, currentPlayer->symbol);
    }
    else if (gameStatus == 2)
    {
        printf("It's a tie! Nobody wins.\n");
    }

    return 0;
}

void print_board(char board[3][3])
{
    printf("\n %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

void playerMoveStruct(char board[3][3], Player *player)
{
    int move, row, col;
    while (1)
    {
        printf("\nPlayer %d (%c), enter your move (1-9): ", player->playerNum, player->symbol);

        if (scanf("%d", &move) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n')
                ; // Clear input buffer
            continue;
        }

        if (move < 1 || move > 9)
        {
            printf("Invalid move.. please Re-enter\n");
            continue;
        }

        row = (move - 1) / 3;
        col = (move - 1) % 3;
        if (board[row][col] == 'X' || board[row][col] == 'O')
        {
            printf("Invalid move.. spot already taken. please Re-enter\n");
        }
        else
        {
            board[row][col] = player->symbol;
            break; // Valid move, exit the input loop
        }
    }
}
int checkWin(char board[3][3])
{
    int i;
    for (i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return 1;
        }
    }
    for (i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return 1;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return 1;
    }

    return 0;
}