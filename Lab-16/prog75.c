#include<stdio.h>
#include<stdlib.h>
struct node{
    int value;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;
// void insert(int x,struct node *root){
//     struct node *newNode = (struct node *)malloc(sizeof(struct node));
//     newNode->value = x;
//     newNode->left = NULL;
//     newNode->right = NULL;
//     if (root == NULL) {
//         root = newNode;
//         return;
//     }
//     struct node *current = root;
//     struct node *parent = NULL;
//     while (current != NULL) {
//         parent = current;
//         if (x < current->value) {
//             current = current->left;
//         } else {
//             current = current->right;
//         }
//     }
//     if (x < parent->value) {
//         parent->left = newNode;
//     } else {
//         parent->right = newNode;
//     }
// }
struct node * insert(int x,struct node *root){
    if (root==NULL)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->value = x;
        newNode->left = NULL;
        newNode->right = NULL;
        root=newNode;
        return root;
    }
    if(root->value > x){
        root->left = insert(x, root->left);
    }
    else if(root->value<x){
        root->right = insert(x, root->right);
    }
    return root;
}

// void delete(int x,struct node *root){
//     struct node *current = root;
//     struct node *parent = NULL;

//     while (current != NULL && current->value != x) {
//         parent = current;
//         if (x < current->value) {
//             current = current->left;
//         } else {
//             current = current->right;
//         }
//     }

//     if (current == NULL) {
//         printf("Not Found\n");
//         return;
//     }
//     if (current->left == NULL || current->right == NULL) {
//         struct node *child = (current->left != NULL) ? current->left : current->right;

//         if (parent == NULL) {
//             root = child;
//         } else if (current == parent->left) {
//             parent->left = child;
//         } else {
//             parent->right = child;
//         }
//     } else {
//         struct node *prevParent = current;
//         struct node *prev = current->right;

//         while (prev->left != NULL) {
//             prevParent = prev;
//             prev = prev->left;
//         }
//         current->value = prev->value;
//         if (prevParent->left == prev) {
//             prevParent->left = prev->right;
//         } else {
//             prevParent->right = prev->right;
//         }
//     }

//     free(current);
// }
struct node * delete(int x,struct node *root){
    if (root==NULL)
    {
        printf("Not Found\n");
        return root;
    }
    if (x < root->value) {
        root->left = delete(x, root->left);
    } else if (x > root->value) {
        root->right = delete(x, root->right);
    }
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        } 
        else if (root->left == NULL) {
            struct node *temp = root;
            root = root->right;
            free(temp);
            return root;
        }
        else if (root->right == NULL) {
            struct node *temp = root;
            root = root->left;
            free(temp);
            return root;
        }
        else {
            struct node *temp = root;
            struct node *parent = NULL;
            temp = temp->right;
            while (temp->left != NULL) 
            {
                parent = temp;
                temp = temp->left;
            }
            root->value = temp->value;
            if (parent != NULL) 
            {
                parent->left = temp->right;
            } else {
                root->right = temp->right;
            }
            free(temp);
            return root;
        }
    }
    return root;
}
void search(int x){
    struct node *current = root;

    while (current != NULL) {
        if (x == current->value) {
            printf("Found\n");
            return;
        } else if (x < current->value) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    printf("Not Found\n");

}

void inorder(struct node *root){
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->value);
        inorder(root->right);
    }
}

void preorder(struct node *root){
    if (root != NULL) {
        printf("%d ", root->value);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root){
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->value);
    }
}

void main(){
    int ch, x;
    while (1) {
        printf("1. Insert\n2.Delete\n3.Search\n4.Inorder\n5.Preorder\n6.Postorder\n\n7.Exit\n");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &x);
                root = insert(x,root);
                break;
                case 2:
                printf("Enter value to delete: ");
                scanf("%d", &x);
                root=delete(x,root);
                break;
                case 3:
                printf("Enter value to search: ");
                scanf("%d", &x);
                search(x);
                break;
                case 4:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;
                case 5:
                printf("Preorder traversal: ");
                preorder(root);
                printf("\n");
                break;
                case 6:
                printf("Postorder traversal: ");
                postorder(root);
                printf("\n");
                break;
                case 7:
                return;
        }
    }
}
