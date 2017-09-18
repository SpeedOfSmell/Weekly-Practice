#ifndef CARD_HPP
#define CARD_HPP

#include <utility>
#include <iosfwd>


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

// Equality comparison
bool operator==(Card a, Card b);
bool operator!=(Card a, Card b);

// Ordering
bool operator<(Card a, Card b);
bool operator>(Card a, Card b);
bool operator<=(Card a, Card b);
bool operator>=(Card a, Card b);

std::ostream& operator<<(std::ostream& os, Card c);
std::ostream& operator<<(std::ostream& os, Rank r);
std::ostream& operator<<(std::ostream& os, Suit s);


#endif // CARD_HPP


