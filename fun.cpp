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
    currentPlayer = 0;
    while(end==false) {
        playerMove();
        displayBoard();
    }
}

int boardClass::playerMove() {
    std::cout << "Player " << currentPlayer << " turn" << std::endl;
    std::cout << "Enter coordinates(width height E.g. 2 1): " << std::endl;
    std::cin >> tmpY;
    std::cin >> tmpX;
    tmpY--;
    tmpX--;
    if(tmpY >= 0 && tmpY <= height && tmpX >= 0 && tmpX <= width) {
        playerPlace();
        return 1;
    } else {
        std::cout << "you're exceeding area" << std::endl;
        return 0;
    }
}

int boardClass::playerPlace() {
    if(boardVector[tmpY][tmpX]==0) {
        if(currentPlayer==0) {
            boardVector[tmpY][tmpX] = CIRCLE;
            currentPlayer=1;
        } else {
            boardVector[tmpY][tmpX] = CROSS;
            currentPlayer=0;
        }
        return 1;
    } else {
        std::cout << "this place is taken" << std::endl;
        return 0;
    }
}