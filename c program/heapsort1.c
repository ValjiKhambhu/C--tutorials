#include <stdio.h>

void heapify(int a[],int n,int i)
{
    int largest=i;
    int l=(i*2)+1;
    int r=(i*2)+2;

    if(l<n && a[l]>a[largest])
    {
        largest=l;
    }

    if(r<n && a[r]>a[largest])
    {
        largest=r;
    }   

    if(largest != i)
    {
        int temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        heapify(a,n,largest);
    }
}

void heapsort(int a[],int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        heapify(a,n,i);
    }
    for(int i=n-1;i>=0;i--)
    {
        int temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        heapify(a,i,0);
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
    int a[7]={35,89,24,9,15,78,3};
    int n=sizeof(a)/sizeof(a[0]);

    printf("\n before sorting:\n");
    print(a,n);
    heapsort(a,n);
    printf("\n after sorting:\n");
    print(a,n);
    return 0;
}