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

int height(struct Node* root) {
    if (root == NULL) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh > rh ? lh : rh) + 1;
}

int isBalanced(struct Node* root) {
    if (root == NULL) return 1;
    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh - rh) > 1) return 0;
    return isBalanced(root->left) && isBalanced(root->right);
}

int main() {
    printf("Build tree:\n");
    struct Node* root = buildTree();
    if (isBalanced(root))
        printf("Output: TRUE\n");
    else
        printf("Output: FALSE\n");
    return 0;
}
