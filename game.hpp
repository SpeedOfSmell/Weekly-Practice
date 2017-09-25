#include "deck.hpp"

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
    /*
    Player p1;
    Player p2;
    Pile pile;
    int turn;
    */
};
