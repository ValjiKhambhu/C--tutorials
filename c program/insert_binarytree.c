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

void insert(struct node *root,int key)
{
    struct node *pre=NULL;
    while(root!=NULL)
    {
        pre=root;
        if(key==root->data)
        {
            printf("\n element is present is not insert ");
            break;
            //return;
        }
        else if(key<root->data)
        {
            root=root->left;
        }
        else{
            root=root->right;
        }
    }

    struct node *no=createnode(key);

    if(key<pre->data)
    {
         pre->left=no;
    }
    else{
         pre->right=no;
    }
}

void inorder(struct node *root)
{
    if(root != NULL)
    {
         printf("%d\t",root->data);
        inorder(root->left);
        inorder(root->right);
    }
}

struct node *inorderpre(struct node *root)
{
    root=root->left;
    if(root->right != NULL)
    {
        root=root->right;
    }
    return root;
};

struct node *delete(struct node *root,int value)
{
    struct node *ipre;
    if(root == NULL)
    {
        return NULL;
    }
    else if(root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    else if(value<root->data)
    {
        root->left=delete(root->left,value);
    }
    else if(value>root->data)
    {
        root->right=delete(root->right,value);
    }
    else 
    {
        ipre=inorderpre(root);
        root->data=ipre->data;
        root->left=delete(root->left,ipre->data);
    }
    return root;
};

int main()
{
    struct node *p=createnode(10);
    struct node *p1=createnode(8);
    struct node *p2=createnode(12);
    struct node *p3=createnode(6);
    struct node *p4=createnode(9);
    struct node *p5=createnode(4);

    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    //p3->left=p5;


    /*insert(p,16);
    printf("%d\n",p->right->right->data);
    insert(p,11);
    printf("%d\n",p->right->left->data);*/
    
    inorder(p);

    delete(p,10);

    printf("\n");
    inorder(p);

    return 0;
}