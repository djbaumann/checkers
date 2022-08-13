#include <iostream>

#include "checkers.hpp"

int main() {
  Checkers::Game myGame;

  myGame.namePlayer1("Madi");
  myGame.namePlayer2("David");

  std::cout << "Player 1: " << myGame.getPlayer1().get_name() << std::endl;
  std::cout << "Player 2: " << myGame.getPlayer2().get_name() << std::endl;

  std::cout << "Hi " << myGame.getPlayer1().get_name() << "!" << std::endl;
  std::cout << "Hi " << myGame.getPlayer2().get_name() << "!" << std::endl;

  myGame.showBoard();
}
