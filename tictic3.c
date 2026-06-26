#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    int playerNum;
    char symbol;
    char name[30];
} Player;
void initializeBoard(char board[3][3]);
void displayBoard(const char board[3][3]);
void switchPlayer(Player *player);
int getPlayerMove(Player *player, char board[3][3], int attempt);

int main()
{
    char choice;
    char board[3][3];
    Player players[2];
    players[0].playerNum = 1;
    players[1].playerNum = 2;
    initializeBoard(board);
    for (int i = 0; i < 2; i++)
    {
        printf("\nUser %d's Turn\n", i + 1);
        printf("Enter Your Name: ");
        fgets(players[i].name, sizeof(players[i].name), stdin);
        players[i].name[strcspn(players[i].name, "\n")] = '\0';
    }
    printf("\n");
    while (1)
    {
        printf("Player 1, choose your symbol (X or O): ");

        scanf(" %c", &choice);
        choice = toupper(choice);

        if (choice == 'X' || choice == 'O')
        {
            break;
        }
        printf("Invalid choice! Please enter 'X' or 'O'.\n\n");
    }

    players[0].symbol = choice;
    if (players[0].symbol == 'X')
    {
        players[1].symbol = 'O';
    }
    else
    {
        players[1].symbol = 'X';
    }

    // Print confirmation
    printf("\n--- Setup Complete ---\n");
    printf("Player 1: %c\n", players[0].symbol);
    printf("Player 2: %c\n", players[1].symbol);
    displayBoard(board);
    for (int attempt = 1; attempt <= 9; attempt++)
    {

        Player *currentPlayer = &players[(attempt - 1) % 2];

        switchPlayer(currentPlayer);
        getPlayerMove(currentPlayer, board, attempt);
        displayBoard(board);
    }

    return 0;
}
void initializeBoard(char board[3][3])
{
    char count = '1';
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = count;
            count++;
        }
    }
}
void displayBoard(const char board[3][3])
{
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i != 2)
        {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}
void switchPlayer(Player *player)
{
    printf("%s's Turn (%c)\n", player->name, player->symbol);
}
int getPlayerMove(Player *player, char board[3][3], int attempt)
{
    int move, row, col;
    while (1)
    {
        printf("Player %d (%s), Enter move (1-9): ", player->playerNum, player->name);
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
    return move;
}