#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *firstchild;
    struct node *nextsibling;
};

struct node *createnode(int data)
{
    struct node *n;
    n=(struct node*) malloc (sizeof(struct node));
    n->data=data;
    n->firstchild=NULL;
    n->nextsibling=NULL;

    return n;
};

void preorder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d\t",root->data);
        preorder(root->firstchild);
        preorder(root->nextsibling);
        
    }
}

int main()
{
    struct node *p=createnode(5);
    struct node *p1=createnode(10);
    struct node *p2=createnode(15);
    struct node *p3=createnode(20);
    struct node *p11=createnode(25);
    struct node *p12=createnode(30);
    struct node *p13=createnode(35);
    struct node *p21=createnode(40);
    struct node *p22=createnode(45);
    struct node *p23=createnode(50);
    struct node *p31=createnode(55);
    struct node *p32=createnode(60);
    struct node *p33=createnode(65);

    p->firstchild=p1;

    p1->firstchild=p11;
    p1->nextsibling=p2;

    p2->firstchild=p21;
    p2->nextsibling=p3;

    p3->firstchild=p31;

    p11->nextsibling=p12;

    p12->nextsibling=p13;

    p21->nextsibling=p22;

    p22->nextsibling=p23;

    p31->nextsibling=p32;

    p32->nextsibling=p33;

    preorder(p);

    return 0;
}