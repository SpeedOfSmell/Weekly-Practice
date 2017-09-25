#include "card.hpp"
#include "deck.hpp"
#include "game.hpp"

#include <iostream>
#include <iomanip>
#include <vector>
#include <random>

int main()
{
    srand(time(0)); // For shuffling the deck
    int runs = 100;
    int total = 0;

    for (int i = 0; i < runs; i++) {
        Game game;
        game.run();
        total += game.turn;
    }

    std::cout << "Average length of a game of war: " << total / runs;

    return 0;
}

