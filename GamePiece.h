// GamePiece.h

#ifndef EX2_GAMEPIECE_H
#define EX2_GAMEPIECE_H

#include <iostream>

#define WHITE 1
#define BLACK 2
#define BOARD_DIM 8

using namespace std;

/**
 * This class represents a general chess game piece. each piece has a location on the board, an life status and the
 * player it belongs too.
 */
class GamePiece
{
public:
    //Constructor
    /**
     * a Constructor for a new GamePiece.
     * @param line the line of the piece
     * @param row the row of the piece
     * @param player number of player, 1=WHITE, 2=BLACK
     * @param isAlive
     */
    GamePiece(int col, int row, int player, bool isAlive = true) : _col(col), _row(row), _player(player),
                                                                 _isAlive(isAlive)
    {

    }

    /**
     * Default destructor
     */
    ~GamePiece() = default;

    //Setters
    /**
     * a setter for line
     * @param newLine the new line position
     */
    void setCol(int newCol)
    {
        GamePiece::_col = newCol;
    }

    /**
     * a stter for a row
     * @param newRow the new row position
     */
    void setRow(int newRow)
    {
        GamePiece::_row = newRow;
    }

    /**
     * a getter for the player's num
     * @return
     */
    int getPlayerNum() const
    {
        return _player;
    }

    /**
     * prints the piece to the board, 1=WHITE, 2=BLACK
     */
    virtual void printPiece()
    {

    }


    /**
     * Moves the piece to a new position
     * @param row the new row
     * @param col the new column
     */
    virtual void move(int row, int col);

    /**
     * Checks legality of move - if the move is legal for that particular piece and if necessary checks if other
     * pieces are in the route
     * @param newRow the new row
     * @param newCol the new column
     * @param board the current playing board
     * @return
     */
    virtual int checkMove(int newRow, int newCol, GamePiece* (&board)[BOARD_DIM][BOARD_DIM])
    {
        (void)newRow;
        (void)newCol;
        (void)board;
        return 0;
    }

    /**
     * returns the type of the piece
     * @return type of the piece - string representation
     */
    virtual string getType()
    {
        return std::string();
    }

    /**
     * returns true if the piece has already moved once, false otherwise
     * @return returns true if the piece has already moved once, false otherwise
     */
    virtual bool hasMoved()
    {
        return false;
    }

protected:
    int _col, _row; /** position of piece */
    int _player; /** number of the player, 1 - white, 2 - black */
    bool _isAlive; /** indicator for the life status */
};


#endif //EX2_GAMEPIECE_H
