#include "GameBoard.h"


/**
 * a constructor which initializes a game board
 */
GameBoard::GameBoard()
{
    cout << "Enter white player name:\n";
    cin >> _player1Name;
    cout << "Enter black player name:\n";
    cin >> _player2Name;
    _currentTurn = WHITE;
    _whiteKingPos[0] = 7;
    _whiteKingPos[1] = 4;
    _blackKingPos[0] = 0;
    _blackKingPos[1] = 4;

    for (int i = 0 ; i < BOARD_DIM ; i++)
    {
        {
            _board[1][i] = new Soldier(i, 1, BLACK); //creates 8 black soldiers in the second row
            _board[6][i] = new Soldier(i, 6, WHITE); //creates 8 white soldiers in the 2nd last row
        }
    }
    for (int i = 0 ; i < BOARD_DIM ; i++)
    {
        if (i == 0 || i == 7)
        {
            _board[0][i] = new Castle(i, 0, BLACK);
            _board[7][i] = new Castle(i, 7, WHITE);
        }
        else if (i == 1 || i == 6)
        {
            _board[0][i] = new Horse(i, 0, BLACK);
            _board[7][i] = new Horse(i, 7, WHITE);
        }
        else if (i == 2 || i == 5)
        {
            _board[0][i] = new Runner(i, 0, BLACK);
            _board[7][i] = new Runner(i, 7, WHITE);
        }
        else if (i == 3)
        {
            _board[0][i] = new Queen(i, 0, BLACK);
            _board[7][i] = new Queen(i, 7, WHITE);
        }
        else
        {
            _board[0][i] = new King(i, 0, BLACK);
            _board[7][i] = new King(i, 7, WHITE);
        }
    }
}

/**
 * this method prints the board
 */
void GameBoard::printBoard()
{
    cout << "  ABCDEFGH" << endl << endl;
    for (int i = 0 ; i < BOARD_DIM ; i++)
    {
        cout << (BOARD_DIM - i) << " ";
        for (int j = 0 ; j < BOARD_DIM ; j++)
        {
            if (_board[i][j] != nullptr)
            {
                _board[i][j]->printPiece();
            }
            else if ((i + j) % 2)
            {
                cout << GREEN_SPACE;
            }
            else
            {
                cout << BLUE_SPACE;
            }
        }
        cout << " " << (BOARD_DIM - i) << endl;
    }
    cout << "\n  ABCDEFGH\n";
}

/**
 * this method cleans the board
 */
void GameBoard::cleanBoard()
{
    cout << "\33[2J";
}
/**
 * checks if a given index exceeds the board borders
 * @param index index to check
 * @return 0 if the given index is a valid index in the board, 1 otherwise
 */
