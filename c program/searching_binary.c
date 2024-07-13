#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int data)
{
    struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;

    return n;
};

struct node *searching(struct node *root,int key)
{
    //struct node *pre;
    if(root==NULL)
    {
        return NULL;
    }
    else if(root->data==key)
    {
        return root;
    }
    else if(key<root->data)
    {
        return searching(root->left,key);
    }
    else{
        return searching(root->right,key);
    }
}

int main()
{
    struct node *p=createnode(5);
    struct node *p1=createnode(3);
    struct node *p2=createnode(6);
    struct node *p3=createnode(1);
    struct node *p4=createnode(4);

    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;

    struct node *ans=searching(p,6);

    if(ans != NULL)
    {
        printf("\n the element is %d is found ",ans->data);
    }
    else{
        printf("\n element is not found:");
    }
    return 0;
}