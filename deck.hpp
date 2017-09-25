#include "card.hpp"

#include <vector>

using Deck = std::vector<Card>;

Deck makeStandardDeck();
Deck makeCombinedDeck(const Deck &d1, const Deck &d2);
void shuffle(Deck &deck);
void print(const Deck &deck);

