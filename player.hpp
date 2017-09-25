#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "card.hpp"

#include <vector>
#include <queue>

struct Player
{
    Player();

    std::queue<Card> pile;
    void printHand();
};

#endif // PLAYER_HPP
