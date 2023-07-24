#include "Player.hpp"

void Player::deal(Deck& deck) {
    int value = 0;
    hand.push_back(deck.cards[deck.position]);
    deck.position += 1;
    if (hand[hand.size() - 1].value == "A") {
        value = 1;
    }
    else if (hand[hand.size() - 1].value == "K" || hand[hand.size() - 1].value == "Q" || hand[hand.size() - 1].value == "J") {
        value = 10;
    }
    else {
        value = stoi(hand[hand.size() - 1].value);
    }
    sum += value;
}

void Player::check() {
    int value;
    if (hand[hand.size() - 1].value == "A" && sum < 11) {
        do {
            system("cls");
            cout << "Would you like your Ace to count as 1 or 11? ";
            cin >> value;
        } while (value != 1 && value != 11);
        
        if (value == 11) {
            sum += 10;
        }
    }
}

void Player::remove() {
    while (hand.size() > 0) {
        hand.pop_back();
    }
    sum = 0;
}