#ifndef UNTITLED1_DOUBLY_LINKED_LIST_H
#define UNTITLED1_DOUBLY_LINKED_LIST_H

#include "node.h"
#include <vector>
#include <iostream>

class doubly_linked_list {
    node *head, *tail;
    unsigned size;

public:
    doubly_linked_list();
    doubly_linked_list(unsigned input);
    doubly_linked_list(std::vector <unsigned> values );
    doubly_linked_list(const doubly_linked_list& original);
    ~doubly_linked_list();

    unsigned get_data(unsigned position);
    std::vector<unsigned> get_set(unsigned position_from, unsigned position_to);
    unsigned get_size();
    bool is_empty();

    void append(unsigned data);
    void merge(doubly_linked_list rhs);
    void insert_before(unsigned position, unsigned data);
    void insert_after(unsigned position, unsigned data);
    void remove(unsigned position);

    doubly_linked_list split_before(unsigned position);
    doubly_linked_list split_after(unsigned position);
    doubly_linked_list split_set(unsigned position_from, unsigned position_to);

    void swap(unsigned position1, unsigned position2);
    void swap_set(unsigned position1_from, unsigned position1_to, unsigned position2_from, unsigned position2_to);

    doubly_linked_list operator+( doubly_linked_list& rhs );//returns list with *this appended to rhs does not alter *this or rhs
    doubly_linked_list &operator=(const doubly_linked_list& RHS);
    doubly_linked_list &operator+=(const doubly_linked_list& RHS);
    void print();
};


#endif //UNTITLED1_DOUBLY_LINKED_LIST_H
