#ifndef CMPE126F17_LABS_LIB_LAB07_INC_NODE_H
#define CMPE126F17_LABS_LIB_LAB07_INC_NODE_H

// Yes, this is a very tiny node. Everything is accessibly publicly, without accessors or mutators
namespace lab7 {
    class node {
    public:
        node *left, *right;
        int data;
        unsigned frequency;

        explicit node(int data) : data(data), frequency(1), left(nullptr), right(nullptr) {}
    };
}

#endif //CMPE126F17_LABS_LIB_LAB07_INC_NODE_H
