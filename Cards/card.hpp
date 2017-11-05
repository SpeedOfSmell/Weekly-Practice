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

struct Card {
    int id;
};

struct Suited : Card {
    Suited(Suit s, Rank r) :
        suit(s), rank(r){}

    Suit suit;
    Rank rank;
};

struct Joker : Card {
    Joker(Color c) : color(c) {}

    Color color;
};


#endif // CARD_HPP


