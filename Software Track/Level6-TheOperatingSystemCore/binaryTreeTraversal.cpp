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

    Node(string n) : name(n), left(NULL), right(NULL) {}
};

string preorder(Node* root) {
    if (root == nullptr) return "";
    string res = root->name + " ";
    res += preorder(root->left);
    res += preorder(root->right);
    return res;
}

string inorder(Node* root) {
    if (root == nullptr) return "";
    string res = inorder(root->left);
    res += root->name + " ";
    res += inorder(root->right);
    return res;
}

string postorder(Node* root) {
    if (root == nullptr) return "";
    string res = postorder(root->left);
    res += postorder(root->right);
    res += root->name + " ";
    return res;
}


int main(){

    // Initial binary tree representing the file system
    Node* root = new Node("root");
    root->left = new Node("Documents");
    root->right = new Node("Music");
    root->left->left = new Node("Photos");
    root->left->right = new Node("Downloads");

    string res_preorder = preorder(root);
    string res_inorder = inorder(root);
    string res_postorder = postorder(root);
    cout << "Pre-order Traversal: " << res_preorder << endl;
    cout << "In-order Traversal: " << res_inorder << endl;
    cout << "Post-order Traversal: " << res_postorder << endl;

    return 0;
}