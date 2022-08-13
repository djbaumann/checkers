#ifndef _PIECE_HPP_
#define _PIECE_HPP_

#include <iostream>
#include <string>
#include <memory>
#include "../include/player.hpp"

namespace Checkers {

enum PieceColor { BLACK_PC, WHITE_PC, UNDEFINED_PC };
enum PieceState { CAPTURED_PS, NORMAL_PS, KING_PS };

class Piece {
 public:
  Piece() : mColor(UNDEFINED_PC), mState(NORMAL_PS), mpPlayer(nullptr) {}
  Piece(PieceColor color) : mColor(color), mState(NORMAL_PS), mpPlayer(nullptr) {}
  Piece(PieceColor color, std::shared_ptr<Player> owner) : mColor(color), mState(NORMAL_PS), mpPlayer(owner) {}

  inline PieceColor getColor() const { return mColor; }
  std::string getColorStr() const;
  inline void setColor(PieceColor color) { mColor = color; }

  inline std::shared_ptr<Player> getOwner() const { return mpPlayer; }
  inline void setOwner(std::shared_ptr<Player> newOwner) {mpPlayer = newOwner;}

  inline void capture() { mState = CAPTURED_PS; }
  inline void king() { if (mState != CAPTURED_PS) mState = KING_PS; }
  inline bool isCaptured() const { return mState == CAPTURED_PS; }
  inline bool isNormal() const { return mState == NORMAL_PS; }
  inline bool isKing() const { return mState == KING_PS; }

  friend std::ostream& operator<<(std::ostream& os, const Piece& square);

 private:
  PieceColor mColor;
  PieceState mState;
  std::shared_ptr<Player> mpPlayer;
};

}  // namespace Checkers

#endif  // _PIECE_HPP_
