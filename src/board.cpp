#include "../include/board.hpp"
#include "../include/piece.hpp"
#include <memory>
#include <iostream>

static const int NUM_PIECES = 12;

Checkers::Board::Board() {
  SquareColor color;
  // reserve space for board squares
  mBoard.reserve(MAX_BOARD_COLUMN + 1);
  for (int col = A; col <= MAX_BOARD_COLUMN; ++col) {
    mBoard[col].reserve(MAX_BOARD_ROW + 1);
  }
  // populate board squares
  for (int row = EIGHT; row >= ONE; row--) {
    for (int col = A; col <= MAX_BOARD_COLUMN; ++col) {
      if ((col + row) % 2 == 0) {
        color = BLACK_SC;
      } else {
        color = WHITE_SC;
      }
      mBoard[col][row] = (Square(color));
    }
  }
  // initialize pieces
  mWhitePieces.reserve(NUM_PIECES);
  mBlackPieces.reserve(NUM_PIECES);

  for (int i = 0; i < NUM_PIECES; ++i) {
    mWhitePieces[i] = std::shared_ptr<Piece>(new Piece(WHITE_PC));
    mBlackPieces[i] = std::shared_ptr<Piece>(new Piece(BLACK_PC));
  }
  resetWhite();
  resetBlack();
}

// white @ A1 C1 E1 G1 / B2 D2 F2 H2 / A3 C3 E3 G3
void Checkers::Board::resetWhite() {
  mBoard[A][ONE].addPiece(mWhitePieces[0]);
  mBoard[C][ONE].addPiece(mWhitePieces[1]);
  mBoard[E][ONE].addPiece(mWhitePieces[2]);
  mBoard[G][ONE].addPiece(mWhitePieces[3]);
  mBoard[B][TWO].addPiece(mWhitePieces[4]);
  mBoard[D][TWO].addPiece(mWhitePieces[5]);
  mBoard[F][TWO].addPiece(mWhitePieces[6]);
  mBoard[H][TWO].addPiece(mWhitePieces[7]);
  mBoard[A][THREE].addPiece(mWhitePieces[8]);
  mBoard[C][THREE].addPiece(mWhitePieces[9]);
  mBoard[E][THREE].addPiece(mWhitePieces[10]);
  mBoard[G][THREE].addPiece(mWhitePieces[11]);
}

// black @ B6 D6 F6 H6 / A7 C7 E7 G7 / B8 D8 F8 H8
void Checkers::Board::resetBlack() {
  mBoard[B][SIX].addPiece(mBlackPieces[0]);
  mBoard[D][SIX].addPiece(mBlackPieces[1]);
  mBoard[F][SIX].addPiece(mBlackPieces[2]);
  mBoard[H][SIX].addPiece(mBlackPieces[3]);
  mBoard[A][SEVEN].addPiece(mBlackPieces[4]);
  mBoard[C][SEVEN].addPiece(mBlackPieces[5]);
  mBoard[E][SEVEN].addPiece(mBlackPieces[6]);
  mBoard[G][SEVEN].addPiece(mBlackPieces[7]);
  mBoard[B][EIGHT].addPiece(mBlackPieces[8]);
  mBoard[D][EIGHT].addPiece(mBlackPieces[9]);
  mBoard[F][EIGHT].addPiece(mBlackPieces[10]);
  mBoard[H][EIGHT].addPiece(mBlackPieces[11]);
}

void Checkers::Board::printBoard() const{
  char columnLetter = 'A';
  // print headers
  for (int col = ONE; col <= MAX_BOARD_COLUMN; ++col) {
    std::cout << "  |   " << char(columnLetter + col) << " ";
  }
  std::cout << std::endl;
  for (int i = 0; i <= MAX_BOARD_COLUMN; ++i) {
    std::cout << "--+-----";
  }
  std::cout << '-' << std::endl;
  for (int row = EIGHT; row >= ONE; row--) {
    // print line number
    std::cout << row + 1 << " ";
    // square color
    for (int col = A; col <= MAX_BOARD_COLUMN; ++col) {
      Square square = mBoard[col][row];
      if (mBoard[col][row].getColor() == BLACK_SC) {
        std::cout << "|XXXXXXX";
      } else {
        std::cout << "|       ";
      }
      // std::cout << "| " << (square) << ' ';
    }
    std::cout << std::endl << "  ";
    // piece color (if any)
    for (int col = A; col <= MAX_BOARD_COLUMN; ++col) {
      if (mBoard[col][row].hasPiece()) {
        std::cout << "|[" << (mBoard[col][row].getPiece()->getColorStr()) << ']';
      } else {
        if (mBoard[col][row].getColor() == BLACK_SC) {
          std::cout << "|XXXXXXX";
        } else {
          std::cout << "|       ";
        }
      }
    }
    // horizontal line
    std::cout << std::endl;
    for (int i = 0; i <= MAX_BOARD_COLUMN; ++i) {
      std::cout << "--+-----";
    }
    std::cout << '-' << std::endl;
  }
}

bool Checkers::Board::isValidMove(Checkers::Coordinate start, Checkers::Coordinate finish) const {
  bool isValid = false;
  Square startSquare = mBoard[start.first][start.second];
  Square finishSquare = mBoard[start.first][start.second];
  if (startSquare.hasPiece() && !finishSquare.hasPiece()) {

  }

  return isValid;
}
