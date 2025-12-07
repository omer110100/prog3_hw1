// Omer Labinsky - 207880857
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Deck.hpp"
#include <cstring>

class Player {
private:
    char* name;   // שם השחקן (דינמי – חייב Deep Copy)
    Deck hand;    // היד של השחקן

public:
    // בנאי רגיל
    Player(const char* n);

    // Copy Constructor
    Player(const Player& other);

    // Operator=
    Player& operator=(const Player& other);

    // Destructor
    ~Player();

    // פונקציות משחק
    void addCard(const Card& c);  // מוסיף קלף ליד
    Card playCard();              // מוציא קלף מהיד

    // פונקציות מידע
    const char* getName() const { return name; }
    int getNumberOfCards() const { return hand.getCardCount(); }

    // פונקציה חדשה — דרושה ל־Game
    bool hasCards() const;        // האם יש קלפים ביד?
};

#endif
