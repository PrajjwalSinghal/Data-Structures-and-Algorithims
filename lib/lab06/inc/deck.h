#ifndef CMPE126F17_LABS_LIB_LAB06_INC_DECK_H
#define CMPE126F17_LABS_LIB_LAB06_INC_DECK_H
/* NOTE THIS CLASS WILL BE FINISHED FOR YOU, YOU DO NOT NEED TO WRITE ANY CODE FOR THIS CLASS*/

#include "doubly_linked_list.h"
#include <string>
#include <map>

namespace lab6 {
    class deck {
        doubly_linked_list cards;
        std::map<int, std::string> card_rules;

    public:
        deck();

        deck(std::string rules, std::string deck_list);

        std::vector<std::string> load(std::string file);//should be called twice in constructor

        void riffle_shuffle();

        void overhand_shuffle();

        deck draw(unsigned number_of_cards);//draw from top of deck
        deck
        pull(unsigned position, unsigned number_of_card); //pull an arbitrary number of cards from somewhere in the deck
        deck split(unsigned position); // Split the deck at a certain position and return the new deck
        deck operator+(const deck &rhs) const;//returns deck with *this appended to rhs does not alter *this or rhs
        deck &operator=(const deck &rhs);

        deck &operator+=(const deck &rhs);

        std::vector<deck> deal(unsigned number_of_players,
                               unsigned number_of_cards);//to deal in a circle. Return an array of each new hand
        void burn(); // Remove and destroy a card from the deck

        std::string check_card(unsigned position);//return the value of key in dictionary for a card in deck
        unsigned size();

        friend std::ostream &operator<<(std::ostream &stream, deck rhs);//print whole deck
    };
}

#endif //CMPE126F17_LABS_LIB_LAB06_INC_DECK_H
