// WAP to define a C structure named Student (roll_no, name, branch and batch_no) and also to access the structure members using Pointer
#include<stdio.h>
#include<stdlib.h>
struct Student{
    int roll_no;
    char name[50];
    char branch[10];
    int batch_no;
};
void main(){
    struct Student s1={509,"Labdhi","CSE",1};
    struct Student *ptr;
    ptr=&s1;
    printf("%d ",ptr->roll_no);
    printf("%s ",ptr->name);
    printf("%s ",ptr->branch);
    printf("%d ",ptr->batch_no);
}