// Omer Labinsky - 207880857
#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include "Player.hpp"

class Game {
private:
    Player player1;
    Player player2;
    bool gameOver;

public:
    Game(const Player& p1, const Player& p2);

    void playRound();
    void resolveWar(std::vector<Card>& tableCards, Card c1, Card c2);

    Player checkWinner();
    bool isGameOver() const;
};

#endif
