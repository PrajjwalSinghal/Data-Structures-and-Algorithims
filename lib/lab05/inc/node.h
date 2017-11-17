#ifndef CMPE126F17_LABS_LIB_LAB05_INC_NODE_H
#define CMPE126F17_LABS_LIB_LAB05_INC_NODE_H

#include <string>
namespace lab5 {
    class node {
    public:
        std::string data;
        node *next;

        node(const std::string &data);
    };
}

#endif //CMPE126F17_LABS_LIB_LAB05_INC_NODE_H
