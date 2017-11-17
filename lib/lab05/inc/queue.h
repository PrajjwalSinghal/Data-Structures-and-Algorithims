#ifndef CMPE126F17_LABS_LIB_LAB05_INC_QUEUE_H
#define CMPE126F17_LABS_LIB_LAB05_INC_QUEUE_H


#include "node.h"
namespace lab5 {
    class queue {
        node *head, *tail;
        unsigned size;

    public:
        queue();

        queue(std::string &data);

        queue(const queue &original);

        virtual ~queue();

        queue &operator=(const queue &RHS);

        bool isEmpty() const;

        unsigned queueSize() const;

        std::string top() const;

        void enqueue(std::string &data);

        void dequeue();
    };
}

#endif //CMPE126F17_LABS_LIB_LAB05_INC_QUEUE_H
