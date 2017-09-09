#ifndef CARD_HPP
#define CARD_HPP

#include <utility>

enum Rank {
    Ace,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King
};

enum Suit {
    Hearts,
    Diamonds,
    Clubs,
    Spades
};

class Card {
    private:
        Rank rank;
        Suit suit;

    public:
        Card() = default;
        Card(Rank r, Suit s) : rank(r), suit(s) {}
//        Card(const Card &c) : rank(c.rank), (c.suit) {} // Copy constructor
//
//        Card& operator=(const Card &c) { // Copy assignment operator
//            rank = c.rank;
//            suit = c.suit;
//            return *this;
//        }

        Rank getRank() const {return rank;}
        Suit getSuit() const {return suit;}
};

#endif // CARD_HPP


