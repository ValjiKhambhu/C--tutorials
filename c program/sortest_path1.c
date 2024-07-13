#include <stdio.h>
#define infinity 99
#define max 10
#define startnode 0

void dijkstra(int cost[max][max],int n);

int main()
{
    int cost[max][max],i,j,n,u;
    printf("\n enter no.of vertices:");
    scanf("%d",&n);

    printf("\n enter the cost matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);
        }
    }

    dijkstra(cost,n);

    return 0;
}

void dijkstra(int cost[max][max],int n)
{
    int distance[max],pred[max];
    int visited[max],count,mindistance ,nextnode ,i,j;

    for(int i=0;i<n;i++)
    {
        distance[i]=cost[startnode][i];
        pred[i]=startnode;
        visited[i]=0;
    }

    distance[startnode]=0;
    visited[startnode]=1;
    count=1;

    while(count<n-1)
    {
        mindistance=infinity;
        for(i=0;i<n;i++)
        {
            if(distance[i]<mindistance && !visited[i])
            {
                mindistance=distance[i];
                nextnode=i;
            }
        }
    }

    visited[nextnode]=1;
    for(i=0;i<n;i++)
    {
        if(!visited[i])
        {
            if(mindistance+cost[nextnode][i]<distance[i])
            {
                distance[i]=mindistance+cost[nextnode][i];
                pred[i]=nextnode;
            }
            count++;
        }
    }

    for(i=0;i<n;i++)
    {
        if(i!=startnode)
        {
            printf("\n distance of node %d = %d",i,distance[i]);
            printf("\n path=%d",i);
            j=i;
            do
            {
                j=pred[j];
                printf("<- %d",j);
            }while(j != startnode);
        }
    }
}