#include <stdio.h>

int main()
{
    //int a[6]={34,90,54,90,15,20};
    int a[6],j;
    int i,x,flag=0;

    printf("\n enter array items:");
    for(j=0;j<6;j++)
    {
        scanf("%d",&a[j]);
    }
    printf("\n enter a your item:");
    scanf("%d",&x);

    for(i=0;i<6;i++)
    {
        if(x==a[i])
        {
            printf("\n your item is index:%d",i+1);
            flag++;
            break;
        }
    }

    if(flag==0)
    {
        printf("\n item is not found");
    }

    return 0;
}