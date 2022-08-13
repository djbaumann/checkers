#ifndef _BOARD_HPP_
#define _BOARD_HPP_

#include <vector>
#include <memory>
#include "square.hpp"
#include "piece.hpp"

namespace Checkers {

enum BoardColumn { A, B, C, D, E, F, G, H };
const BoardColumn MIN_BOARD_COLUMN = A;
const BoardColumn MAX_BOARD_COLUMN = H;

enum BoardRow { ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT };
const BoardRow MIN_BOARD_ROW = ONE;
const BoardRow MAX_BOARD_ROW = EIGHT;

class Coordinate : public std::pair<BoardColumn, BoardRow> {};

class Board {
  public:
    Board();

    void printBoard() const;

    bool movePiece(Piece piece, Coordinate newCoordinate);

    // std::vector<Coordinate> calculateAllowedMovesFrom(Coordinate) const;

  private:
    std::vector< std::vector<Checkers::Square> > mBoard;
    std::vector< std::shared_ptr<Piece> > mWhitePieces;
    std::vector< std::shared_ptr<Piece> > mBlackPieces;

    void resetWhite();
    void resetBlack();

    bool isValidMove(Coordinate start, Coordinate finish) const;
};

} // namespace checkers

#endif
