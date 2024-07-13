#include <stdio.h>
#define max 100

int queue[max];
int rear=-1,front=-1;

void enqueue(int item)
{
    if(rear == max-1)
    {
        printf("\n queue is full");
    }
    else{
        if(front == -1)
        {
            front=0;
        }
        rear=rear+1;
        queue[rear]=item;
    }
}

int dequeue()
{
    int item;
    if(front == -1)
    {
        printf("\n queue is empty");
        rear=-1;
    }
    else{
        item=queue[front];
        front=front+1;
        if(front>rear)
        {
            rear=front=-1;
        }
    }
    return item;
}

int isempty()
{
    return (front == -1);
}

int a[max][max];
int visited[max];
int n;

void bfs(int startnode)
{
    enqueue(startnode);
    visited[startnode]=1;

    while(!isempty())
    {
        int current=dequeue();
        printf("%d ",current);

        for(int i=0;i<n;i++)
        {
            if(!visited[i] && a[current][i]==1)
            {
                enqueue(i);
                visited[i]=1;
            }
        }
    }
}

int main()
{
    int i,j,startnode;

    printf("\n enter a number of nodes in fraph:");
    scanf("%d",&n);

    printf("\n enter a matrix of graph:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    for(i=0;i<n;i++)
    {
        visited[i]=0;
    }

    printf("\n enter a starting node of graph:");
    scanf("%d",&startnode);

    printf("\n bfs traversal of graph startnode is %d",startnode);
    bfs(startnode);

    return 0;
}