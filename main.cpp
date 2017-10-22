#include <iostream>
#include <iomanip>
#include <random>

#include "card.hpp"
#include "deck.hpp"

using namespace std;

int main()
{
    srand(time(0));

    Deck deck = makeStandardDeck();
    shuffle(deck);

    return 0;
}
