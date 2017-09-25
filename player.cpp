#include "player.hpp"

Player::Player()
{
    //ctor
}

void Player::printHand() {
    std::queue<Card> temp = pile;

    while (!temp.empty()) {
        std::cout << temp.front() << " ";
        temp.pop();
    }

    std::cout << std::endl;
}
