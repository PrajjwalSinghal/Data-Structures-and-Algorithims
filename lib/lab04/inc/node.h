#ifndef CMPE126F17_LABS_LIB_LAB04_INC_NODE_H
#define CMPE126F17_LABS_LIB_LAB04_INC_NODE_H

namespace lab4 {
    class node {
    public:
        node* next;
        int data;
        node();
        node(int input);
        node(int input[], int length);
        ~node();

        void append(int value);
        void append(int values[], int length);
        node* insert(int location, int value);
        node* remove(int location);

        void print();
        void print_middle();

        int get_value(int location);
        void set_data(int location, int value);


    };
}
#endif //CMPE126F17_LABS_LIB_LAB04_INC_NODE_H
