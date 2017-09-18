#include "card.hpp"

#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
#include <algorithm>

std::random_device rng;
std::minstd_rand prng;

void print_deck(const std::vector<Card>& deck) {
    int i = 1;

    for (Card c : deck) {
        std::cout << c << " ";
        if (i % 13 == 0) {
            std::cout << "\n";
            i = 0;
        }
        i++;
    }

    std::cout << '\n';
}


bool card_greater(Card a, Card b) {
  return a > b;
}


int main()
{
    prng.seed(rng());

    std::vector<Card> deck; //Create vector to represent the deck
    deck.reserve(52); //Get another storage for 52 objects
    for (int r = Ace; r <= King; r++) {
        for (int s = Hearts; s <= Spades; s++) {
            Card c{static_cast<Rank>(r), static_cast<Suit>(s)};
            deck.push_back(c);
        }
    }

    print_deck(deck);

    std::shuffle(deck.begin(), deck.end(), prng);
    print_deck(deck);

    std::sort(deck.begin(), deck.end());
    print_deck(deck);

    std::shuffle(deck.begin(), deck.end(), prng);
    std::sort(deck.begin(), deck.end(), [](Card a, Card b) { // lambda expression
        return a > b;
    });
    print_deck(deck);

    std::shuffle(deck.begin(), deck.end(), prng);
    std::sort(deck.begin(), deck.end(), card_greater);
    print_deck(deck);

    std::shuffle(deck.begin(), deck.end(), prng);
    std::sort(deck.begin(), deck.end(), [](Card a, Card b) { // lambda expression
        return a.getSuit() < b.getSuit();
    });
    print_deck(deck);


    return 0;
}
