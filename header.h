#include <iostream>
#include <vector>

enum squareStatus {EMPTY, CIRCLE, CROSS};

class boardClass {
    int width;
    int height;
    std::vector<std::vector<squareStatus>> boardVector;
    
    public:
        boardClass();
        void displayBoard();
        void startGame();
};