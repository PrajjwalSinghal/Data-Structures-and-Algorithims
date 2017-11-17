#include <iostream>
#include "../inc/stack.h"

namespace lab5 {
    stack::stack() : head(nullptr), size(0) {}

    stack::stack(std::string &data) {
        head = new node(data);
        size = 1;
    }

    stack::stack(const stack &original) {
        if (original.head != nullptr) {
            node *original_tmp = original.head;
            node *tmp = head = new node(original_tmp->data);
            size = original.size;

            original_tmp = original_tmp->next;
            while (original_tmp != nullptr) {
                tmp->next = new node(original_tmp->data);
                tmp = tmp->next;
                original_tmp = original_tmp->next;
            }
        } else {
            head = nullptr;
            size = 0;
        }
    }

    stack::~stack() {
        while (head != nullptr)
            pop();
    }

    stack &stack::operator=(const stack &RHS) {

        if (this != &RHS) {
            if (head != nullptr)
                delete this;
            if (RHS.head != nullptr) {
                node *RHS_tmp = RHS.head;
                node *tmp = head = new node(RHS_tmp->data);
                size = RHS.size;
                RHS_tmp = RHS_tmp->next;
                while (RHS_tmp != nullptr) {
                    tmp->next = new node(RHS_tmp->data);
                    tmp = tmp->next;
                    RHS_tmp = RHS_tmp->next;
                }
            }
        }
        return *this;
    }

    bool stack::isEmpty() const {
        return size == 0;
    }

    unsigned stack::stackSize() const {
        return size;
    }

    std::string stack::top() const {
        return head->data;
    }

    void stack::push(std::string &data) {
        //step 1 store address of current top node (pointed to by head) in a node*
        //step 2 create a new node with the incoming data variable, storing the address of this node in head pointer
        //step 3 update new nodes next pointer with the address stored in step 1
        //step 4 update size of stack variable
    }

    void stack::pop() {
        //step 1 store address of current top node (pointed to by head) in a node*
        //step 2 update head with address of second node
        //step 3 delete node pointed to by address stored in step 1
        // step 4 update size of stack variable
    }
}