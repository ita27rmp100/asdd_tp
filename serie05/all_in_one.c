#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// DECLARE STRUCTURE
typedef struct Node {
    int data;
    struct Node *left , *right;
} Node;

// Create a new node
Node* CreateNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Check if a tree is empty
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

// Display all the leaves
void DisplayLeaves(Node* root) {
    if (root) {
        if (isLeaf(root))
            printf("%d ", root->data);
        DisplayLeaves(root->left);
        DisplayLeaves(root->right);
    }
}

// Calculate depth of tree
int TreeDepth(Node* root) {
    if (!root) return 0;
    int leftDepth = TreeDepth(root->left);
    int rightDepth = TreeDepth(root->right);
    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}

/////// EXO2 ///////

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
