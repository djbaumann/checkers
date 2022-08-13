#ifndef _CHECKERS_HPP_
#define _CHECKERS_HPP_

#include <string>

#include "board.hpp"
#include "player.hpp"

namespace Checkers {

class Game {
 public:
  Game();

  inline Player getPlayer1() { return mPlayer1; }
  inline Player getPlayer2() { return mPlayer2; }
  inline Board getBoard() { return mGameBoard; }

  inline void namePlayer1(const std::string name) { mPlayer1.set_name(name); }
  inline void namePlayer2(const std::string name) { mPlayer2.set_name(name); }

  inline void showBoard() { mGameBoard.printBoard(); }

 private:
  // Board
  Board mGameBoard;

  // Players
  Player mPlayer1;
  Player mPlayer2;
};

}  // namespace Checkers

#endif  // _CHECKERS_HPP_
