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