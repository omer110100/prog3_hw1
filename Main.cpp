// Omer Labinsky - 207880857
#include <iostream>
#include "Card.hpp"
#include "Deck.hpp"
#include "Player.hpp"
#include "Game.hpp"

int main() 
{
    Deck mainDeck;     // כאן הדק מתמלא
    mainDeck.shuffle(); // ועכשיו הוא באמת מתערבב

    Player player1("Alice");
    Player player2("Bob");

    for (int i = 0; i < 26; i++) {
        player1.addCard(mainDeck.draw());
        player2.addCard(mainDeck.draw());
    }

    Game warGame(player1, player2);

    while (!warGame.isGameOver()) {
        warGame.playRound();
    }

    Player winner = warGame.checkWinner();
    std::cout << "\nWinner is: " << winner.getName() << std::endl;

    return 0;
}

