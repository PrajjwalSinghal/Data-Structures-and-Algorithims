#ifndef UNTITLED1_NODE_H
#define UNTITLED1_NODE_H
#include<iostream>

using namespace std;
// Yes, this is a very tiny node. Everything is accessibly publicly, without accessors or mutators

namespace lab6 {
    class node {
    public:
        node *next, *prev;
        unsigned data;

        explicit node(unsigned int data) : data(data), next(NULL), prev(NULL) {}
    };
}

#endif //CMPE126F17_LABS_LIB_LAB06_INC_NODE_H
