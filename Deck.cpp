// Omer Labinsky - 207880857
#include "Deck.hpp"
#include <cstdlib>
#include <ctime>
#include <cstring>

/*
 * בנאי — יוצר חבילת קלפים מלאה (52 קלפים)
 */
Deck::Deck()
{
    cardCount = 52;
    cards = new Card[cardCount];

    const char* ranks[] = {
        "2","3","4","5","6","7","8","9","10",
        "Jack","Queen","King","Ace"
    };

    int index = 0;

    for (int s = Hearts; s <= Clubs; s++) {
        for (int r = 0; r < 13; r++) {
            cards[index] = Card((Suit)s, ranks[r]);
            index++;
        }
    }
}

/*
 * Copy Constructor — העתקה עמוקה מלאה
 */
Deck::Deck(const Deck& other)
{
    cardCount = other.cardCount;
    cards = new Card[cardCount];

    for (int i = 0; i < cardCount; i++) {
        cards[i] = other.cards[i];
    }
}

/*
 * Operator= — העתקה עמוקה
 */
Deck& Deck::operator=(const Deck& other)
{
    if (this == &other)
        return *this;

    delete[] cards;

    cardCount = other.cardCount;
    cards = new Card[cardCount];

    for (int i = 0; i < cardCount; i++) {
        cards[i] = other.cards[i];
    }

    return *this;
}

/*
 * Destructor — שחרור המערך הדינמי
 */
Deck::~Deck()
{
    delete[] cards;
}

/*
 * draw — שליפת קלף מהחלק העליון של החבילה
 */
Card Deck::draw()
{
    if (cardCount == 0) {
        return Card(Hearts, "Empty");
    }

    Card top = cards[0];

    for (int i = 1; i < cardCount; i++) {
        cards[i - 1] = cards[i];
    }

    cardCount--;

    return top;
}

/*
 * shuffle — ערבוב בשיטת Fisher–Yates
 */
void Deck::shuffle()
{
    srand(time(NULL));

    for (int i = cardCount - 1; i > 0; i--) {
        int j = rand() % (i + 1);

        Card temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

/*
 * addCard — מוסיף קלף לסוף החבילה
 */
void Deck::addCard(const Card& c)
{
    // 1. מקצים מערך חדש בגודל גדול ב־1
    Card* newArr = new Card[cardCount + 1];

    // 2. מעתיקים את כל הקלפים הקיימים
    for (int i = 0; i < cardCount; i++) {
        newArr[i] = cards[i];   // שימוש ב־operator= של Card
    }

    // 3. מוסיפים את הקלף החדש בסוף
    newArr[cardCount] = c;

    // 4. משחררים את המערך הישן
    delete[] cards;

    // 5. מעדכנים מצביע וכמות
    cards = newArr;
    cardCount++;
}
