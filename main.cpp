#include <iostream>
#include "card.hpp"

#include <vector>

int main()
{
    std::vector<Card> deck; //Create vector to represent the deck
    deck.reserve(52); //Get another storage for 52 objects
    for (int r = Ace; r <= King; r++) {
        for (int s = Hearts; s <= Spades; s++) {
            Card c{static_cast<Rank>(r), static_cast<Suit>(s)};
            deck.push_back(c);
        }
    }

    for (Card c : deck) {
        std::cout << c.getRank() << " of " << c.getSuit() << std::endl;
    }

    return 0;
}
