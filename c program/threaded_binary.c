#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
    int righttread;
};

struct node *createnode(int data)
{
    struct node *n;
    n=(struct node *)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    n->righttread=0;

    return n;
};

struct node *leftmost(struct node *n)
{
    if(n==NULL)
        return n;
    while(n->left != NULL)
        n=n->left;
    return n;
};

struct node printTreadedBinaryTree(struct node *root)
{
    struct node *curl=leftmost(root);
    while(curl != NULL)
    {
        printf("%d\t",curl->data);

    if(curl->righttread==1)
        curl=curl->right;
    else
        curl=leftmost(curl->right);
    }    
};

int main()
{
    struct node *root=createnode(5);
    struct node *p1=createnode(10);
    struct node *p2=createnode(15);
    struct node *p3=createnode(20);
    struct node *p4=createnode(25);
    struct node *p5=createnode(30);
    struct node *p6=createnode(35);

    root->left=p1;
    root->right=p2;

    p1->left=p4;
    p1->right=root;
    p1->righttread=1;

    p4->left=NULL;
    p4->right=p1;
    p4->righttread=1;

    p2->left=NULL;
    p2->right=p5;

    p5->left=p6;
    p5->right=NULL;

    p6->left=NULL;
    p6->right=p5;
    p6->righttread=1;


    printTreadedBinaryTree(root);

    return 0;
}