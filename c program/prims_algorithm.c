#include <stdio.h>
#define max 5
#define v 4

int queue[max];
int rear=-1,front=-1;

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

int graph[v][v];
int visited[v];
int total_weight=0;

void prims(int graph[v][v],int visited[v])
{
    int m=-1,n=-1;
    for(int i=0;i<=rear;i++)
    {
        for(int j=0;j<v;j++)
        {
            int k=queue[i];

            if(visited[j] != 1 && graph[k][j] != 0)
            {
                if(m == -1)
                {
                    m=k;
                    n=j;
                }
                else if(graph[k][j]<graph[m][n])
                {
                    m=k;
                    n=j;
                }
            }
        }
    }

    if(m != -1)
    {
        enqueue(n);
        visited[n]=1;

        printf("node %d to %d weight is:%d \n",m,n,graph[m][n]);

        total_weight += graph[m][n];

        prims(graph,visited);
    }
}

int main()
{
    int graph[v][v]={
            {0,10,15,30},
            {10,0,0,40},
            {15,0,0,50},
            {30,40,50,0}
        };

        int visited[v]={0,0,0,0};

        enqueue(1);

        visited[1]=1;

        prims(graph,visited);

        printf("\n total weight: %d",total_weight);

    return 0;
}