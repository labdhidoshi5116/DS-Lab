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

    if (data == -1) {
        return NULL;
    }

    struct Node* root = newNode(data);

    printf("Enter left child of %d\n", data);
    root->left = buildTree();

    printf("Enter right child of %d\n", data);
    root->right = buildTree();

    return root;
}

int isSameTree(struct Node* root1, struct Node* root2) {
    if (root1 == NULL && root2 == NULL)
        return 1;
    if (root1 == NULL || root2 == NULL)
        return 0;
    return (root1->data == root2->data) &&
           isSameTree(root1->left, root2->left) &&
           isSameTree(root1->right, root2->right);
}

void main() {
    printf("Build first tree:\n");
    struct Node* root1 = buildTree();

    printf("\nBuild second tree:\n");
    struct Node* root2 = buildTree();

    if (isSameTree(root1, root2))
        printf("\nOutput: Given trees are same\n");
    else
        printf("\nOutput: Given trees are not same\n");

}
