#include "doubly_linked_list.h"
/*
 * You will be writing all of the code for each of these functions.
 * Remember, this is a doubly linked list, not an array. You need to
 * be using pointers, and not overwriting your values like you would
 * in an array.
 *
 * If you need to write auxiliary functions, you are more than welcome
 * to, but you can't change the signature of any of the functions we
 * have written.
 *
 * Information on doubly linked lists can be found at
 * https://en.wikipedia.org/wiki/Doubly_linked_list
 *
 * Hints: - Keep track of size. If you add or delete something, you
 *          need to change size.
 *        - This isn't an array, so moving things around is actually
 *          a lot easier. Just change the pointers to the objects.
 *        - Keep track of your edge cases; empty, 1 item, and 2 items
 *        - Some of these functions are basically the same thing,
 *          with the index shifted or return ignored. Don't rewrite
 *          code, just call the function with the 'correct' inputs.
 *        - Test your doubly linked list by itself before testing it
 *          in the deck class. It will make it easier to find any bugs
 *        - Use your debugger. It is your best friend for finding
 *          issues!
 *        - Don't forget to ask for help on Slack!
 *
 * We will be making changes throughout the week to the deck.cpp as
 * well as adding testing into the project. Make sure to pull and
 * merge frequently.
 */


// Default constructor
doubly_linked_list::doubly_linked_list() {
    head->next = head->prev=tail->next=tail->prev = nullptr;
    head->data=tail->data=0;
    size = 0;
}

// Take in a vector of inputs and construct a doubly linked list from them
doubly_linked_list::doubly_linked_list(std::vector<unsigned> values) {
    size = 0;
    int vector_size = values.size();
    node *temp = head;
    for(int i = 0;i<vector_size;i++)
    {
        temp = new node(values[i]);
        temp->next = tail;
        tail->prev = temp;
        temp = tail;
        size++;
    }
}

// Copy constructor
doubly_linked_list::doubly_linked_list(const doubly_linked_list& original) {

    node *temp1=original.head;
    head = tail = nullptr;
    this->head->prev=this->head->next = this->tail->prev=this->tail->next = nullptr;
    node *temp = head;
    while(temp1)
    {
        temp = new node(temp1->data);
        temp->next = tail;
        tail->prev = temp;
        temp = tail;
        temp->next = nullptr;
        temp1= temp1->next;
        size++;
    }

}

// Create doubly linked linked list with one input value
doubly_linked_list::doubly_linked_list(unsigned input) {

   if(is_empty())
   {
       tail = head = new node(input);
       head->next = nullptr;
       head->prev = nullptr;
       size++;
   }
   else
   {
       node *temp;
       temp = new node(input);
       tail->next = temp;
       temp->prev = tail;
       tail = temp;
       tail->next = nullptr;
   }




}

// Default constructor
doubly_linked_list::~doubly_linked_list() {
    node *temp;
    temp = head;
    while(is_empty())
    {
        head = head->next;
        delete temp;
        temp = head;
        size--;
    }

}

// return the value inside of the node located at position
unsigned doubly_linked_list::get_data(unsigned position) {

    unsigned return_value = 0;
    if( position>= size)
    {
        std::cout<<"invalid size::"<<std::endl;
    }
    else
    {
        node *temp;
        temp = head;
        for(int i=0; i<position;i++)
            temp = temp->next;
        return_value = temp->data;
    }

    return return_value;
}

// Get a set of values between position_from to position_to
std::vector<unsigned> doubly_linked_list::get_set(unsigned position_from, unsigned position_to) {

}

// Add a value to the end of the list
void doubly_linked_list::append(unsigned data) {

}

// Merge two lists together in place, placing the input list at the end of this list
void doubly_linked_list::merge(doubly_linked_list rhs) {

}

// Allow for the merging of two lists using the + operator.
doubly_linked_list doubly_linked_list::operator+(const doubly_linked_list &rhs) const {
//    return ;
}

// Insert a node before the node located at position
void doubly_linked_list::insert_before(unsigned position, unsigned data) {

}

// Insert a node after the node located at position
void doubly_linked_list::insert_after(unsigned position, unsigned data) {

}

// Remove the node located at position from the linked list
void doubly_linked_list::remove(unsigned position) {

}

// Split the list with the node being split on being included in the returned list
doubly_linked_list doubly_linked_list::split_before(unsigned position) {
//    return ;
}

// Split the list with the node being split on being included in the retained list
doubly_linked_list doubly_linked_list::split_after(unsigned position) {
//    return ;
}

// Create two lists, one starting at position_from and ending with position_to and return that list
// Merge the beginning of the original list with the end of the original list and retain it
doubly_linked_list doubly_linked_list::split_set(unsigned position_from, unsigned position_to) {
//    return ;
}

// Swap two nodes in the list. USE POINTERS. Do not just swap the values!
void doubly_linked_list::swap(unsigned position1, unsigned position2) {

}

// Swap two sets of cards. The sets are inclusive. USE POINTERS!
void doubly_linked_list::swap_set(unsigned position1_from, unsigned position1_to, unsigned position2_from,
                                  unsigned position2_to) {

}

// Overload operator=
doubly_linked_list &doubly_linked_list::operator=(const doubly_linked_list &RHS) {
//    return <#initializer#>;
}

// Append the rhs to the end of the this list
doubly_linked_list &doubly_linked_list::operator+=(const doubly_linked_list &RHS) {
//    return <#initializer#>;
}

unsigned doubly_linked_list::get_size() {
    return size;
}

bool doubly_linked_list::is_empty() {
    return !size;
}