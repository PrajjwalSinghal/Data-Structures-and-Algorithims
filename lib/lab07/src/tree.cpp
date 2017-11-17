#include "../inc/tree.h"
#include<iostream>
void clear(node* to_clear);
void node_print_gtl(node* to_print);
void insert_recursive(node *root,int value);
node* get_node_recursive(node *root,int key);
node* delete_recursive(node* root,int key);
node* search_min_in_right_recursive(node* root);
int level_recursive(node* root,int data);
int print_recursive(node *root,int data);
unsigned find_size_recursive(node *root);
unsigned find_depth_recursive(node *root);
bool in_tree_recursive(node *root,int key);
void print_tree_recursive(node *root);
// Construct an empty tree
tree::tree(){
    root = nullptr;
}

    // Deconstruct tree
    tree::~tree() {
        clear(root);
    }

    // Insert
    void tree::insert(int value) {
    if(root==nullptr)
        root = new node(value);
    else
        insert_recursive(root,value);
    }

    // Remove key
    bool tree::remove(int key) {
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
        root = delete_recursive(root,key);
        return true;
    }

    }

    // What level is key on?
    int tree::level(int key) {
    return level_recursive(root,key);
    }

    // Print the path to the key, starting with root
    void tree::path_to(int key) {
    std::cout<<"Path:"<<print_recursive(root,key);
    }

    // Number of items in the tree
    unsigned tree::size() {
    unsigned size_of_tree;
    if(root== nullptr)
        size_of_tree = 0;
    else
        size_of_tree = 1 + find_size_recursive(root->left) + find_size_recursive(root->right);
    return size_of_tree;
    }

    // Calculate the depth of the tree, longest string of connections
    unsigned tree::depth() {
    unsigned depth;
    if(root==nullptr)
        depth = 0;
    else
        depth = find_depth_recursive(root);
    return depth;
    }

    // Determine whether the given key is in the tree
    bool tree::in_tree(int key) {
    if(in_tree_recursive(root,key))
        return true;
    else
        return false;

    }

    // Return the number of times that value is in the tree
    int tree::get_frequency(int key) {
    node *temp;
    temp = get_node_recursive(root,key);
    return temp->frequency;
    }

    // Print the tree least to greatest, Include duplicates
    void tree::print() {
    if(root == nullptr)
        std::cout<<"Tree is empty!!";
    else
    {
        print_tree_recursive(root);
    }
    }

    void tree::print_gtl() {
        node_print_gtl(root);
        std::cout << std::endl;
    }

    void node_print_gtl(node *top) {
        if(top == nullptr) return;
        node_print_gtl(top->right);
        for(int i = 0; i < top->frequency; i++) std::cout << top->data << " ";
        node_print_gtl(top->left);

    void clear(node *to_clear) {
        if (to_clear == nullptr) return;
        if (to_clear->left != nullptr) clear(to_clear->left);
        if (to_clear->right != nullptr) clear(to_clear->right);
        delete to_clear;
    }
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
node* get_node_recursive(node *root,int key)
{
    node *temp_root;
    if (key > root->data)
    {
        node *temp_root;
        temp_root = get_node_recursive(root->right, key);
    }
    else if (key < root->data)
    {
        node *temp_root;
        temp_root = get_node_recursive(root->left, key);
    }
    else
        temp_root = root;

    return temp_root;

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
        //CASE 3 : Two child
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
int level_recursive(node* root,int data)
{
    if(root->data == data)
        return 0;
    else if(data>root->data)        // What is node is not present
        return (1+level_recursive(root->right,data));
    else
        return  (1+level_recursive(root->left,data));
}
int print_recursive(node *root,int data)
{
    if(data > root->data)
        std::cout<<print_recursive(root->right,data);
    else if(data < root->data)
        std::cout<<print_recursive(root->left,data);
    return root->data;
}
unsigned find_size_recursive(node *root)
{
    unsigned size_of_tree;
    if(root == nullptr)
        size_of_tree = 0;
    else
        size_of_tree = find_size_recursive(root->left) + 1 + find_size_recursive(root->right);
    return size_of_tree;

}
unsigned find_depth_recursive(node* root)
{
    unsigned depth;
    if(root == nullptr)
        depth = 0;
    else
    {
        unsigned left_depth=0,right_depth=0;
        left_depth = 1 + find_depth_recursive(root->left);
        right_depth = 1 + find_depth_recursive(root->right);
        if(left_depth>right_depth)
            depth = left_depth;
        else
            depth = right_depth;
    }
    return depth;
}
bool in_tree_recursive(node *root,int key)
{
    bool key_found;
    if(root->data == key)
        key_found = true;
    else if(root->right== nullptr&&root->left== nullptr)
        key_found = false;
    else if(key>root->data && root->right != nullptr)
        key_found = in_tree_recursive(root->right,key);
    else if(key<root->data && root->left != nullptr)
        key_found = in_tree_recursive(root->left,key);
    else
        key_found = false;
    return key_found;
}
void print_tree_recursive(node *root)
{
    if(root == nullptr)
        return ;
    print_tree_recursive(root->left);
    for(int i=0;i<root->frequency;i++)
        std::cout<<root->data<<":";
    print_tree_recursive(root->right);

}