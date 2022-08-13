#include "../include/square.hpp"

bool Checkers::Square::addPiece(std::shared_ptr<Piece> pNewPiece) {
  if (!hasPiece()) {
    mpPiece = pNewPiece;
    return true;
  }
  return false;
}

bool Checkers::Square::removePiece() {
  if (hasPiece()) {
    mpPiece = nullptr;
    return true;
  }
  return false;
}

std::ostream& Checkers::operator<<(std::ostream& os,
                                   const Checkers::Square& square) {
  if (square.mColor == Checkers::WHITE_SC) {
    os << "White";
  } else if (square.mColor == Checkers::BLACK_SC) {
    os << "Black";
  } else {
    os << "Undef";
  }
  return os;
}
