#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// DECLARE STRUCTURE
typedef struct Node {
    int data;
    struct Node *left , *right;
} Node;

// The functions

Node* CreateNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

bool isEmpty(Node* root) {
    return root == NULL;
}
// TRAVERSAL (inorder/preorder/postorder)
void InOrder(Node* root) {
    if (root!=NULL) {
        InOrder(root->left);
        printf("%d ", root->data);
        InOrder(root->right);
    }
}
void PreOrder(Node* root) {
    if (root!=NULL) {
        printf("%d ", root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
void PostOrder(Node* root) {
    if (root!=NULL) {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d ", root->data);
    }
}
// Count number of elements in a tree
int CountNodes(Node* root) {
    if (root!=NULL){
        return 0;
    }
    else{
        return 1 + CountNodes(root->left) + CountNodes(root->right);
    }
}
bool isLeaf(Node* node) {
    return !isEmpty(node) && (node->left == NULL) && (node->right == NULL);
}
void DisplayLeaves(Node* root) {
    if (root) {
        if (isLeaf(root))
            printf("%d ", root->data);
        DisplayLeaves(root->left);
        DisplayLeaves(root->right);
    }
}
int TreeDepth(Node* root) {
    if (!root) return 0;
    int leftDepth = TreeDepth(root->left);
    int rightDepth = TreeDepth(root->right);
    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}