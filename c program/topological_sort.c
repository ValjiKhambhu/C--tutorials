#include <stdio.h>
#define max 6
int top=-1;
int stack[max];
void push(int item)
{
    if(top == max-1)
    {
        printf("\n stack is full \n");
    }
    else{
        //printf("\n yes\n");
        top=top+1;
        stack[top]=item;
    }
}

int pop()
{
    int item;
    if(top == -1)
    {
        printf("\n stack is empty");
        return -1;
    }
    else{
        //printf("\n yes\n");
        item=stack[top];
        top=top-1;
    }
    return item;
}

int graph[max][max];
int visited[max],i;

void topological(int start)
{
    //int j=0;
    //printf("%d ",start);
    visited[start]=1;

    for(i=0;i<max;i++)
    {
        if(!visited[i] && graph[start][i] == 1)
        {
            topological(i);
            //j++;
        }  
    }

    push(start);

}

void print()
{
    while(top != -1)
    {
        int item=pop();
        printf("%d ",item);
    }
}

int main()
{
    int graph[max][max]={
        {0,1,0,1,0},
        {0,0,1,1,0},
        {0,0,0,0,1},
        {0,0,1,0,0},
        {0,0,0,0,0},
        //{1,0,1,0,0,0}
    };

    int visited[max]={0,0,0,0,0,0};

    topological(0);
    print();

    return 0;
}