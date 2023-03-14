#include <iostream>
#include <vector>

enum squareStatus {EMPTY, CIRCLE, CROSS};

class boardClass {
    int width, height;
    int tmpX, tmpY;
    bool end, error;
    int currentPlayer, moveCount;
    std::vector<std::vector<squareStatus>> boardVector;
    
    public:
        boardClass();
        void displayBoard();
        void startGame();
        int playerMove();
        int playerPlace();
        void checkWinEnd();
};