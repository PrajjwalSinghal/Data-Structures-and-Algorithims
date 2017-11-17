#ifndef CMPE126F17_LABS_LIB_LAB05_INC_STACK_H
#define CMPE126F17_LABS_LIB_LAB05_INC_STACK_H


#include "node.h"

namespace lab5 {
    class stack {
        node *head;
        unsigned size;

    public:
        stack();

        stack(std::string &data);

        stack(const stack &original);

        virtual ~stack();

        stack &operator=(const stack &RHS);

        bool isEmpty() const;

        unsigned stackSize() const;

        std::string top() const;

        void push(std::string &data);

        void pop();
    };
}

#endif //CMPE126F17_LABS_LIB_LAB05_INC_STACK_H

