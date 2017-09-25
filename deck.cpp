#include "deck.hpp"

#include <iostream>
#include <random>
#include <algorithm>

/*
Deck makeStandardDeck() {
    Deck d = {
        {Suited, .info={.sc={Ace, Spades}}},
        {Suited, .info={.sc={Two, Spades}}},
        {Suited, .info={.sc={Three, Spades}}},
        {Suited, .info={.sc={Four, Spades}}},
        {Suited, .info={.sc={Five, Spades}}},
        {Suited, .info={.sc={Six, Spades}}},
        {Suited, .info={.sc={Seven, Spades}}},
        {Suited, .info={.sc={Eight, Spades}}},
        {Suited, .info={.sc={Nine, Spades}}},
        {Suited, .info={.sc={Ten, Spades}}},
        {Suited, .info={.sc={Jack, Spades}}},
        {Suited, .info={.sc={Queen, Spades}}},
        {Suited, .info={.sc={King, Spades}}},

        {Suited, .info={.sc={Ace, Clubs}}},
        {Suited, .info={.sc={Two, Clubs}}},
        {Suited, .info={.sc={Three, Clubs}}},
        {Suited, .info={.sc={Four, Clubs}}},
        {Suited, .info={.sc={Five, Clubs}}},
        {Suited, .info={.sc={Six, Clubs}}},
        {Suited, .info={.sc={Seven, Clubs}}},
        {Suited, .info={.sc={Eight, Clubs}}},
        {Suited, .info={.sc={Nine, Clubs}}},
        {Suited, .info={.sc={Ten, Clubs}}},
        {Suited, .info={.sc={Jack, Clubs}}},
        {Suited, .info={.sc={Queen, Clubs}}},
        {Suited, .info={.sc={King, Clubs}}},

        {Suited, .info={.sc={Ace, Hearts}}},
        {Suited, .info={.sc={Two, Hearts}}},
        {Suited, .info={.sc={Three, Hearts}}},
        {Suited, .info={.sc={Four, Hearts}}},
        {Suited, .info={.sc={Five, Hearts}}},
        {Suited, .info={.sc={Six, Hearts}}},
        {Suited, .info={.sc={Seven, Hearts}}},
        {Suited, .info={.sc={Eight, Hearts}}},
        {Suited, .info={.sc={Nine, Hearts}}},
        {Suited, .info={.sc={Ten, Hearts}}},
        {Suited, .info={.sc={Jack, Hearts}}},
        {Suited, .info={.sc={Queen, Hearts}}},
        {Suited, .info={.sc={King, Hearts}}},

        {Suited, .info={.sc={Ace, Diamonds}}},
        {Suited, .info={.sc={Two, Diamonds}}},
        {Suited, .info={.sc={Three, Diamonds}}},
        {Suited, .info={.sc={Four, Diamonds}}},
        {Suited, .info={.sc={Five, Diamonds}}},
        {Suited, .info={.sc={Six, Diamonds}}},
        {Suited, .info={.sc={Seven, Diamonds}}},
        {Suited, .info={.sc={Eight, Diamonds}}},
        {Suited, .info={.sc={Nine, Diamonds}}},
        {Suited, .info={.sc={Ten, Diamonds}}},
        {Suited, .info={.sc={Jack, Diamonds}}},
        {Suited, .info={.sc={Queen, Diamonds}}},
        {Suited, .info={.sc={King, Diamonds}}},
    };

    return d;
}
*/

Deck makeStandardDeck() {
    Deck d;
    d.reserve(52);

    // Much easier to just loop through the enums to create the deck instead of doing it manually
    for (int suitInt = Hearts; suitInt <= Spades; suitInt++) {
        for (int rankInt = Ace; rankInt <= King; rankInt++) {
            d.push_back({Suited, .info={.sc={static_cast<Rank>(rankInt), static_cast<Suit>(suitInt)}}});
        }
    }

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

void
print(const Deck& deck)
{
    int i = 1;
    for (Card c : deck) {
        std::cout << c << ' ';
        if (i % 13 == 0) {
            std::cout << '\n';
            i = 0;
        }
        ++i;
    }

    std::cout << '\n';
}

