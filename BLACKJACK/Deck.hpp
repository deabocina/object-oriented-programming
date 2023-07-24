#pragma once
#include "Card.hpp"

class Deck : public Card {
public:
    vector<Card> cards;
    int position;
    Deck();
    void shuffle();
    ~Deck();
};