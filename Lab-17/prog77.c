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

struct Node* buildTree() {
    int data;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &data);
    if (data == -1) return NULL;

    struct Node* root = newNode(data);
    printf("Enter left child of %d\n", data);
    root->left = buildTree();
    printf("Enter right child of %d\n", data);
    root->right = buildTree();
    return root;
}

int isMirror(struct Node* t1, struct Node* t2) {
    if (t1 == NULL && t2 == NULL) return 1;
    if (t1 == NULL || t2 == NULL) return 0;
    return (t1->data == t2->data) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

int isSymmetric(struct Node* root) {
    if (root == NULL) return 1;
    return isMirror(root->left, root->right);
}

int main() {
    printf("Build tree:\n");
    struct Node* root = buildTree();

    if (isSymmetric(root))
        printf("\nOutput: Given tree is symmetric\n");
    else
        printf("\nOutput: Given tree is not symmetric\n");

    return 0;
}
