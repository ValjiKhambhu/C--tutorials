/* #include <stdio.h>
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
    n=(struct node*)malloc(sizeof(struct node));   
    n->data=data;
    n->left=NULL;
    n->right=NULL;

    return n;
    
};

void inorder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d\t",root->data);
        inorder(root->left);
        inorder(root->right);
    }
}

struct node *insert(struct node *root,int value)
{
    struct node *pre=NULL;
    while(root != NULL)
    {
        pre=root;
    
        if(root->data == value)
        {
            printf("\n value does not insert,it already here");
            return NULL;
        }
        else if(root->data > value)
        {
            root=root->left;
        }
        else{
            root=root->right;
        }
    }

    struct node *new=createnode(value);

    if(pre->data>value)
    {
        pre->left=new;
    }
    else{
        pre->right=new;
    }


};

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
    if(root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    else if(value < root->data)
    {
        root->left=delete(root->left,value);
    }
    else if(value > root->data)
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
    struct node *root=createnode(20);
    struct node *p1=createnode(15);
    struct node *p2=createnode(30);
    struct node *p3=createnode(8);
    struct node *p4=createnode(17);

    root->left=p1;
    root->right=p2;
    p1->left=p3;
    p1->right=p4;

    inorder(root);

    insert(root,35);   
    printf("%d\n",root->right->right->data);
    insert(root,25);
    printf("%d\n",rwoot->right->left->data);

    inorder(root);

    delete(root,15);

    printf("\n");
    inorder(root);
    return 0;
}*/

#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *left;
    struct node *right;
    int righttreaded;
};

struct node *createnode(int data)
{
    struct node *n;
    n=(struct node*) malloc (sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;

    n->righttreaded=0;

    return n;
};

struct node *leftmost(struct node *n)
{
    if(n == NULL)
        return n;

    while(n->left != NULL)
        n=n->left;
    return n;
};

void print(struct node *root)
{
    struct node *curl=leftmost(root);

    while(curl != NULL){
        printf("%d\t",curl->data);

        if(curl->righttreaded == 1)
            curl=curl->right;
        else
            curl=leftmost(curl->right);
    }
}

int inorder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d\t",root->data);
        inorder(root->left);
        inorder(root->right);
    }
}


int main()
{
    struct node *root=createnode(5);
    struct node *node2=createnode(10);
    struct node *node3=createnode(15);
    struct node *node4=createnode(25);
    struct node *node5=createnode(30);
    struct node *node6=createnode(35);

    root->left=node2;
    root->right=node3;

    node2->left=node4;
    node2->right=root;
    node2->righttreaded=1;

    node4->left=NULL;
    node4->right=node2;
    node4->righttreaded=1;

    node3->left=NULL;
    node3->right=node5;
    
    node5->left=node6;
    node5->right=NULL;

    node6->left=NULL;
    node6->right=node5;
    node6->righttreaded=1;

    print(root);

    return 0;
}

