
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

namespace lab6 {
    // Default constructor
    doubly_linked_list::doubly_linked_list() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    // Take in a vector of inputs and construct a doubly linked list from them
    doubly_linked_list::doubly_linked_list(std::vector<unsigned> values) {
        node *temp;
        size = values.size();
        head = new node(values[0]);
        head->prev = nullptr;
        head->next = nullptr;
        temp = head;
        for(int i=1;i<size;i++)
        {
            temp->next = new node(values[i]);
            temp->next->prev = temp;
            temp = temp->next;
            temp->next = nullptr;
        }
        tail = temp;
    }

// Copy constructor
    doubly_linked_list::doubly_linked_list(const doubly_linked_list &original) {
        size = original.size;
        node *temp_original;
        node *temp_this;
        temp_original = original.head;
        if(temp_original== nullptr)
            head = tail = nullptr;
        else
        {
            head = new node(temp_original->data);
            head->prev = nullptr;
            head->next = nullptr;
            temp_this = head;
            temp_original = temp_original->next;
            while(temp_original!= nullptr)
            {
                temp_this->next = new node(temp_original->data);
                temp_this->next->prev = temp_this;
                temp_this = temp_this->next;
                temp_this->next = nullptr;
                temp_original = temp_original->next;
            }
        }
        tail = temp_this;

    }

    // Create doubly linked linked list with one input value
    doubly_linked_list::doubly_linked_list(unsigned input) {

        tail = head = new node(input);
        size = 1;
        head->prev = nullptr;
        tail->next = nullptr;
    }

    // Default destructor
    doubly_linked_list::~doubly_linked_list() {

        while(!is_empty())
            remove((0));

    }

// return the value inside of the node located at position
    unsigned doubly_linked_list::get_data(unsigned position) {
        unsigned return_value = 0;
        if (position >= size || position < 0) {
            std::cout << "invalid size::" << std::endl;
        } else {
            node *temp;
            temp = head;
            for (unsigned i = 0; i < position ; i++)
                temp = temp->next;
            return_value = temp->data;
        }

        return return_value;
    }

    // Get a set of values between position_from to position_to
    std::vector<unsigned> doubly_linked_list::get_set(unsigned position_from, unsigned position_to) {

        unsigned i, k = 0;
        std::vector<unsigned> values(position_to - position_from + 1);
        node *temp;
        temp = head;
        for (i = 0; i < position_from; i++)
            temp = temp->next;
        while (i <= position_to) {
            values[k] = temp->data;
            temp = temp->next;
            i++;
            k++;
        }
        return values;
    }

    // Add a value to the end of the list
    void doubly_linked_list::append(unsigned data) {

        if(head== nullptr){
            head = tail = new node(data);
            size++;
        }
        else{
            node *temp;
            temp = new node(data);
            temp->next = nullptr;
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
            size++;
        }

    }

    // Merge two lists together in place, placing the input list at the end of this list
    void doubly_linked_list::merge(doubly_linked_list rhs) {

        if(rhs.head==this->head)
        {
            doubly_linked_list temp(rhs);
            this->tail->next = temp.head;
            temp.head->prev = this->tail;
            this->tail = temp.tail;
            size = size + size;
        }
        else if(rhs.head != nullptr)
        {
            size+=rhs.get_size();
            this->tail->next = rhs.head;
            rhs.head->prev = this->tail;
            this->tail = rhs.tail;
        }

    }

// Allow for the merging of two lists using the + operator.
    doubly_linked_list doubly_linked_list::operator+(doubly_linked_list &rhs) {

        std::vector<unsigned> values(this->get_size() + rhs.get_size());
        node *temp = this->head;
        int i = 0;
        while (temp!= nullptr) {
            values[i] = temp->data;
            i++;
            temp = temp->next;
        }
        temp = rhs.head;
        while (temp) {
            values[i] = temp->data;
            i++;
            temp = temp->next;
        }
        doubly_linked_list result(values);
        return result;


    }

