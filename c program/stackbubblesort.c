#include <stdio.h>
#include <conio.h>
#define size 5
int array[size];
int top=-1;
void push();
void pop();
void show();

int main()
{
    int choice;
    while(1);
    {
        printf("\n perform stack operation :");
        printf("\n 1.push \n2.pop \n3.show \n4.exit \n");
        printf("\n enter a your choice \n:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            push();
            break;

            case 2:
            pop();
            break;

            case 3:
            show();
            break;

            /*case 4:
            exit(0);
            break;*/

            default:
            printf("\n invalid choice:");

        }
    }
    getch();
    return 0;
}

void push()
{
    int a;
    if(top==size-1)
    {
        printf("\n overflow");
    }
    else{
        printf("\n enter a stack element:\n");
        scanf("%d",&a);
        array[top]=a;
        top=top+1;
    }
}

void pop()
{
    if(top==-1)
    {
        printf("\n underflow");

    }
    else{
        printf("pop element in stack:%d",array[top]);
        top=top-1;
    }
}

void show()
{
    int i;
    if(top==-1)
    {
        printf("\n underflow");
    }
    else
    {
        printf("\n stack element:\n");
        for(i=top;i>=0;i--)
        {
            printf("%d ",array[i]);
        }
    }
}