#include "card.hpp"
#include "deck.hpp"

#include <iostream>
#include <iomanip>
#include <vector>
#include <random>

std::random_device rng;
std::minstd_rand prng;

int main()
{
    Deck deck = makeStandardDeck();
    Deck deck2 = makeStandardDeck();

    shuffle(deck);
    shuffle(deck2);

    print(deck);
    print(deck2);

    Deck deck3 = makeCombinedDeck(deck, deck2);

    print(deck3);

    return 0;
}