    // Insert a node before the node located at position
    void doubly_linked_list::insert_before(unsigned position, unsigned data) {

        if (position >= size || position < 0) {
            std::cout << "Wrong position entered";
        } else {
            node *temp;
            temp = head;
            for (unsigned i = 0; i < position - 1; i++)
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

        if (position >= size || position < 0) {
            std::cout << "Wrong position entered";
        } else {
            node *temp;
            temp = head;
            for (unsigned i = 0; i < position; i++)
                temp = temp->next;
            node *temp1 = new node(data);
            node *temp2 = temp->next;
            temp1->prev = temp;
            temp1->next = temp2;
            temp2->prev = temp1;
            temp->next = temp1;
        }
    }

    // Remove the node located at position from the linked list
    void doubly_linked_list::remove(unsigned position) {
        if (position >= size || position < 0)
        {
            std::cout << "Wrong position entered";
        }
        else if (size == 1){
            delete head;
            head = tail = nullptr;
            size=0;
        }
        else if(position==0)
        {
            node *temp;
            temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
            size--;
        }
        else
        {
            node *temp_remove_node;
            temp_remove_node = head;
            for (unsigned i = 0; i < position; i++)
                temp_remove_node = temp_remove_node->next;
            node *temp_previous = temp_remove_node->prev;
            node *temp_after = temp_remove_node->next;
            temp_previous->next = temp_after;
            temp_after->prev = temp_previous;
            delete temp_remove_node;
            size--;
        }

    }

// Split the list with the node being split on being included in the returned list
    doubly_linked_list doubly_linked_list::split_before(unsigned position) {

        if(position>=size || position<0)
        {
            std::cout<<"Wrong position entered:";
            return *this;
        }
        else
        {
            doubly_linked_list return_list;
            return_list.tail = this->tail;
            node *temp;
            temp = this->head;
            for(int i=0;i<position;i++)
                temp = temp->next;
            return_list.head = temp;
            this->tail = temp->prev;
            this->tail->next = nullptr;
            return_list.head->prev = nullptr;
            return_list.size = size-position;
            size = position;
            return return_list;
        }


    }

// Split the list with the node being split on being included in the retained list
    doubly_linked_list doubly_linked_list::split_after(unsigned position) {

        if(position>=size || position<0)
        {
            std::cout<<"Wrong position entered:";
            return *this;
        }
        else
        {
            doubly_linked_list return_list;
            return_list.tail = this->tail;
            node *temp;
            temp = this->head;
            for(int i=0;i<position+1;i++)
                temp = temp->next;
            return_list.head = temp;
            temp->prev->next = nullptr;
            return_list.head->prev = nullptr;
            return_list.size = (size - position) - 1;
            size = position + 1;
            return return_list;
        }
    }

// Create two lists, one starting at position_from and ending with position_to and return that list
// Merge the beginning of the original list with the end of the original list and retain it
    doubly_linked_list doubly_linked_list::split_set(unsigned position_from, unsigned position_to) {

       if(position_from>=size || position_from<0||position_to>=size || position_to<0)
       {
           std::cout<<"Wrong position entered:";
           return *this;
       }
        else
       {
           node *temp1,*temp2;
           temp1 = head;
           temp2 = head;
           for(int i=0;i<position_from;i++)
               temp1 = temp1->next;
           for(int i=0;i<position_to;i++)
               temp2 = temp2->next;
           temp1->prev->next = temp2->next;
           temp2->next->prev = temp1->prev;
           temp1->prev = nullptr;
           temp2->next = nullptr;
           doubly_linked_list return_list;
           return_list.head = temp1;
           return_list.tail = temp2;
           return_list.size = position_to - position_from + 1;
           size = size - return_list.size;
           return return_list;
       }

    }

    // Swap two nodes in the list. USE POINTERS. Do not just swap the values!
    void doubly_linked_list::swap(unsigned position1, unsigned position2) {

        node *temp_position1 = head;
        node *temp_position2 = head;
        node *before_position1;
        node *after_position1;
        node *after_position2;
        node *before_position2;
        for (unsigned i = 0; i < position1; i++)
            temp_position1 = temp_position1->next;
        before_position1 = temp_position1->prev;
        after_position1 = temp_position1->next;
        for (unsigned i = 0; i < position2; i++)
            temp_position2 = temp_position2->next;
        after_position2 = temp_position2->next;
        before_position2 = temp_position2->prev;
        temp_position2->prev = temp_position1->prev;
        temp_position2->next = temp_position1->next;
        if(before_position1!= nullptr)
            before_position1->next = temp_position2;
        if(after_position1!= nullptr)
            after_position1->prev = temp_position2;

        temp_position1->next = after_position2;
        temp_position1->prev = before_position2;
        if(after_position2!= nullptr)
            after_position2->prev = temp_position1;
        if(before_position2!= nullptr)
            before_position2->next = temp_position1;
    }

    // Swap two sets of cards. The sets are inclusive. USE POINTERS!
    void doubly_linked_list::swap_set(unsigned position1_from, unsigned position1_to, unsigned position2_from,
                                      unsigned position2_to) {

        node *position1_start, *position1_end, *position2_start, *position2_end;
        position1_start = position1_end = position2_start = position2_end = head;
        if(position1_from >= size || position1_from < 0 || position1_to >= size || position1_to < 0
           ||position2_from >= size || position2_from < 0 || position2_to >= size || position2_to < 0)
        {
            std::cout<<"Wrong position entered";
        }
        for(int i=0;i<position1_from;i++)
            position1_start = position1_start->next;
        for(int i=0;i<position1_to;i++)
            position1_end = position1_end->next;
        for(int i=0; i<position2_from;i++)
            position2_start = position2_start->next;
        for(int i=0; i<position2_to;i++)
            position2_end = position2_end->next;

        node *p1_start_prev,*p1_end_next,*p2_start_prev,*p2_end_next;

        p1_start_prev = position1_start->prev;
        p1_end_next = position1_end->next;
        p2_start_prev = position2_start->prev;
        p2_end_next = position2_end->next;

        position1_start->prev = p2_start_prev;
        position1_end->next = p2_end_next;

        if(p1_start_prev != nullptr)
            p1_start_prev->next = position2_start;
        p1_end_next->prev = position2_end;

        p2_start_prev->next = position1_start;
        p2_end_next->prev = position1_end;

        position2_start->prev = p1_start_prev;
        position2_end->next = p1_end_next;

        if(position1_from == 0)
            head = position2_start;
        else if(position2_from == 0)
            head = position1_start;
        if(position1_to == (size-1))
            tail = position2_end;
        else if(position2_to == (size-1))
            tail = position1_end;

    }

// Overload operator=
    doubly_linked_list &doubly_linked_list::operator=(const doubly_linked_list &RHS) {



            this->size = RHS.size;
            node *temp_original;
            node *temp_this;
            temp_original = RHS.head;
            if(temp_original == nullptr)
            {
                this->head = this->tail = nullptr;
            }
            else
            {
                this->head = new node(temp_original->data);
                this->head->prev = nullptr;
                this->head->next = nullptr;
                temp_this = this->head;
                temp_original = temp_original->next;
                while(temp_original!= nullptr)
                {
                    temp_this->next = new node(temp_original->data);
                    temp_this->next->prev = temp_this;
                    temp_this = temp_this->next;
                    temp_this->next = nullptr;
                    temp_original = temp_original->next;

                }
                this->tail = temp_this;
            }

        return *this;
    }

// Append the rhs to the end of the this list
    doubly_linked_list &doubly_linked_list::operator+=(const doubly_linked_list &RHS) {


        if(RHS.head == nullptr)
            return *this;
        if(this->head!=RHS.head)
        {
            node *this_temp,*RHS_temp;
            this_temp = tail;
            RHS_temp = RHS.head;
            while(RHS_temp!= nullptr)
            {
                this_temp->next = new node(RHS_temp->data);
                this_temp->next->prev = this_temp;
                this_temp->next->next = nullptr;
                this_temp = this_temp->next;
                RHS_temp = RHS_temp->next;
            }
            this->size = this->size + RHS.size;
            this->tail = this_temp;
            return *this;
        }
        else
        {
            std::vector<unsigned> values(RHS.size);
            node *temp;
            temp = RHS.head;
            for(int i=0;temp!= nullptr;i++)
            {
                values[i] = temp->data;
                temp = temp->next;
            }
            lab6::doubly_linked_list temp_list(values);
            *this += temp_list;
            return *this;
        }
    }

    unsigned doubly_linked_list::get_size() {
        return size;
    }

    bool doubly_linked_list::is_empty() {
        return !size;
    }

    bool doubly_linked_list::operator==(const doubly_linked_list &rhs) const {
        node *iterL = head, *iterR = rhs.head;
        while (iterL != nullptr && iterR != nullptr) {
            if (iterL->data != iterR->data)
                return false;
            iterL = iterL->next;
            iterR = iterR->next;
        }
        return iterL == nullptr && iterR == nullptr;
    }

    std::string doubly_linked_list::to_string() {
        if (!head) return "";
        else {
            std::string output = "";
            output += std::to_string(head->data);
            node *to_return = head->next;
            while (to_return) {
                output += ", ";
                output += std::to_string(to_return->data);
                to_return = to_return->next;
            }
            return output;
        }
    }

    void doubly_linked_list::print() {
        node *temp;
        temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

}
