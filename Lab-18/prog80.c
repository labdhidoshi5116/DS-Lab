//WAP to find the smallest and largest elements in the Binary Search Tree.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

struct Node* minFunc(struct Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

struct Node* maxFunc(struct Node* root) {
    while (root && root->right != NULL)
        root = root->right;
    return root;
}

void main() {
    struct Node* root = NULL;
    int n, val;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &val);
        root = insert(root, val);
    }
    struct Node* minNode = minFunc(root);
    struct Node* maxNode = maxFunc(root);
    if (minNode) printf("Smallest element: %d\n", minNode->data);
    if (maxNode) printf("Largest element: %d\n", maxNode->data);
}