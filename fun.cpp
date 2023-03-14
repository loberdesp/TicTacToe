#include "header.h"

boardClass::boardClass() {
    height=3;
    width=3;
    boardVector.resize(height, std::vector<squareStatus>(width));
    for(int i=0; i < height; i++) {
        for(int j=0; j < width; j++) {
            boardVector[i][j] = EMPTY;
        }
    }
}

void boardClass::displayBoard() {
    for(int i=0; i < height; i++) {
        for(int j=0; j < width; j++) {
            if(j==0) {
                if(i==0) {
                    std::cout << " ";
                    for(int k=1; k <= width; k++) {
                        std::cout << "  " << k;
                    }
                    std::cout << std::endl;
                }
                std::cout << i+1 << " ";
            }
            std::cout << "[";
            switch(boardVector[i][j]) {
                case EMPTY:
                    std::cout << " ";
                break;
                case CIRCLE:
                    std::cout << "O";
                break;
                case CROSS:
                    std::cout << "X";
                break;
            }
            std::cout << "]";
        }
        std::cout << std::endl;
    }
}

void boardClass::startGame() {
    displayBoard();
    currentPlayer = 1;
    end = false;
    moveCount = 0;
    while(end==false) {
        playerMove();
        displayBoard();
        checkWinEnd();
    }
}

int boardClass::playerMove() {
    std::cout << "Player " << currentPlayer << " turn" << std::endl;
    std::cout << "Enter coordinates(column row E.g. 2 1): " << std::endl;
    std::cin >> tmpX;
    if(tmpX==9) {
        exit(0);
    }
    std::cin >> tmpY;
    tmpY--;
    tmpX--;
    if(tmpY >= 0 && tmpY <= height && tmpX >= 0 && tmpX <= width) {
        playerPlace();
        return 1;
    } else {
        std::cout << "You're exceeding area" << std::endl;
        return 0;
    }
}

int boardClass::playerPlace() {
    if(boardVector[tmpY][tmpX]==0) {
        if(currentPlayer==1) {
            boardVector[tmpY][tmpX] = CIRCLE;
            currentPlayer=2;
        } else {
            boardVector[tmpY][tmpX] = CROSS;
            currentPlayer=1;
        }
        moveCount++;
        return 1;
    } else {
        std::cout << "This place is taken" << std::endl;
        return 0;
    }
}

void boardClass::checkWinEnd() {
    for(int i=0; i < height; i++) {

        if(boardVector[i][0]!=EMPTY) {
            if(boardVector[i][0]==boardVector[i][1] && boardVector[i][1]==boardVector[i][2]) {
                currentPlayer = boardVector[i][0];
                std::cout << "Player " << currentPlayer << " won!!" << std::endl;
                end = true;
            }
        }
        if(boardVector[0][i]!=0) {
            if(boardVector[0][i]==boardVector[1][i] && boardVector[1][i]==boardVector[2][i]) {
                currentPlayer = boardVector[0][i];
                std::cout << "Player " << currentPlayer << " won!!" << std::endl;
                end = true;
            }
        }
    }

    if(boardVector[1][1]!=0) {
        if(boardVector[0][0]==boardVector[1][1] && boardVector[1][1]==boardVector[2][2]) {
            currentPlayer = boardVector[1][1];
            std::cout << "Player " << currentPlayer << " won!!" << std::endl;
            end = true;
        }
        if(boardVector[2][0]==boardVector[1][1] && boardVector[1][1]==boardVector[0][2]) {
            currentPlayer = boardVector[1][1];
            std::cout << "Player " << currentPlayer << " won!!" << std::endl;
            end = true;
        }
    }

    if(moveCount==9 && end==false) {
        std::cout << "Draw!" << std::endl;
        end = true;
    }
}
