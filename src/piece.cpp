#include "../include/piece.hpp"
#include <string>

std::string Checkers::Piece::getColorStr() const {
  if (mColor == WHITE_PC) {
    return "White";
  } else if (mColor == BLACK_PC) {
    return "Black";
  } else {
    return "Undef";
  }
}

std::ostream& Checkers::operator<<(std::ostream& os,
                                   const Checkers::Piece& piece) {
  os << piece.getColorStr();
  return os;
}
