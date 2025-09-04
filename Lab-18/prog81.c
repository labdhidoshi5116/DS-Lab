#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    char phone[15];
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(char name[], char phone[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, char name[], char phone[]) {
    if (root == NULL)
    {
        return createNode(name, phone);
    }
    if (strcmp(name, root->name) < 0){
        root->left = insert(root->left, name, phone);
    }
    else if (strcmp(name, root->name) > 0){
        root->right = insert(root->right, name, phone);
    }
    return root;
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL){
        current = current->left;
    }
    return current;
}

struct Node* deleteNode(struct Node* root, char name[]) {
    if (root == NULL) {
        return root;
    }
    if (strcmp(name, root->name) < 0)
    {    
        root->left = deleteNode(root->left, name);
    }
    else if (strcmp(name, root->name) > 0)
    {    
        root->right = deleteNode(root->right, name);
    }
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = minValueNode(root->right);
        strcpy(root->name, temp->name);
        strcpy(root->phone, temp->phone);
        root->right = deleteNode(root->right, temp->name);
    }
    return root;
}

struct Node* search(struct Node* root, char name[]) {
    if (root == NULL || strcmp(root->name, name) == 0)
        return root;
    if (strcmp(name, root->name) < 0)
        return search(root->left, name);
    return search(root->right, name);
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%s : %s\n", root->name, root->phone);
        inorder(root->right);
    }
}

void reverseInorder(struct Node* root) {
    if (root != NULL) {
        reverseInorder(root->right);
        printf("%s : %s\n", root->name, root->phone);
        reverseInorder(root->left);
    }
}

int main() {
    struct Node* root = NULL;
    int choice;
    char name[50], phone[15];
    while (1) {
        printf("\n1. Add Entry\n2. Delete Entry\n3. Search Phone\n4. List Ascending\n5. List Descending\n6. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Phone: ");
                scanf("%s", phone);
                root = insert(root, name, phone);
                break;
            case 2:
                printf("Enter Name to Delete: ");
                scanf("%s", name);
                root = deleteNode(root, name);
                break;
            case 3:
                printf("Enter Name to Search: ");
                scanf("%s", name);
                struct Node* found;
                found = search(root, name);
                if (found != NULL)
                    printf("Phone: %s\n", found->phone);
                else
                    printf("Not Found\n");
                break;
            case 4:
                inorder(root);
                break;
            case 5:
                reverseInorder(root);
                break;
            case 6:
                exit(0);
        }
    }
    return 0;
}
