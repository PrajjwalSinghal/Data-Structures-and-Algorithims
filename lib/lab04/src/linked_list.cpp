#include "../inc/linked_list.h"
namespace lab4{
    // Default constructor for creating a linked list with nothing in it
    linked_list::linked_list()
    {
        head = nullptr;
    }

    // Default constructor for creating a linked list with a given value
    linked_list::linked_list(int value)
    {
        head= new node(value);
    }

    // Default constructor for creating a linked list from a given integer array
    linked_list::linked_list(int values[], int length)
    {
        head= new node(values, length);
    }

    // Default destructor. Should run through each of the nodes and delete them
    linked_list::~linked_list()
    {
        while(head!=nullptr)
        {
            node* temp = head;
            head = head-> next;
            delete temp;
        }
    }

    // Add a single value to a linked list. Adds to the end of the linked_list
    bool linked_list::append(int value)
    {
        if(head== nullptr) {
            head = new node(value);
        }
        else {
            head->append(value);
        }
    }

    // Add an array of values to the end of the
    bool linked_list::append(int values[], int length)
    {
        if(head== nullptr) {
            head = new node(values, length);
        }
        else {
            head->append(values, length);
        }
    }

    // Add a a single value after the given location
    void linked_list::insert(int location, int value)
    {
        if(head== nullptr) {
            return;
        }
        else {
            head= head->insert(location, value);
        }
    }

    // Remove a node at the given node and link the previous node to the next node
    void linked_list::remove(int location)
    {
        if(head== nullptr) {
            return;
        }
        else {
            head= head->remove(location);
        }
    }

    // Print the entire linked list
    void linked_list::print()
    {
        head->print();
    }

    // Print the middle node of the linked list
    void linked_list::print_middle()
    {
        head->print_middle();
    }

    // Get the data at the given location
    int linked_list::get_value(int location)
    {
        return head->get_value(location);
    }

    // Overwrite the data at the given location
    void linked_list::set_data(int location, int value)
    {
        head->set_data(location, value);
    }
}