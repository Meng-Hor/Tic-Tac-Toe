#include<stdio.h>

void initializeBoard(char board[3][3]);
void displayBoard(const char board[3][3]);

void initializeBoard(char board[3][3]){
    char count='1';
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j]=count;
            count++;
        }
    }
}

void displayBoard(const char board[3][3]){
    printf("\n");
    for (int i=0;i<3;i++){
        printf("  %c  |  %c  |  %c  \n",board[i][0],board[i][1],board[i][2]);
        if(i!=2){
            printf("-----|-----|-----\n");
        }
    }
    printf("\n");
}

int main(){
    char board[3][3];
    initializeBoard(board);
    displayBoard(board);

    return 0;
}