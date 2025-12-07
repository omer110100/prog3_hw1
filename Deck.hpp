// Omer Labinsky - 207880857
#ifndef DECK_HPP
#define DECK_HPP

#include "Card.hpp"

class Deck {
private:
    Card* cards;
    int cardCount;

public:
    Deck();
    Deck(const Deck& other);
    Deck& operator=(const Deck& other);
    ~Deck();

    void shuffle();
    Card draw();
    void addCard(const Card& c);   // ← חשוב! מוסיף קלף ליד

    int getCardCount() const { return cardCount; }
};


#endif
