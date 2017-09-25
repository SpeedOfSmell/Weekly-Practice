#include <iostream>

#include "card.hpp"


bool
operator==(Card a, Card b)
{
    if (a.getKind() == b.getKind() == Suited) { // If they're both normal cards
        return a.getInfo().sc.getRank() == b.getInfo().sc.getRank() &&
        a.getInfo().sc.getSuit() == b.getInfo().sc.getSuit();
    } else if (a.getKind() == b.getKind() == Joker) { // If they're both jokers
        return a.getInfo().jc.color == b.getInfo().jc.color;
    } else { // Can't be the same if the kind is different
        return false;
    }
}

bool
operator!=(Card a, Card b)
{
  return !(a == b);
}


bool
operator<(Card a, Card b)
{
    if (a.getKind() == b.getKind() == Suited) { // If they're both normal cards
        return a.getInfo().sc.getRank() < b.getInfo().sc.getRank();
    } else if (a.getKind() == b.getKind() == Joker) { // If they're both jokers
        return a.getInfo().jc.color < b.getInfo().jc.color;
    } else {
        if (a.getKind() == Suited) // Jokers are higher value than suited cards
            return true;
        else
            return false;
    }
}

bool
operator>(Card a, Card b)
{
  return b < a;
}

bool
operator<=(Card a, Card b)
{
  return !(b < a);
}

bool
operator>=(Card a, Card b)
{
  return !(a < b);
}

std::ostream&
operator<<(std::ostream& os, const Rank r)
{
  switch (r) {
    case Ace:
      os << 'A';
      break;
    case Two:
      os << '2';
      break;
    case Three:
      os << '3';
      break;
    case Four:
      os << '4';
      break;
    case Five:
      os << '5';
      break;
    case Six:
      os << '6';
      break;
    case Seven:
      os << '7';
      break;
    case Eight:
      os << '8';
      break;
    case Nine:
      os << '9';
      break;
    case Ten:
      os << 'T';
      break;
    case Jack:
      os << 'J';
      break;
    case Queen:
      os << 'Q';
      break;
    case King:
      os << 'K';
      break;
  }
  return os;
}

std::ostream&
operator<<(std::ostream& os, const Suit s)
{
  switch (s) {
    case Hearts:
      os << 'H';
      break;
    case Diamonds:
      os << 'D';
      break;
    case Clubs:
      os << 'C';
      break;
    case Spades:
      os << 'S';
      break;
  }
  return os;
}

std::ostream&
operator<<(std::ostream& os, const Color c)
{
  switch (c) {
    case Black:
      os << 'B';
      break;
    case Red:
      os << 'R';
      break;
  }
  return os;
}

std::ostream&
operator<<(std::ostream& os, const Card c)
{
    if (c.getKind() == Suited)
        return os << c.getInfo().sc.getRank() << c.getInfo().sc.getSuit();
    else if (c.getKind() == Joker)
        return os << 'J' << c.getInfo().jc.color;
}


