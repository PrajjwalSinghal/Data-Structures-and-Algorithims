#include "node.h"
#include <iostream>

namespace lab4 {
    // Take in value and create a node
    node::node(int input)
    {
        this->data = input;
        this->next = nullptr;
    }
// Takes in an array of values and creates the appropriate nodes
    node::node(int values[], int length)
    {
        node* temp;
        temp = this;
        //temp = new node(values[0]);
        //temp->next = nullptr;
        for(int i=1;i<length;i++)
        {
            temp->next = new node(values[i]);
            temp=temp->next;
            temp->next = nullptr;
        }
    }

// Default destructor
    node::~node()
    {
        // Hint: You don't want to just delete the current node. You need to keep track of what is next
        //node *temp;
        //temp = this->next;
        //node *temp1 = this;
        //delete this;
    }

// Add a value to the end node
    void node::append(int input)
    {
        node *temp;
        temp = this;
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = new node(input);
        temp = temp->next;
        temp->next = nullptr;
    }

// Add an array of values to the end as separate nodes
    void node::append(int inputs[], int length)
    {
        node *temp;
        temp = this;
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        for(int i=0;i<length;i++)
        {
            temp->next = new node(inputs[i]);
            temp = temp->next;
            temp->next = nullptr;
        }
    }

// Insert a new node after the given location
    node* node::insert(int location, int value)
    {
        node *temp;
        temp = this;
        for(int i=0;((i<location)&&(temp->next!=nullptr));i++)
        {
            temp = temp->next;
        }
        if(temp->next!=nullptr)
        {
            node *temp1;
            temp1 = new node(value);
            temp1->next = temp->next;
            temp->next = temp1;
        }
        else
        {
            node*temp1;
            temp1 = new node(value);
            temp1->next = nullptr;
            temp->next = temp1;
        }
        return this;
        // Must return head pointer location
    }

// Remove a node and link the next node to the previous node
    node* node::remove(int location)
    {
        node *temp;
        temp = this;
        if(location == 0)
        {
            temp = temp->next;
            delete this;
            return temp;
        }
        else
        {   node* temp1;
            for(int i=0;((i<location)&&(temp->next!=nullptr));i++)
            {
                temp1=temp;
                temp=temp->next;
            }
            temp1->next = temp->next;
            delete temp;
            return this;

        }
        // Must return head pointer location
    }

// Print all nodes
    void node::print()
    {
        node* temp;
        temp = this;
        while(temp!=nullptr)
        {
            std::cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        std::cout<<"null";
    }

//Print the middle node
    void node::print_middle()
    {
        node *runner1;
        node *runner2;
        bool flag = true;
        runner1 = this;
        runner2 = this;
        if(this == nullptr)
            return;
        do
        {
            if(runner2->next == nullptr)
            {

                flag = false;
            }
            else
            {
                runner2 = runner2->next->next;
                if(runner2== nullptr)
                    flag = false;
                else
                    runner1 = runner1->next;

            }

        }while(flag == true);
        std::cout<<runner1->data;
        // HINT: Use a runner to traverse through the linked list at two different rates, 1 node per step
        //       and two nodes per step. When the faster one reaches the end, the slow one should be
        //       pointing to the middle
    }

// Get the value of a given node
    int node::get_value(int location)
    {
        node* temp;
        temp = this;
        for(int i=0;i<location;i++)
        {
            temp=temp->next;
        }
        return temp->data;
    }

// Overwrite the value of a given node
    void node::set_data(int location, int value)
    {
        node* temp;
        temp = this;
        for(int i=0;i<location;i++)
        {
            temp = temp->next;
        }
        temp->data = value;
    }

}