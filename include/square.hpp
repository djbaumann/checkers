#ifndef _SQUARE_HPP_
#define _SQUARE_HPP_

#include <iostream>
#include <string>
#include <memory>
#include "../include/piece.hpp"

namespace Checkers {

enum SquareColor { BLACK_SC, WHITE_SC, UNDEFINED_SC };

class Square {
 public:
  Square() : mColor(UNDEFINED_SC), mpPiece(nullptr) {}
  Square(SquareColor color) : mColor(color), mpPiece(nullptr) {}

  inline SquareColor getColor() const { return mColor; }
  inline void setColor(SquareColor color) { mColor = color; }

  inline bool hasPiece() const { return mpPiece != nullptr; }
  inline std::shared_ptr<Piece> getPiece() const { return mpPiece; }
  bool addPiece(std::shared_ptr<Piece> pNewPiece);
  bool removePiece();

  friend std::ostream& operator<<(std::ostream& os, const Square& square);

 private:
  SquareColor mColor;
  std::shared_ptr<Piece> mpPiece;
};

}  // namespace Checkers

#endif  // _SQUARE_HPP_
