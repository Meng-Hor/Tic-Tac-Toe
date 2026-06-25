#include <stdio.h>
typedef struct
{
    int playerNum;
    char symbol;
} Player;
void print_board(char board[3][3]);
void playerMoveBasic(char board[3][3], char symbol, int playerNum);
void playerMoveStruct(char board[3][3], Player *player);

int main()
{
    char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}};
    Player player1 = {1, 'X'};
    Player player2 = {2, 'O'};

    printf("--- Initial Board ---\n");
    print_board(board);
    printf("\n--- Player 1's Turn (Using Basic Function) ---\n");
    playerMoveBasic(board, player1.symbol, player1.playerNum);
    print_board(board);
    printf("\n--- Player 2's Turn (Using Struct Function) ---\n");
    playerMoveStruct(board, &player2);
    print_board(board);

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
void playerMoveBasic(char board[3][3], char symbol, int playerNum)
{
    int move, row, col;
    while (1)
    {
        printf("Player %d (Choice: %c), Enter move (1-9): ", playerNum, symbol);

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
            board[row][col] = symbol;
            break;
        }
    }
}
void playerMoveStruct(char board[3][3], Player *player)
{
    int move, row, col;
    while (1)
    {
        printf("Player %d (Choice: %c), Enter move (1-9): ", player->playerNum, player->symbol);

        if (scanf("%d", &move) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n')
                ;
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
            break;
        }
    }
}