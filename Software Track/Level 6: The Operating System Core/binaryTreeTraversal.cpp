/*
    The operating system's file system is structured as a binary tree, where each node represents a folder or file. 
    Your task is to traverse this binary tree and print out the names of all the files and folders in a specific order.

    You are required to implement three types of tree traversals:
    In-order traversal: Visit the left subtree, the root node, and then the right subtree.
    Pre-order traversal: Visit the root node, then the left subtree, followed by the right subtree.
    Post-order traversal: Visit the left subtree, then the right subtree, and finally the root node.

    Input: A binary tree representing the file system, where each node has:
    name: The name of the folder or file.
    left: A pointer to the left child node (or null if absent).
    right: A pointer to the right child node (or null if absent).

    Output: Print the traversal order of the file system for each traversal method.
*/

#include<iostream>
using namespace std;

struct Node {
    string name;
    Node* left;
    Node* right;
};

string preorder(){
    // WRITE YOUR CODE HERE
}

string inorder(){
    // WRITE YOUR CODE HERE
}

string postorder(){
    // WRITE YOUR CODE HERE
}


int main(){

    // Initial binary tree representing the file system
    Node* root = new Node("root");
    root->left = new Node("Documents");
    root->right = new Node("Music");
    root->left->left = new Node("Photos");
    root->left->right = new Node("Downloads");

    // WRITE YOUR CODE HERE

}