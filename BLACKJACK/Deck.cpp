#include "Deck.hpp"

Deck::Deck() {
    position = 0;
    Card card;
    vector<char> suits = { 3,4,5,6 };
    vector<string> values = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
    for (int i = 0; i < 4; i++) {
        card.suit = suits[i];
        for (int j = 0; j < 13; j++) {
            card.value = values[j];
            cards.push_back(card);
        }
    }
}

void Deck::shuffle() {
    position = 0;
    srand(time(NULL));
    random_shuffle(cards.begin(), cards.end());
}

Deck::~Deck() {
    cards.clear();
}