/*#include <stdio.h>
#include <stdlib.h>

int visited[7] ={0,0,0,0,0,0,0};
    int A[7][7]={
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };

    void dfs(int);

int main()
{

    dfs(6);

    return 0;
}

void dfs(int i)
{
    int j;
    printf("%d ",i);

    visited[i] = 1;
    for(j=0;j<7;j++)
    {
        if(A[i][j] == 1 && !visited[j])
        {
            dfs(j);
        }
    }
}*/


#include <stdio.h>

int a[10][10];
int n,start;
int visited[7];

void dfs(int start)
{
    printf("%d ",start);

    visited[start]=1;

    for(int i=0;i<n;i++)
    {
        if(!visited[i] && a[start][i])
        {
            dfs(i);
        }
    }
}

int main()
{
    int i,j;
    printf("\n enter a number of node in graph:");
    scanf("%d",&n);

    printf("\n enter a graph matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    printf("\n enter a starting node of graph:");
    scanf("%d",&start);

    printf("\n dfs traversal:\n");
    dfs(start);
    return 0;
}