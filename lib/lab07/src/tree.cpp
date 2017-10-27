#include "../inc/tree.h"
#include<iostream>
void clear(node* to_clear);
void node_print_gtl(node* to_print);
void insert_recursive(node *root,int value);
node* search_recursive(node *root,int key);
node* delete_recursive(node* root,int key);
node* search_min_in_right_recursive(node* root);
// Construct an empty tree
tree::tree(){
    root = nullptr;
}

// Deconstruct tree
tree::~tree(){
    clear(root);
}

// Insert
void tree::insert(int value){
    if(root==nullptr)
        root = new node(value);
    else
        insert_recursive(root,value);
}

// Remove key
bool tree::remove(int key){
    if(root== nullptr)
        return false;
    else if(root->data==key)
    {
        delete root;
        root=nullptr;
        return true;
    }
    else
    {
        delete_recursive(root,key);
        return true;
    }

}

// What level is key on?
int tree::level(int key){

}

// Print the path to the key, starting with root
void tree::path_to(int key){

}

// Number of items in the tree
unsigned tree::size(){

}

// Calculate the depth of the tree, longest string of connections
unsigned tree::depth(){

}

// Determine whether the given key is in the tree
bool tree::in_tree(int key){

}

// Return the number of times that value is in the tree
int tree::get_frequency(int key){

}

// Print the tree least to greatest, Include duplicates
void tree::print(){

}

void tree::print_gtl(){
    //WILL BE PROVIDED FOR YOU
}

void node_print_gtl(node* to_print){
    //WILL BE PROVIDED FOR YOU
}

void clear(node* to_clear){
    if(to_clear == nullptr) return;
    if(to_clear->left != nullptr) clear(to_clear->left);
    if(to_clear->right != nullptr) clear(to_clear->right);
    delete to_clear;
}
void insert_recursive(node *root,int value)
{
    if(value<root->data)
    {
        if(root->left!= nullptr)
            insert_recursive(root->left,value);
        else
            root->left = new node(value);
    }
    else if(value>root->data)
    {
        if(root->right != nullptr)
            insert_recursive(root->right,value);
        else
            root->right = new node(value);
    }
    else
        ++root->frequency;
}
node* search_recursive(node *root,int key)
{

    if (key > root->data)
    {
        node *temp_root;
        temp_root = search_recursive(root->right, key);
        return temp_root;
    }
    else if (key < root->data)
    {
        node *temp_root;
        temp_root = search_recursive(root->left, key);
        return temp_root;
    }
    else
        return root;

}
node* delete_recursive(node* root,int data)
{
    if(data>root->data)
       root->right = delete_recursive(root->right,data);
    else if(data<root->data)
        root->left=delete_recursive(root->left,data);
    else
    {
        // CASE 1 : No Child
        if(root->right == nullptr && root->left == nullptr)
        {
            delete root;
            root = nullptr;

        }
        //CASE 2 : One Child
        else if(root->left == nullptr)
        {
            node *temp;
            temp = root;
            root = root->right;
            delete temp;

        }
        else if(root->right == nullptr)
        {
            node *temp;
            temp = root;
            root = root->left;
            delete temp;

        }
        //CASE 3 : Complicated
        else
        {
            node *temp;
            temp = search_min_in_right_recursive(root->right);
            root->data = temp->data;
            root->right = delete_recursive(root->right,temp->data);
        }
    }
    return root;
}
node* search_min_in_right_recursive(node*root)
{
    if(root->left == nullptr)
        return root;
    else
    {
        root = search_min_in_right_recursive(root->left);
        return root;
    }
}