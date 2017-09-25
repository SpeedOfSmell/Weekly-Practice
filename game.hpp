#include "deck.hpp"
#include "player.hpp"

#include <vector>

#pragma once

struct Options {
    int numDecks = 1;
    bool aceHigh = true;
    int numSacrifices = 1;
    bool negotiableSacrifice = true;
};

struct Game {
    void step();
    void run();

    Options options;
    Deck deck;
    Player p1;
    Player p2;
    std::string winner = "";
    std::vector<Card> spoils;
    int turn;
};

void dealOne(Deck &deck, Player &player);

