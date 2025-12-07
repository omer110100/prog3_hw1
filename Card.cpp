// Omer Labinsky - 207880857
#include "Card.hpp"
#include <cstring>

/*
 * בנאי ברירת מחדל — חובה כדי שנוכל ליצור מערכים של Card
 */
Card::Card()
{
    suit = Hearts;
    rank = nullptr;
}

/*
 * בנאי רגיל — העתקה עמוקה של rank
 */
Card::Card(Suit s, const char* r)
{
    suit = s;

    if (r == nullptr) {
        rank = nullptr;
        return;
    }

    rank = new char[strlen(r) + 1];
    strcpy(rank, r);
}

/*
 * Copy Constructor — העתקה עמוקה של כל השדות
 */
Card::Card(const Card& other)
{
    suit = other.suit;

    if (other.rank == nullptr) {
        rank = nullptr;
        return;
    }

    rank = new char[strlen(other.rank) + 1];
    strcpy(rank, other.rank);
}

/*
 * Operator=
 */
Card& Card::operator=(const Card& other)
{
    if (this == &other)
        return *this;

    delete[] rank;

    suit = other.suit;

    if (other.rank != nullptr) {
        rank = new char[strlen(other.rank) + 1];
        strcpy(rank, other.rank);
    } else {
        rank = nullptr;
    }

    return *this;
}

/*
 * Destructor — משחרר את המחרוזת
 */
Card::~Card()
{
    delete[] rank;
}

int Card::getValue() const
{
    const char* ranks[] = {
        "2","3","4","5","6","7","8","9","10",
        "Jack","Queen","King","Ace"
    };

    for (int i = 0; i < 13; i++) {
        if (strcmp(rank, ranks[i]) == 0)
            return i; // הערך של הקלף
    }

    return -1; // במקרה של טעות (לא אמור לקרות)
}
