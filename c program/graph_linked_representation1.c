#include <stdio.h>
#include <stdlib.h>
#define maxnode 4

typedef struct node 
{
    int vertexnum;
    struct node *next;
}node;

typedef struct list
{
    node *head;
}list;

list *adjlist[maxnode]={0};

void addnode(int,int);
void printlist();

int main()
{
    int i;
    for(i=0;i<maxnode;i++)
    {
        adjlist[i]=(list *)malloc(sizeof(list));
        adjlist[i]->head=NULL;
    }

    addnode(0,1);
    addnode(0,3);
    addnode(1,2);

    printlist();

    return 0;
}

void addnode(int s,int d)
{
    node *dest,*temp,*src;

    if(adjlist[s]->head == NULL)
    {
        src=(node *)malloc(sizeof(node));
        src->vertexnum=s;
        src->next=NULL;
        adjlist[s]->head=src;
    }

    dest=(node *)malloc(sizeof(node));
    dest->vertexnum=d;
    dest->next=NULL;
    temp=adjlist[s]->head;

    while(temp->next != NULL)
    {
        temp=temp->next;
    }
    temp->next=dest;
}

void printlist()
{
    int i;
    for(i=0;i<maxnode;++i)
    {
        node *p=adjlist[i]->head;
        printf("adjacency list for vertex %d\n",i);

        while(p)
        {
            printf("%d ",p->vertexnum);
            p=p->next;
        }
        printf("\n");
    }
}