#include <iostream>
#include "GameBoard.h"

/**
 * main function which fully runs a Chess Game
 */
int main()
{
    GameBoard comp;
    string move;
    do
    {
        comp.cleanBoard();
        comp.printBoard();
        comp.warnIfCheck();
        do
        {
            move = comp.getMove();
        }
        while (comp.makeMove(move));
        comp.changeTurn();
    }
    while (comp.checkWinner());
    return EXIT_SUCCESS;
}