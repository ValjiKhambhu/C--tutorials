#include <stdio.h>
#include <stdlib.h>
#define infinity 9999

typedef enum{
    thread,link
}boolean;

struct node 
{
    struct node *left_ptr;
    boolean left;
    int info;
    boolean right;
    struct node *right_ptr;
}*head=NULL;

int main()
{ 
    int choice,num;
    insert();

    while(1)
    {
        printf("\n");
        printf("\n1.insert");
        printf("\n2.inorder traversal");
        printf("\n3.quit");
        printf("\n enter your choice:\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            printf("\n enter number to be insert:\n");
            scanf("%d",&num);
            insert(num);
            break;

            case 2:
            inorder();
            break;

            case 3:
            exit(0);
            break;

            default:
            printf("\n wrong choice\n");

        }
    }
    return 0;
}

int insert()
{
    struct node *temp;
    head=(struct node*) malloc (sizeof(struct node));

    head->info=infinity;
    head->left=thread;
    head->left_ptr=head;
    head->right=link;
    head->right_ptr=head;
}

int find(int item,struct node **par,struct node **loc)
{
    struct node *ptr,*ptrsave;

    if(head->left_ptr == head)
    {
        *loc =NULL;
        *par=head;

        return;
    }

    if(item == head->left_ptr->info)
    {
        *loc=head->left_ptr;
        *par=head;

        return;
    }

    ptr=head->left_ptr;

    while(ptr != head)
    {
        ptrsave=ptr;

        if(item <ptr->info)
        {
            if(ptr->left == link)
            {
                ptr=ptr->left_ptr;
            }
            else
            {
                break;
            }
        }

        else if(item>ptr->info)
        {
            if(ptr->right == link)
            {
                ptr=ptr->right_ptr;
            }
            else{
                break;
            }
        }

        if(item == ptr->info)
        {
            *loc=ptr;
            *par=ptrsave;
        }
    }
    *loc=NULL;
    *par=ptrsave;
}

int insert(int item)
{
    struct node *temp,*parent,*location;
    find(item,&parent,&location);

    if(location != NULL)
    {
        printf("\n item is already present\n");
        return;
    }

    temp=(struct node *) malloc (sizeof(struct node));
    temp->info=item;
    temp->left=thread;
    temp->right=thread;

    if(parent == head)
    {
        head->left=link;
        head->left_ptr=temp;
        head->left_ptr=head;
        temp->right_ptr=head;
    }
    else if(item < parent->info)
    {
        temp->left_ptr=parent->left_ptr;
        temp->right_ptr=parent;
        parent->left=link;
        parent->left_ptr=temp;
    }

    else{
        temp->left_ptr=parent;
        temp->right_ptr=parent->right_ptr;
        parent->right=link;
        parent->right_ptr=temp;
    }
}

struct node *in_succ(struct node *ptr)
{
    struct node *succ;

    if(ptr->right == thread)
    {
        succ=right->right_ptr;
    }
    else{
        ptr=ptr->right_ptr;

        while(ptr->left == link)
        {
            ptr=ptr->left_ptr;
            
        }
        succ=ptr;
    }return succ;
};

struct node *in_pred(struct node *ptr)
{
    struct node *pred;
    if(ptr->left == thread)
    {
        pred=ptr->left_Ptr;
    }
    else{
        ptr=ptr=ptr->left_ptr;
        while(ptr->right_ptr)
        pred=ptr;
    }
    return pred;
};

void inorder()
{
    struct node *ptr;
    if(head->left_ptr== head)
    {
        printf("\n the tree is empty");
        return;
    }
    ptr=head->left_ptr;

    while(ptr->left == link)
    {
        ptr=ptr->left_ptr;
        if(ptr == head)
        {
            break;
        }
        printf("%d",ptr->info);
    }
}