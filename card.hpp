#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
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

enum Color {
    Black,
    Red
};

class SuitedCard {
    private:
        Rank rank;
        Suit suit;

    public:
        SuitedCard() = default;
        SuitedCard(Rank r, Suit s) : rank(r), suit(s) {}

        Rank getRank() const { return rank; }
        Suit getSuit() const { return suit; }
};

struct JokerCard {
    Color color;
};

union CardInfo {
    SuitedCard sc;
    JokerCard jc;
};

enum CardKind {
    Suited,
    Joker
};

class Card {
    private:
        CardKind kind;
        CardInfo info;
    public:
        Card() = default;
        Card(CardKind k, CardInfo i) : kind(k), info(i) {}

        CardKind getKind() const { return kind; }
        CardInfo getInfo() const { return info; }
};

// Equality comparison
bool operator==(Card a, Card b);
bool operator!=(Card a, Card b);

// Ordering
bool operator<(Card a, Card b);
bool operator>(Card a, Card b);
bool operator<=(Card a, Card b);
bool operator>=(Card a, Card b);

std::ostream& operator<<(std::ostream& os, const Card c);
std::ostream& operator<<(std::ostream& os, const Rank r);
std::ostream& operator<<(std::ostream& os, const Color c);
std::ostream& operator<<(std::ostream& os, const Suit s);


#endif // CARD_HPP


