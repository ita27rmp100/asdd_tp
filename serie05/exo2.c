#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the DS we need
typedef struct Node {
    int data;
    struct Node *left , *right;
} Node;
Node* CreateNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}
// Insert into BST
Node* Insert(Node* root, int value) {
    if (!root) return CreateNode(value);
    if (value < root->data)
        root->left = Insert(root->left, value);
    else if (value > root->data)
        root->right = Insert(root->right, value);
    return root;
}

// Search in BST
Node* Search(Node* root, int value) {
    if (!root || root->data == value) return root;
    if (value < root->data)
        return Search(root->left, value);
    else
        return Search(root->right, value);
}

// Find minimum node
Node* FindMin(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

// Delete a node from BST
Node* Delete(Node* root, int value) {
    if (!root) return NULL;
    if (value < root->data)
        root->left = Delete(root->left, value);
    else if (value > root->data)
        root->right = Delete(root->right, value);
    else {
        if (!root->left) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = FindMin(root->right);
        root->data = temp->data;
        root->right = Delete(root->right, temp->data);
    }
    return root;
}
int main(){

    return 0;
}