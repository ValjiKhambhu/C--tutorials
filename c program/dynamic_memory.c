#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,*ptr,sum=0;

    printf("\n enter a number:");
    scanf("%d",&n);

    ptr=(int *)malloc(n*sizeof(int));

    printf("\n enter a %d a number:\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",ptr);
        sum=sum+(*ptr);
    }

    printf("sum=%d",sum);
    return 0;
}