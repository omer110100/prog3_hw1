// Omer Labinsky - 207880857
#include "Player.hpp"
#include <cstring>

/*
 * בנאי רגיל: מבצע Deep Copy לשם
 */
Player::Player(const char* n)
{
    if (n == nullptr) {
        name = nullptr;
    } else {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
}

/*
 * Copy Constructor: העתקה עמוקה של name ושל hand (Deck)
 */
Player::Player(const Player& other)
    : hand(other.hand)  // מפעיל Copy Constructor של Deck
{
    if (other.name == nullptr) {
        name = nullptr;
    } else {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }
}

/*
 * Operator= : העתקה עמוקה מלאה
 */
Player& Player::operator=(const Player& other)
{
    if (this == &other)
        return *this;

    delete[] name;

    if (other.name == nullptr) {
        name = nullptr;
    } else {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }

    hand = other.hand;  // העתקת Deck (עמוקה)

    return *this;
}

/*
 * Destructor: משחרר את ה-name
 */
Player::~Player()
{
    delete[] name;
}

/*
 * addCard: מוסיף קלף ליד
 */
void Player::addCard(const Card& c)
{
    hand.addCard(c);
}

/*
 * playCard: שולף קלף מראש היד
 */
Card Player::playCard()
{
    return hand.draw();
}

/*
 * hasCards: האם יש לשחקן קלפים ביד?
 */
bool Player::hasCards() const
{
    return hand.getCardCount() > 0;
}
