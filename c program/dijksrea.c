/*#include <stdio.h>
#define INFINITY 9999
#define V 5
#define max 100

int queue[max];
int front = -1, rear = -1;

void enqueue(int item)
{
    if (rear == max - 1)
    {
        printf("\n queue is full\n");
    }
    else
    {

        if (front == -1)
        {
            front = 0;
        }
        rear = rear + 1;
        queue[rear] = item;
    }
}

int dequeue()
{
    int item;
    if (front == -1)
    {
        printf("\n queue is empty");
        return -1;
    }
    else
    {
        item = queue[front];
        front = front + 1;
        if (front > rear)
        {
            front = rear = -1;
        }
    }
    return item;
}

void dijisktra(int graph[V][V], int dist[], int start, int vis[])
{
    int i = dequeue();
    vis[i] = 1;
    for (int j = 0; j < V; j++)
    {
        if (!vis[j] && graph[i][j] != 0 && dist[j] > dist[i]+graph[i][j])
        {
            enqueue(j);
            dist[j] = dist[i] + graph[i][j];
            dijisktra(graph, dist, j, vis);
        }
    }
    vis[i] = 0;
}

void printDist(int dist[]){
    for(int i = 0; i < V; i++){
        printf("Sorce node 0 to %d distance is %d\n", i, dist[i]);
    }
}

int main()
{
    int graph[V][V] = {
        {0, 2, 6, 0, 0, },
        {5, 0, 0, 7, 0},
        {0, 0, 0, 1, 3},
        {4, 7, 1, 0, 0},
        {2, 0, 3, 0, 0}};
    int dist[V] = {INFINITY, INFINITY, INFINITY, INFINITY, INFINITY};
    int visited[V] = {0, 0, 0, 0, 0};
    dist[0] = 0;
    enqueue(0);
    dijisktra(graph, dist, 0, visited);
    printDist(dist);
}
*/

#include <stdio.h>
#define max 100

int queue[max];
int rear=-1,front=-1;

void enqueue(int item)
{
    if(rear == max-1)
    {
        printf("\n queue is empty");
    }
    else{
        if(front ==-1)
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

int a[5][5];
int visited[5],dist[5];

void dijkstra(int a[5][5],int dist[5],int start,int visited[5])
{
    int i=dequeue();
    visited[i]=1;

    for(int j=0;j<5;j++)
    {
        if(!visited[j] && a[i][j]!= 0 && dist[j]>dist[i]+a[i][j])
        {
            enqueue(j);
            dist[j]=dist[i]+a[i][j];
            dijkstra(a,dist,j,visited);
        }
    }
    visited[i]=0;
}

void print(int dist[5])
{
    for(int i=0;i<5;i++)
    {
        printf("distance of 0 to %d : %d\n",i,dist[i]);
        //printf("\n");
    }
}

int main()
{
    int a[5][5]={
        {0,5,0,4,2},
        {5,0,0,7,0},
        {0,0,0,1,3},
        {4,7,1,0,0},
        {2,0,3,0,0}
    };

    int dist[5]={9999,9999,9999,9999,9999};
    int visited[5]={0,0,0,0,0};

    dist[0]=0;
    enqueue(0);
    dijkstra(a,dist,0,visited);

    print(dist);

    return 0;
}