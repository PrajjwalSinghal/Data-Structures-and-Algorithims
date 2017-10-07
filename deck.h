#ifndef UNTITLED1_DECK_H
#define UNTITLED1_DECK_H


#include "doubly_linked_list.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>

class deck {
    doubly_linked_list cards;
    std::map<int, std::string> card_rules;

public:
    deck();
    deck(std::string rules, std::string deck_list);

    std::vector<std::string> load(std::string file);//should be called twice in constructor
    void save(std::string file); //use if wanted to save deck state to new file

    void riffle_shuffle();
    void overhand_shuffle_front();
    void overhand_shuffle_back();

    deck draw(unsigned number_of_cards);//draw from top of deck
    deck pull(unsigned position1);//pull from anywhere in deck
    deck pull_multiple(unsigned number_of_card, unsigned position); //pull an arbitrary number of cards from somewhere in the deck
    deck split(unsigned position); // Split the deck at a certain position and return the new deck
    deck* deal(unsigned number_of_players, unsigned number_of_cards);//to deal in a circle. Return an array of each new hand
    void burn(); // Remove and destroy a card from the deck

    std::string check_card(unsigned position);//return the value of key in dictionary for a card in deck

    friend std::ostream& operator << (std::ostream& stream, const deck rhs);//print whole deck
    //TODO: create definitions for all functions
};


#endif //UNTITLED1_DECK_H