// Omer Labinsky - 207880857
#include "Game.hpp"
#include <iostream>
#include <vector>

Game::Game(const Player& p1, const Player& p2)
    : player1(p1), player2(p2), gameOver(false)
{
}

/*
 *  playRound — סיבוב רגיל
 */
void Game::playRound()
{
    if (gameOver) return;
    if (!player1.hasCards() || !player2.hasCards()) {
        gameOver = true;
        return;
    }

    Card c1 = player1.playCard();
    Card c2 = player2.playCard();

    std::cout << player1.getName() << " plays: " << c1.getRank() << std::endl;
    std::cout << player2.getName() << " plays: " << c2.getRank() << std::endl;

    // במקרה של תיקו — WAR
    if (c1.getValue() == c2.getValue()) {
        std::vector<Card> tableCards;
        tableCards.push_back(c1);
        tableCards.push_back(c2);
        std::cout << "Tie — starting WAR...\n";
        resolveWar(tableCards, c1, c2);
        return;
    }

    // מנצח רגיל
    if (c1.getValue() > c2.getValue()) {
        player1.addCard(c1);
        player1.addCard(c2);
        std::cout << player1.getName() << " wins the round!\n";
    } 
    else {
        player2.addCard(c1);
        player2.addCard(c2);
        std::cout << player2.getName() << " wins the round!\n";
    }
}

/*
 * resolveWar — WAR אמיתי לפי החוקים
 */
void Game::resolveWar(std::vector<Card>& tableCards, Card c1, Card c2)
{
    int v1 = c1.getValue();
    int v2 = c2.getValue();

    while (v1 == v2)
    {
        // בדיקה אם יש מספיק קלפים
        if (player1.getNumberOfCards() < 2) {
            std::cout << player1.getName() 
                      << " cannot continue WAR (not enough cards). GAME OVER.\n";

            // כל הקלפים של Alice עוברים ל-Bob
            while (player1.hasCards())
                player2.addCard(player1.playCard());
            for (Card& c : tableCards)
                player2.addCard(c);

            gameOver = true;
            return;
        }

        if (player2.getNumberOfCards() < 2) {
            std::cout << player2.getName() 
                      << " cannot continue WAR (not enough cards). GAME OVER.\n";

            while (player2.hasCards())
                player1.addCard(player2.playCard());
            for (Card& c : tableCards)
                player1.addCard(c);

            gameOver = true;
            return;
        }

        // כל שחקן מניח קלף הפוך
        Card p1down = player1.playCard();
        Card p2down = player2.playCard();
        tableCards.push_back(p1down);
        tableCards.push_back(p2down);

        // כל שחקן מניח קלף גלוי
        Card p1up = player1.playCard();
        Card p2up = player2.playCard();
        tableCards.push_back(p1up);
        tableCards.push_back(p2up);

        std::cout << player1.getName() << " plays: " << p1up.getRank() << std::endl;
        std::cout << player2.getName() << " plays: " << p2up.getRank() << std::endl;

        v1 = p1up.getValue();
        v2 = p2up.getValue();
        c1 = p1up;
        c2 = p2up;
    }

    // מנצח WAR
    if (v1 > v2) {
        std::cout << player1.getName() << " wins the WAR!\n";
        for (Card& c : tableCards)
            player1.addCard(c);
    }
    else {
        std::cout << player2.getName() << " wins the WAR!\n";
        for (Card& c : tableCards)
            player2.addCard(c);
    }
}

/*
 * checkWinner — מי מנצח?
 */
Player Game::checkWinner()
{
    if (player1.getNumberOfCards() > player2.getNumberOfCards())
        return player1;
    return player2;
}

bool Game::isGameOver() const
{
    return gameOver;
}
