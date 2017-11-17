#include "node.h"
#include <iostream>

namespace lab4 {
    // Take in value and create a node
    node::node(int input) {
    }

    // Takes in an array of values and creates the appropriate nodes
    node::node(int values[], int length) {

    }

    // Default destructor
    node::~node() {
        // Hint: You don't want to just delete the current node. You need to keep track of what is next
    }

    // Add a value to the end node
    void node::append(int input) {

    }

    // Add an array of values to the end as separate nodes
    void node::append(int inputs[], int length) {

    }

    // Insert a new node after the given location
    node *node::insert(int location, int value) {
        // Must return head pointer location
    }

    // Remove a node and link the next node to the previous node
    node *node::remove(int location) {
        // Must return head pointer location
    }

    // Print all nodes
    void node::print() {

    }

    //Print the middle node
    void node::print_middle() {
        // HINT: Use a runner to traverse through the linked list at two different rates, 1 node per step
        //       and two nodes per step. When the faster one reaches the end, the slow one should be
        //       pointing to the middle
    }

    // Get the value of a given node
    int node::get_value(int location) {

    }

    // Overwrite the value of a given node
    void node::set_data(int location, int value) {

    }
}