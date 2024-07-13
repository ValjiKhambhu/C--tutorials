#include <stdio.h>

void heapify(int a[],int n,int i)
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n && a[left]>a[largest])
    {
        largest=left;
    }

    if(right<n && a[right]>a[largest])
    {
        largest=right;
    }

    if(largest!=i)
    {
        int temp=a[largest];
        a[largest]=a[i];
        a[i]=temp;

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
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d \t",a[i]);
    }
}

int main()
{
    int a[7],i;
    int n=sizeof(a)/sizeof(a[0]);

    printf("\n enter a array element:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    printf("\n before sorting:\n");

    print(a,n);
    heapsort(a,n);

    printf("\n after sorting:\n");
    print(a,n);

    return 0;
}