#include "game.hpp"

void Game::run() {
    turn = 0;
    deck = {};
    for (int i = 0; i < options.numDecks; i++ )
        deck = makeCombinedDeck(deck, makeStandardDeck());

    shuffle(deck);

    while (!deck.empty()) {
        dealOne(deck, p1);
        dealOne(deck, p2);
    }

    while (winner == "") {
        step();
        turn++;
    }

    if (p1.pile.empty() && p2.pile.empty())
        std::cout << "Tie!";
    else if (p1.pile.empty())
        std::cout << "Player 2 wins!";
    else if (p2.pile.empty())
        std::cout << "Player 1 wins!";

    std::cout << " Turns: " << turn << "\n";
}

void Game::step() {
    Player *roundWinner = nullptr;

    while (roundWinner == nullptr) {
        if (p1.pile.empty() && p2.pile.empty()) {
            winner = "It's a tie!";
            break;
        } else if (p1.pile.empty()) {
            winner = "Player 2 wins!";
            break;
        } else if (p2.pile.empty()) {
            winner = "Player 1 wins!";
            break;
        }

        Card p1Card = p1.pile.front();
        Card p2Card = p2.pile.front();

        std::cout << "Player 1: " << p1Card << " - Player 2: " << p2Card << std::endl; // Display the cards
        spoils.push_back(p1Card); // Place the cards in the spoils pile
        spoils.push_back(p2Card);

        p1.pile.pop(); // Remove them from each players' pile
        p2.pile.pop();

        if (p1Card > p2Card) {
            std::cout << "Player 1 wins, taking " << spoils.size() << " cards." << std::endl;
            roundWinner = &p1;
        } else if (p1Card < p2Card) {
            std::cout << "Player 2 wins, taking " << spoils.size() << " cards." << std::endl;
            roundWinner = &p2;
        } else {
            std::cout << "War!" << std::endl << "Sacrificing " << options.numSacrifices << " cards each." << std::endl;
            for (int i = 0; i < options.numSacrifices && !p1.pile.empty() && !p2.pile.empty(); i++) {
                spoils.push_back(p1.pile.front());
                spoils.push_back(p2.pile.front());
                p1.pile.pop();
                p2.pile.pop();
            }
        }
    }

    if (roundWinner != nullptr) {
        for (Card card : spoils) { // Go through the spoils and give the winner every card
            roundWinner->pile.push(card);
            spoils.clear();
        }
    }

    std::cout << std::endl;

}

void dealOne(Deck &deck, Player &player) {
    player.pile.push(deck.back());
    deck.pop_back();
}
