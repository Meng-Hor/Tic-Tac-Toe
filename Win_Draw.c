#include <stdio.h>
#include <stdbool.h>

int attempts = 0;

int checkWin(char board[3][3], char name[]){
    // checking row
    for (int i=0; i<3; i++){
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            if (board[i][0] == name[0]){
                return 1;
            }else{
                return 2;
            }
        }
    }
    // check column
    for (int j=0; j<3; j++){
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]){
            if (board[0][j] == name[0]){
                return 1;
            }else{
                return 2;
            }
        }
    }
    // check main diagonal
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        if (board[0][0] == name[0]){
            return 1;
        }else{
            return 2;
        }
    }
    // check anti-diagonal
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        if (board[0][2] == name[0]){
            return 1;
        }else{
            return 2;
        }
    }
    return 0;
}

bool checkDraw(char board[3][3]){
    if (attempts == 9){
        if (checkWin(board) == 0){
            return 1;
        }
    }
    return 0;
}