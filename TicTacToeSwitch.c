#include <stdio.h>
#include <string.h>

void initializeBoard(char board[3][3]);
void displayBoard(const char board[3][3]);
void switchPlayer(int n, char name[]); // without using structs, this function only prints, nothing else
int getPlayerMove(int n);

int main(){
    int choice;
    char board[3][3];
    char names[2][30];

    initializeBoard(board);

    for (int i = 0; i < 2; i++){
        printf("\nUser %d's Turn\n", i + 1);
        printf("Enter Your Name: ");
        fgets(names[i], sizeof(names), stdin);
        (names[i])[strlen(names[i]) - 1] = '\0';
    }
    printf("\n");

    displayBoard(board);

    for (int attempt = 1; attempt <= 9; attempt++){
        switchPlayer(attempt, names[(attempt - 1) % 2]);
        choice = getPlayerMove(attempt);
        displayBoard(board);
    }

    return 0;
}

void initializeBoard(char board[3][3]){
    char count = '1';
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            board[i][j] = count;
            count++;
        }
    }
}

void displayBoard(const char board[3][3]){
    for (int i = 0; i < 3; i++){
        printf(" %c | %c | %c \n",board[i][0], board[i][1], board[i][2]);
        if(i != 2){
            printf("-----------\n");
        }
    }
    printf("\n");
}

int getPlayerMove(int n){
    int choice;

    printf("Enter Your Choice: ");
    scanf("%d", &choice);

    return choice;
}

void switchPlayer(int n, char name[]){
    printf("%s's Turn\n\n", name);
}