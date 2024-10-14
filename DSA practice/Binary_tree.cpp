#include <iostream>
using namespace std;

// Define the structure of a tree node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        return nullptr;
    }
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function to insert node in the tree
Node* insertNode(Node* root, int data) {
    if (root == nullptr) {
        root = createNode(data);
        return root;
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Inorder traversal of the tree (Left, Root, Right)
void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Function to search for a value in the tree
bool search(Node* root, int key) {
    if (root == nullptr) {
        return false;
    }
    if (root->data == key) {
        return true;
    }
    if (key < root->data) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

// Main function
int main() {
    Node* root = nullptr;
    int n, data, key;
    
    cout << "Enter number of elements to insert in the tree: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> data;
        root = insertNode(root, data);
    }

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Enter element to search: ";
    cin >> key;
    if (search(root, key)) {
        cout << key << " found in the tree.\n";
    } else {
        cout << key << " not found in the tree.\n";
    }

    return 0;
}