int GameBoard::_isIndexLegal(int index)
{
    if (index < 0 || index > 7)
    {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

/**
 * checks if a specific position is threatened by a queen, castle or a King (vertical &
 * horizontal check)
 * @param posToCheck - the current position to check
 * @return 1 if the position is threatened, 0 otherwise
 */
int GameBoard::_checkVerticHoriz(int posToCheck[2])
{
    int i = 1;
    while ((posToCheck[0] - i) >= 0)
    {
        GamePiece* pieceToCheck = _board[posToCheck[0] - i][posToCheck[1]];
        if  (pieceToCheck != nullptr)
        {
            if (pieceToCheck->getPlayerNum() != _currentTurn && ( pieceToCheck->getType() ==
                "Queen" || pieceToCheck->getType() == "Castle" || (i == 1 && pieceToCheck->getType
                () == "King")))
            {
                return EXIT_FAILURE;
            }
            else
            {
                break;
            }
        }
        i++;
    }
    i = 1;
    while ((posToCheck[0] + i) < BOARD_DIM)
    {
        GamePiece* pieceToCheck = _board[posToCheck[0] + i][posToCheck[1]];
        if  (pieceToCheck != nullptr)
        {
            if (pieceToCheck->getPlayerNum() != _currentTurn && ( pieceToCheck->getType() ==
                "Queen" || pieceToCheck->getType() == "Castle" || (i == 1 && pieceToCheck->getType
                () == "King")))
            {
                return EXIT_FAILURE;
            }
            else
            {
                break;
            }
        }
        i++;
    }
    i = 1;
    while ((posToCheck[1] + i) < BOARD_DIM)
    {
        GamePiece* pieceToCheck = _board[posToCheck[0]][posToCheck[1] + i];
        if  (pieceToCheck != nullptr)
        {
            if (pieceToCheck->getPlayerNum() != _currentTurn && ( pieceToCheck->getType() ==
                "Queen" || pieceToCheck->getType() == "Castle" || (i == 1 && pieceToCheck->getType
                () == "King")))
            {
                return EXIT_FAILURE;
            }
            else
            {
                break;
            }
        }
        i++;
    }
    i = 1;
    while ((posToCheck[1] - i) >= 0)
    {
        GamePiece* pieceToCheck = _board[posToCheck[0]][posToCheck[1] - i];
        if  (pieceToCheck != nullptr)
        {
            if (pieceToCheck->getPlayerNum() != _currentTurn && ( pieceToCheck->getType() ==
                "Queen" || pieceToCheck->getType() == "Castle" || (i == 1 && pieceToCheck->getType
                () == "King")))
            {
                return EXIT_FAILURE;
            }
            else
            {
                break;
            }
        }
        i++;
    }
    return EXIT_SUCCESS;
}

/**
 * checks if a specific position is threatened by a queen, runner or a King (diagonal check)
 * @param kingPos - the current position to check
 * @return 1 if the position is threatened, 0 otherwise
 */
int GameBoard::_checkDiagonal(int PosToCheck[2])
{
    int i = 1;
    while ((PosToCheck[0] - i) >= 0 && (PosToCheck[1] - i) >= 0)
    {
        GamePiece* pieceToCheck = _board[PosToCheck[0] - i][PosToCheck[1] - i];
        if  (pieceToCheck != nullptr)
        {
            if (pieceToCheck->getPlayerNum() != _currentTurn && ( pieceToCheck->getType() ==
                "Queen" || pieceToCheck->getType() == "Runner" || (i == 1 && pieceToCheck->getType
                () == "King")))
            {
                return EXIT_FAILURE;
            }
            else
            {
                break;
            }
        }
        i++;
    }
    i = 1;
    while ((PosToCheck[0] + i) < BOARD_DIM && (PosToCheck[1] - i) >= 0)
    {
        GamePiece* pieceToCheck = _board[PosToCheck[0] + i][PosToCheck[1] - i];
        if  (pieceToCheck != nullptr)
        {
            if (pieceToCheck->getPlayerNum() != _currentTurn && ( pieceToCheck->getType() ==
                "Queen" || pieceToCheck->getType() == "Runner" || (i == 1 && pieceToCheck->getType
                () == "King")))
            {
                return EXIT_FAILURE;
            }
            else
            {
                break;
            }
        }
        i++;
    }
    i = 1;
    while ((PosToCheck[0] - i) >= 0 && (PosToCheck[1] + i) < BOARD_DIM)
    {
        GamePiece* pieceToCheck = _board[PosToCheck[0] - i][PosToCheck[1] + i];
        if  (pieceToCheck != nullptr)
        {
            if (pieceToCheck->getPlayerNum() != _currentTurn && ( pieceToCheck->getType() ==
                "Queen" || pieceToCheck->getType() == "Runner" || (i == 1 && pieceToCheck->getType
                () == "King")))
            {
                return EXIT_FAILURE;
            }
            else
            {
                break;
            }
        }
        i++;
    }
    i = 1;
    while ((PosToCheck[0] + i) < BOARD_DIM && (PosToCheck[1] + i) < BOARD_DIM)
    {
        GamePiece* pieceToCheck = _board[PosToCheck[0] + i][PosToCheck[1] + i];
        if  (pieceToCheck != nullptr)
        {
            if (pieceToCheck->getPlayerNum() != _currentTurn && ( pieceToCheck->getType() ==
                "Queen" || pieceToCheck->getType() == "Runner" || (i == 1 && pieceToCheck->getType
                () == "King")))
            {
                return EXIT_FAILURE;
            }
            else
            {
                break;
            }
        }
        i++;
    }
    return EXIT_SUCCESS;
}
/**
 * checks if a specific position is threatened by a soldier
 * @param PosToCheck - the current position to check
 * @return 1 if the position is threatened, 0 otherwise
 */
int GameBoard::_soldierThreat(int PosToCheck[2])
{
    int step;
    if (_currentTurn == WHITE)
    {
        if (PosToCheck[0] == 0)
        {
            return EXIT_SUCCESS;
        }
        step = -1;
    }
    else
    {
        if (PosToCheck[0] == BOARD_DIM - 1)
        {
            return EXIT_SUCCESS;
        }
        step = 1;
    }
    if (PosToCheck[1] != 0 && _board[PosToCheck[0] + step][PosToCheck[1] - 1] != nullptr &&
        _board[PosToCheck[0] + step][PosToCheck[1] - 1]->getPlayerNum() != _currentTurn &&
        _board[PosToCheck[0] + step][PosToCheck[1] - 1]->getType() == "Soldier")
    {
        return EXIT_FAILURE;
    }

    if (PosToCheck[1] != BOARD_DIM - 1 && _board[PosToCheck[0] + step][PosToCheck[1] + 1] != nullptr &&
        _board[PosToCheck[0] + step][PosToCheck[1] + 1]->getPlayerNum() != _currentTurn &&
        _board[PosToCheck[0] + step][PosToCheck[1] + 1]->getType() == "Soldier")
    {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
/**
 * this method checks if a couple of indices in the board contains a horseman which threathens
 * a specific position
 * @param rowToCheck row index to check
 * @param colToCheck col index to check
 * @return 1 if the position is threathened, 0 otherwise
 */
int GameBoard::_checkHorseIndices(int rowToCheck, int colToCheck)
{
    if (!_isIndexLegal(rowToCheck) && !_isIndexLegal(colToCheck) && _board[rowToCheck][colToCheck] !=
        nullptr && _board[rowToCheck][colToCheck]->getPlayerNum() != _currentTurn &&
        _board[rowToCheck][colToCheck]->getType() == "Horse")
    {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

/**
 * checks if a specific position is threatened by a horseman
 * @param kingPos - the current position to check
 * @return 1 if the position is threatened, 0 otherwise
 */
int GameBoard::_horseThreat(int posToCheckg[2])
{
    int rowToCheck, colToCheck;

    rowToCheck = posToCheckg[0] - 2;
    colToCheck = posToCheckg[1] - 1;
    if (_checkHorseIndices(rowToCheck, colToCheck))
    {
        return EXIT_FAILURE;
    }
    colToCheck = posToCheckg[1] + 1;
    if (_checkHorseIndices(rowToCheck, colToCheck))
    {
        return EXIT_FAILURE;
    }
    rowToCheck = posToCheckg[0] + 2;
    if (_checkHorseIndices(rowToCheck, colToCheck))
    {
        return EXIT_FAILURE;
    }
    colToCheck = posToCheckg[1] - 1;
    if (_checkHorseIndices(rowToCheck, colToCheck))
    {
        return EXIT_FAILURE;
    }
    rowToCheck = posToCheckg[0] - 1;
    colToCheck = posToCheckg[1] - 2;
    if (_checkHorseIndices(rowToCheck, colToCheck))
    {
        return EXIT_FAILURE;
    }
    colToCheck = posToCheckg[1] + 2;
    if (_checkHorseIndices(rowToCheck, colToCheck))
    {
        return EXIT_FAILURE;
    }
    rowToCheck = posToCheckg[0] + 1;
    if (_checkHorseIndices(rowToCheck, colToCheck))
    {
        return EXIT_FAILURE;
    }
    colToCheck = posToCheckg[1] - 2;
    if (_checkHorseIndices(rowToCheck, colToCheck))
    {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}



/**
 * this method gets position indices, and returns whether this position is threatened or not
 * @param rowPos index of the row
 * @param colPos index of the col
 * @return 1 if this position is threatened, 0 otherwise
 */
int GameBoard::_isPositionThreatened(int rowPos, int colPos)
{
    int posToCheck[2] = {rowPos, colPos};
    if (_checkDiagonal(posToCheck) || _checkVerticHoriz(posToCheck) || _horseThreat(posToCheck) ||
        _soldierThreat(posToCheck))
    {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}



/**
 * checks if the current player's king is exposed and threatened
 * @return 1 if the king is exposed, 0 otherwise
 */
int GameBoard::_isKingThreatened()
{
    int *kingPos;
    if (_currentTurn == WHITE)
    {
        kingPos = _whiteKingPos;
    }
    else
    {
        kingPos = _blackKingPos;
    }
    return _isPositionThreatened(kingPos[0], kingPos[1]);

}

/**
 * performs all legality checks of a desired move, besides if it exposes the king
 * @param move - a string represents a move as given by the user
 * @return 0 if the move is legal, 1 otherwise
 */
int GameBoard::_isMoveLegal(string move)
{
    int currentCol = int(move[0]) - ASCII_NORM;
    int currentRow = ((((-1) * (int(move[1]) - BOARD_DIM)) % BOARD_DIM) + BOARD_DIM) % BOARD_DIM;
    int nextCol = int(move[2]) - ASCII_NORM;
    int nextRow = ((((-1) * (int(move[3]) - BOARD_DIM)) % BOARD_DIM) + BOARD_DIM) % BOARD_DIM;
    //checks if given move positions exceeds the board borders
    if (_isIndexLegal(currentRow) || _isIndexLegal(currentCol) || _isIndexLegal(nextRow) ||
        _isIndexLegal(nextCol))
    {
        cout << ILLEGAL_MOVE;
        return EXIT_FAILURE;
    }
    //checks if the current position's piece belongs to the opposite player
    if (_board[currentRow][currentCol] == nullptr || _board[currentRow][currentCol]->getPlayerNum()
        != _currentTurn)
    {
        cout << ILLEGAL_MOVE;
        return EXIT_FAILURE;
    }
    // checks if player tries to eat his own piece
    if (_board[nextRow][nextCol] != nullptr && _board[nextRow][nextCol]->getPlayerNum() ==
        _currentTurn)
    {
        cout << ILLEGAL_MOVE;
        return EXIT_FAILURE;
    }
    // checks if the move is legal for the specific type of game piece, and checks if it's a
    // valid move (no pieces in the way)
    if (_board[currentRow][currentCol]->checkMove(nextRow, nextCol, _board))
    {
        cout << ILLEGAL_MOVE;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

/**
 * this method performs a move after legality check
 * @param move - a string represents a move, as given by the user
 * @return 0 if the move is legal and performed, 1 otherwise
 */
int GameBoard::makeMove(string move)
{
    if (move == CASTLING_KING_SIDE)
    {
        return _castlingKingSide();
    }
    if (move == CASTLING_QUEEN_SIDE)
    {
        return _castlingQueenSide();
    }
    if (_isMoveLegal(move))
    {
        return EXIT_FAILURE;
    }
    int currentCol = int(move[0]) - ASCII_NORM;
    int currentRow = ((((-1) * (int(move[1]) - BOARD_DIM)) % BOARD_DIM) + BOARD_DIM) % BOARD_DIM;
    int nextCol = int(move[2]) - ASCII_NORM;
    int nextRow = ((((-1) * (int(move[3]) - BOARD_DIM)) % BOARD_DIM) + BOARD_DIM) % BOARD_DIM;
    //performs the move
    GamePiece* tempPiece = _board[nextRow][nextCol];
    _board[nextRow][nextCol] = _board[currentRow][currentCol];
    //updates the king's position in case the king moved
    if (_board[nextRow][nextCol]->getType() == "King")
    {
        if(_board[nextRow][nextCol]->getPlayerNum() == WHITE)
        {
            _whiteKingPos[0] = nextRow;
            _whiteKingPos[1] = nextCol;
        }
        else
        {
            _blackKingPos[0] = nextRow;
            _blackKingPos[1] = nextCol;
        }
    }
    _board[currentRow][currentCol] = nullptr;
    //checks if the king is threatened by the desired move, and cancels it if so
    if (_isKingThreatened())
    {
        _board[currentRow][currentCol] = _board[nextRow][nextCol];
        //updates back the king's position in case the king's move was rejected
        if (_board[currentRow][currentCol]->getType() == "King")
        {
            if(_board[nextRow][nextCol]->getPlayerNum() == WHITE)
            {
                _whiteKingPos[0] = currentRow;
                _whiteKingPos[1] = currentCol;
            }
            else
            {
                _blackKingPos[0] = currentRow;
                _blackKingPos[1] = currentCol;
            }
        }
        _board[nextRow][nextCol] = tempPiece;
        cout << ILLEGAL_MOVE;
        return EXIT_FAILURE;
    }
    if (_board[nextRow][nextCol]->getType() == "Soldier" &&
        nextRow == (BOARD_DIM - 1) * ((_currentTurn + 1) % 2)) // checks if a black soldier reached
        // the last row (7), or a white soldier reached the first row (0)
    {
        // transforms the soldier into a queen
        _board[nextRow][nextCol] = new Queen(nextCol, nextRow, _currentTurn);
    }
    _board[nextRow][nextCol]->move(nextRow, nextCol);
    return EXIT_SUCCESS;
}

/**
 * this method receives a move as input from user
 * @return string represents the desired move
 */
string GameBoard::getMove()
{
    if (_currentTurn == WHITE)
    {
        cout << _player1Name + MOVE_INPUT_MSG;
    }
    else
    {
        cout << _player2Name + MOVE_INPUT_MSG;
    }
    string move;
    cin >> move;
    return move;
}

/**
 * this method checks at the beginning of a turn if the player's king is exposed and warns him if so
 * @return 1 if the king is exposed, 0 otherwise
 */
int GameBoard::warnIfCheck()
{
    if (_isKingThreatened())
    {
        cout << CHECK_WARNING_MSG;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

/**
 * this method changes the current turn to the other player
 */
void GameBoard::changeTurn()
{
    if (_currentTurn == WHITE)
    {
        _currentTurn = BLACK;
    }
    else
    {
        _currentTurn = WHITE;
    }
}

/**
 * this method performs a castling by king side
 * @return 0 if castling was possible and performed, 1 otherwise
 */
int GameBoard::_castlingKingSide()
{
    //checks if the king is threatened in its current position
    if (_isKingThreatened())
    {
        cout << ILLEGAL_MOVE;
        return EXIT_FAILURE;
    }
    //check if castling is legal
    int *kingPos;
    if (_currentTurn == WHITE)
    {
        kingPos = _whiteKingPos;
    }
    else
    {
        kingPos = _blackKingPos;
    }

    //making sure the king and castle haven't moved
    if (_board[kingPos[0]][kingPos[1]]->hasMoved() || (_board[kingPos[0]][KING_CASTLE_COL]->getType
        () == "Castle" && _board[kingPos[0]][KING_CASTLE_COL]->hasMoved()))
    {

        cout << ILLEGAL_MOVE ;
        return EXIT_FAILURE;
    }
    //check for other pieces on route
    for (int i = kingPos[1] + 1; i < KING_CASTLE_COL; ++i)
    {
        if (_board[kingPos[0]][i] != nullptr)
        {
            cout << ILLEGAL_MOVE;
            return EXIT_FAILURE;
        }
    }
    //checks if the designated positions aren't threatened
    if (!_isPositionThreatened(kingPos[0], kingPos[1] + 1) &&
        !_isPositionThreatened(kingPos[0], kingPos[1] + 2))
    {
        //perform the move
        _board[kingPos[0]][kingPos[1] + 2] = _board[kingPos[0]][kingPos[1]]; //move the king
        _board[kingPos[0]][kingPos[1]] = nullptr;
        _board[kingPos[0]][kingPos[1] + 1] = _board[kingPos[0]][KING_CASTLE_COL]; //move the castle
        _board[kingPos[0]][KING_CASTLE_COL] = nullptr;
        kingPos[1] = kingPos[1] + 2; // updates the king's position attribute
    }
    return EXIT_SUCCESS;
}

/**
* this method performs a castling by queen side
* @return 0 if castling was possible and performed, 1 otherwise
*/
int GameBoard::_castlingQueenSide()
{
    //checks if the king is threatened in its current position
    if (_isKingThreatened())
    {
        cout << ILLEGAL_MOVE;
        return EXIT_FAILURE;
    }
    //check if castling is legal
    int *kingPos;
    if (_currentTurn == WHITE)
    {
        kingPos = _whiteKingPos;
    }
    else
    {
        kingPos = _blackKingPos;
    }
    //making sure the king and castle haven't moved
    if (_board[kingPos[0]][kingPos[1]]->hasMoved() ||
        (_board[kingPos[0]][QUEEN_CASTLE_COL]->getType() == "Castle" &&
        _board[kingPos[0]][QUEEN_CASTLE_COL]->hasMoved()))
    {
        cout << ILLEGAL_MOVE;
        return EXIT_FAILURE;
    }
    //check for other pieces on route
    for (int i = kingPos[1] - 1; i > QUEEN_CASTLE_COL; --i)
    {
        if (_board[kingPos[0]][i] != nullptr)
        {
            cout << ILLEGAL_MOVE;
            return EXIT_FAILURE;
        }
    }
    //checks if the designated position aren't threatened
    if (!_isPositionThreatened(kingPos[0], kingPos[1] - 1) &&
        !_isPositionThreatened(kingPos[0], kingPos[1] - 2))
    {
        //perform the move
        _board[kingPos[0]][kingPos[1] - 2] = _board[kingPos[0]][kingPos[1]]; //move the king
        _board[kingPos[0]][kingPos[1]] = nullptr;
        _board[kingPos[0]][kingPos[1] - 1] = _board[kingPos[0]][QUEEN_CASTLE_COL]; // move the castle
        _board[kingPos[0]][QUEEN_CASTLE_COL] = nullptr;
        kingPos[1] = kingPos[1] - 2; // updates the king's position attribute
    }
    return EXIT_SUCCESS;
}

/**
 * changes turns, and checks if the current player is in an unavoidable situation, and losing
 * @return 0 and declare winner if there is one, returns 1 if there is no
 */
int GameBoard::checkWinner()
{
    //if king isn't threatened in it's original position- there is no winner-return EXIT_FAILURE(1)
    if (!_isKingThreatened())
    {
        return EXIT_FAILURE;
    }
    int *kingPosToCheck;
    if (_currentTurn == WHITE)
    {
        kingPosToCheck = _whiteKingPos;
    }
    else
    {
        kingPosToCheck = _blackKingPos;
    }
    //check if the king can move to any surrounding cell, and escape the threat
    if (!_isIndexLegal(kingPosToCheck[0] + 1) && !_isIndexLegal(kingPosToCheck[1]) &&
        !(_board[kingPosToCheck[0] + 1][kingPosToCheck[1]] != nullptr &&
        _board[kingPosToCheck[0] + 1][kingPosToCheck[1]]->getPlayerNum() == _currentTurn) &&
        !_isPositionThreatened(kingPosToCheck[0] + 1, kingPosToCheck[1]))
    {
        return EXIT_FAILURE;
    }
    if (!_isIndexLegal(kingPosToCheck[0] - 1) && !_isIndexLegal(kingPosToCheck[1]) &&
        !(_board[kingPosToCheck[0] - 1][kingPosToCheck[1]] != nullptr &&
        _board[kingPosToCheck[0] - 1][kingPosToCheck[1]]->getPlayerNum() == _currentTurn) &&
        !_isPositionThreatened(kingPosToCheck[0] - 1, kingPosToCheck[1]))
    {
        return EXIT_FAILURE;
    }
    if (!_isIndexLegal(kingPosToCheck[0]) && !_isIndexLegal(kingPosToCheck[1] + 1) &&
        !(_board[kingPosToCheck[0]][kingPosToCheck[1] + 1] != nullptr &&
        _board[kingPosToCheck[0]][kingPosToCheck[1] + 1]->getPlayerNum() == _currentTurn) &&
        !_isPositionThreatened(kingPosToCheck[0], kingPosToCheck[1] + 1))
    {
        return EXIT_FAILURE;
    }
    if (!_isIndexLegal(kingPosToCheck[0]) && !_isIndexLegal(kingPosToCheck[1] - 1) &&
        !(_board[kingPosToCheck[0]][kingPosToCheck[1] - 1] != nullptr &&
        _board[kingPosToCheck[0]][kingPosToCheck[1] - 1]->getPlayerNum() == _currentTurn) &&
        !_isPositionThreatened(kingPosToCheck[0], kingPosToCheck[1] - 1))
    {
        return EXIT_FAILURE;
    }
    if (!_isIndexLegal(kingPosToCheck[0] + 1) && !_isIndexLegal(kingPosToCheck[1] + 1) &&
        !(_board[kingPosToCheck[0] + 1][kingPosToCheck[1] + 1] != nullptr &&
        _board[kingPosToCheck[0] + 1][kingPosToCheck[1] + 1]->getPlayerNum() == _currentTurn) &&
        !_isPositionThreatened(kingPosToCheck[0] + 1, kingPosToCheck[1] + 1))
    {
        return EXIT_FAILURE;
    }
    if (!_isIndexLegal(kingPosToCheck[0] - 1) && !_isIndexLegal(kingPosToCheck[1] - 1) &&
        !(_board[kingPosToCheck[0] - 1][kingPosToCheck[1] - 1] != nullptr &&
        _board[kingPosToCheck[0] - 1][kingPosToCheck[1] - 1]->getPlayerNum() == _currentTurn) &&
        !_isPositionThreatened(kingPosToCheck[0] - 1, kingPosToCheck[1] - 1))
    {
        return EXIT_FAILURE;
    }
    if (!_isIndexLegal(kingPosToCheck[0] + 1) && !_isIndexLegal(kingPosToCheck[1] - 1) &&
        !(_board[kingPosToCheck[0] + 1][kingPosToCheck[1] - 1] != nullptr &&
        _board[kingPosToCheck[0] + 1][kingPosToCheck[1] - 1]->getPlayerNum() == _currentTurn) &&
        !_isPositionThreatened(kingPosToCheck[0] + 1, kingPosToCheck[1] - 1))
    {
        return EXIT_FAILURE;
    }
    if (!_isIndexLegal(kingPosToCheck[0] - 1) && !_isIndexLegal(kingPosToCheck[1] + 1) &&
        !(_board[kingPosToCheck[0] - 1][kingPosToCheck[1] + 1] != nullptr &&
        _board[kingPosToCheck[0] - 1][kingPosToCheck[1] + 1]->getPlayerNum() == _currentTurn) &&
        !_isPositionThreatened(kingPosToCheck[0] - 1, kingPosToCheck[1] + 1))
    {
        return EXIT_FAILURE;
    }

    if (_currentTurn == WHITE)
    {
        cout << _player2Name + " won!" << endl;
    }
    else
    {
        cout << _player1Name + " won!" << endl;
    }
    return EXIT_SUCCESS;
}