// Omer Labinsky - 207880857
#ifndef CARD_HPP
#define CARD_HPP

#include <cstring>

// Suit enum
enum Suit { Hearts, Spades, Diamonds, Clubs };

class Card {
private:
    Suit suit;
    char* rank;

public:
    Card();
    Card(Suit s, const char* r);
    Card(const Card& other);
    Card& operator=(const Card& other);
    ~Card();

    Suit getSuit() const { return suit; }
    const char* getRank() const { return rank; }

    int getValue() const;   // ← חדש
};

#endif
