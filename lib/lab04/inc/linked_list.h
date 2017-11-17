#ifndef CMPE126F17_LABS_LIB_LAB04_INC_LINKED_LIST_H
#define CMPE126F17_LABS_LIB_LAB04_INC_LINKED_LIST_H

#include "node.h"

namespace lab4 {
    class linked_list {
    private:
        node *head;

    public:
        linked_list();

        linked_list(int value);

        linked_list(int values[], int length);

        ~linked_list();

        bool append(int value);

        bool append(int values[], int length);

        void insert(int location, int value);

        void remove(int location);

        void print();

        void print_middle();

        int get_value(int location);

        void set_data(int location, int value);
    };
}

#endif //CMPE126F17_LABS_LIB_LAB04_INC_LINKED_LIST_H
