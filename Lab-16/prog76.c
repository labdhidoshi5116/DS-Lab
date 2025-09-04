//Write a program to check whether the given two trees are same or not. 
#include <stdio.h>
#include <stdlib.h>
struct node {
    int value;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;
