/*#include <stdio.h>
#define max 100

int queue[max];
int front=-1,rear=-1;

void enqueue(int item)
{
    if(rear == max-1)
    {
        printf("\n queue is full\n");
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
        return -1;
    }
    else{
        item=queue[front];
        front=front+1;     
        if(front>rear)
        {
            front=rear=-1;
        }
    }
    return item;
}

int isempty()
{
    return (front==-1);
}

int a[max][max];
int visited[max];
int n;

void bfs(int start)
{
    enqueue(start);
    visited[start]=1;
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

    printf("\n enter a number of nodes in graph:");
    scanf("%d",&n);

    printf("\n \n enter a matrix of graph:\n");

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    printf("\n enter the starting node of graph:");
    scanf("%d",&startnode);

    printf("\n bfs traversal of graph starting node :\n");
    bfs(startnode);

    return 0;
}
*/

#include <stdio.h>
#define max 100
int queue[max];
int rear=-1,front=-1;

void enqueue(int item)
{
    if(rear==max-1)
    {
        printf("\n queue is full\n");
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
        printf("\n queue is empty\n");
    }
    else{
        item=queue[front];
        front=front+1;
        if(front>rear)
        {
            front=rear=-1;
        }
    }
    return item;
}

int a[10][10];
int visited[7];
int n,start; 

void bfs(int start)
{
    enqueue(start);

    while(queue[front]!=-1)
    {
        int current=dequeue();
        printf("%d ",current);
        visited[current]=1;

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
    printf("\n enter a number of vertex in graph:");
    scanf("%d",&n);

    printf("\n enter a graph matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    printf("\n enter a starting node in graph:");
    scanf("%d",&start);

    printf("\n bfs traversal:");
    bfs(start);
    return 0;
}