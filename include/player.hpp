#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <string>

namespace Checkers {

// give each player a set of pieces
// assign pieces to positions on board by pointer
class Player {
  public:
    Player() : m_name("") {}
    Player(std::string name) : m_name(name) {}

    inline std::string get_name() { return m_name; }
    inline void set_name(std::string new_name) { m_name = new_name; }

  private:
    std::string m_name;
};

} // namespace checkers

#endif  // _PLAYER_HPP_
