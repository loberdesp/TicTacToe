#include <iostream>
#include <vector>

enum squareStatus {EMPTY, CIRCLE, CROSS};

class boardClass {
    int width;
    int height;
    bool end;
    int tmpX, tmpY;
    int currentPlayer;
    
    std::vector<std::vector<squareStatus>> boardVector;
    
    public:
        boardClass();
        void displayBoard();
        void startGame();
        int playerMove();
        int playerPlace();
};