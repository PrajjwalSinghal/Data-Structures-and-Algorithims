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

    int i,k=0;
    std::vector <unsigned> values(position_to-position_from+1);
    node *temp = head;
    for(i=0;i<position_from;i++)
        temp = temp->next;
    while(i<=position_to)
    {
        values[k] = temp->data;
        temp = temp->next;
        i++;
        k++;
    }
    return values;
}

// Add a value to the end of the list
void doubly_linked_list::append(unsigned data) {

    node *temp;
    temp = new node(data);
    temp->next = nullptr;
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
}

// Merge two lists together in place, placing the input list at the end of this list
void doubly_linked_list::merge(doubly_linked_list rhs) {

    this->tail->next = rhs.head;
    rhs.head->prev = this->tail;
}

// Allow for the merging of two lists using the + operator.
doubly_linked_list doubly_linked_list::operator+( doubly_linked_list &rhs)  {

    std::vector<unsigned> values(this->get_size()+rhs.get_size());
    node* temp = this->head;
    int i=0;
    while(temp)
    {
        values[i] = temp->data;
        i++;
        temp = temp->next;
    }
    temp = rhs.head;
    while(temp)
    {
        values[i] = temp->data;
        i++;
        temp = temp->next;
    }
    doubly_linked_list result(values);
    return result;
}

// Insert a node before the node located at position
void doubly_linked_list::insert_before(unsigned position, unsigned data) {

    if(position >= size)
    {
        std::cout<<"Wrong position entered";
    }
    else
    {
        node *temp = head;
        for(int i=0;i<position-1;i++)
            temp = temp->next;
        node *temp1 = new node(data);
        node *temp2 = temp->next;
        temp1->prev = temp;
        temp1->next = temp2;
        temp2->prev = temp1;
        temp->next = temp1;
    }
}

// Insert a node after the node located at position
void doubly_linked_list::insert_after(unsigned position, unsigned data) {

        if(position == (size-1))
            append(data);
        else
        {
            position++;
            insert_before(position,data);
        }

}

// Remove the node located at position from the linked list
void doubly_linked_list::remove(unsigned position) {
    node *temp_remove_node = head;
    for(int i=0;i<position;i++)
        temp_remove_node = temp_remove_node->next;
    node *temp_previous = temp_remove_node->prev;
    node *temp_after = temp_remove_node->next;
    temp_previous->next = temp_after;
    temp_after->prev = temp_previous;
    delete temp_remove_node;
    size--;
}

// Split the list with the node being split on being included in the returned list
doubly_linked_list doubly_linked_list::split_before(unsigned position) {

    node *temp = head;
    std::vector <unsigned> values(position);
    if(position>=size)
        std::cout<<"Wrong size entered";
    else
    {
        for(int i=0;i<position;i++)
        {
            values[i] = temp->data;
            temp = temp->next;
        }

        doubly_linked_list result(values);
        node *temp1 = temp;
        temp = temp->next;
        temp1->next = nullptr;
        temp->prev = nullptr;
        // temp1 = head;
        // while(temp1)
        //    remove(0);
        head = temp;
        size = size - result.get_size();
        return result;
    }

}

// Split the list with the node being split on being included in the retained list
doubly_linked_list doubly_linked_list::split_after(unsigned position) {
    doubly_linked_list result = this->split_before(position-1);
    return result;
}

// Create two lists, one starting at position_from and ending with position_to and return that list
// Merge the beginning of the original list with the end of the original list and retain it
doubly_linked_list doubly_linked_list::split_set(unsigned position_from, unsigned position_to) {

    int i,k=0;
    std::vector <unsigned> values(position_to-position_from);
    node *original_end_first;
    node *original_end_second;
    node *temp = head;
    for(i=0;i<position_from;i++)
        temp = temp->next;
    original_end_first = temp->prev;
    while(i<position_to)
    {
        values[k] = temp->data;
        k++;
        i++;
        temp = temp->next;
    }
    doubly_linked_list result(values);
    original_end_second = temp->next;
    original_end_first->next = original_end_second;
    original_end_second->prev = original_end_first;
    return result;
}

// Swap two nodes in the list. USE POINTERS. Do not just swap the values!
void doubly_linked_list::swap(unsigned position1, unsigned position2) {

    node *temp;
    node *temp_position1=head;
    node *temp_position2=head;
    node *before_position1;
    node *after_position1;
    node *after_position2;
    node *before_position2;
    for(int i=0;i<position1;i++)
        temp_position1 = temp_position1->next;
    before_position1 = temp->prev;
    after_position1 = temp->next;
    for(int i=0;i<position2;i++)
        temp_position2 = temp_position2->next;
    after_position2 = temp_position2->next;
    before_position2 = temp_position2->prev;
    temp_position2->prev = temp_position1->prev;
    temp_position2->next = temp_position1->next;
    before_position1->next = temp_position2;
    after_position1->prev = temp_position2;
    temp_position1->next = after_position2;
    temp_position1->prev = before_position2;
    after_position2->prev = temp_position1;
    before_position2->next = temp_position1;
}

// Swap two sets of cards. The sets are inclusive. USE POINTERS!
void doubly_linked_list::swap_set(unsigned position1_from, unsigned position1_to, unsigned position2_from,
                                  unsigned position2_to) {

}

// Overload operator=
doubly_linked_list &doubly_linked_list::operator=(const doubly_linked_list &RHS) {
    std::vector <unsigned> values(RHS.size);
    node *temp;
    for(int i=0;temp;i++)
    {
        values[i] = temp->data;
        temp = temp->next;
    }
    doubly_linked_list result(values);
    return result;
}

// Append the rhs to the end of the this list
doubly_linked_list &doubly_linked_list::operator+=(const doubly_linked_list &RHS) {
    std::vector <unsigned> values(this->size + RHS.size);
    node *temp = this->head;
    int i;
    for(i=0;temp;i++)
    {
        values[i] = temp->data;
        temp = temp->next;
    }
    temp = RHS.head;
    while(temp)
    {
        values[i] = temp->data;
        temp = temp->next;
        i++;
    }
    doubly_linked_list result(values);
        return result;
}

unsigned doubly_linked_list::get_size() {
    return size;
}

bool doubly_linked_list::is_empty() {
    return !size;
}