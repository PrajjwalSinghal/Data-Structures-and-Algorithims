#ifndef UNTITLED1_NODE_H
#define UNTITLED1_NODE_H
#include<iostream>

using namespace std;
// Yes, this is a very tiny node. Everything is accessibly publicly, without accessors or mutators

class node {
public:
    node *next, *prev;
    unsigned data;
    explicit node(unsigned int data) : data(data), next(NULL), prev(NULL) {}
};


#endif //UNTITLED1_NODE_H
