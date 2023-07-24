#pragma once
#include "Card.hpp"
#include "Deck.hpp"

class Player : public Card {
public:
    int sum, wallet;
    vector<Card> hand;
    void deal(Deck& deck);
    void check();
    void remove();
};