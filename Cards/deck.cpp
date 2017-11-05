#include "deck.hpp"

#include <iostream>
#include <random>
#include <algorithm>

Deck makeStandardDeck() {
    Deck d;
    d.reserve(52);

    for (int suitInt = Hearts; suitInt <= Spades; suitInt++) {
        for (int rankInt = Ace; rankInt <= King; rankInt++) {
            Suited card (static_cast<Suit>(suitInt), static_cast<Rank>(rankInt));
            d.push_back(card);
        }
    }

    d.push_back(Joker(Black));
    d.push_back(Joker(Red));

    return d;
}

Deck
makeCombinedDeck(const Deck& d1, const Deck& d2)
{
    Deck d;
    d.insert(d.end(), d1.begin(), d1.end());
    d.insert(d.end(), d2.begin(), d2.end());
    return d;
}

void
shuffle(Deck& d)
{
    std::random_shuffle(d.begin(), d.end());
}

