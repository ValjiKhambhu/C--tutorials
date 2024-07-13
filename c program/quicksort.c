#include <stdio.h>

int partition(int a[],int start,int end)
{
    int p,i,j,temp;
    i=start-1;
    p=a[end];

    for(j=start;j<=end;j++)
    {
        if(a[j]<p)
        {
            i++;
            temp=a[j];
            a[j]=a[i];
            a[i]=temp;
        }
    }
    temp=a[i+1];
    a[i+1]=a[end];
    a[end]=temp;

    return (i+1);
}

void quicksort(int a[],int start,int end)
{
    int pivot;
    if(start<end)
    {
        pivot=partition(a,start,end);
        quicksort(a,start,pivot-1);
        quicksort(a,pivot+1,end);
    }
}

void print(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}

int main()
{
    int a[8]={45,89,25,67,16,8,90,3};
    int n=sizeof(a)/sizeof(a[0]);

    printf("\n before sorting:\n");

    print(a,n);
    quicksort(a,0,n-1);

    printf("\n after sorting:\n");
    print(a,n);

    return 0;
}