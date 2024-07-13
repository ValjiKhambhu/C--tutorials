#include <stdio.h>

void merge(int a[],int beg,int mid,int end)
{
    int i,j,k,b[100];
    i=beg;
    j=mid+1;
    k=beg;
    while(i<=mid && j<=end)
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];
            i++;
            k++;
        }
        else{
            b[k]=a[j];
            j++;
            k++;
        }
    }
    while(i<=mid)
    {
        b[k]=a[i];
        k++;
        i++;
    }
    while(j<=end)
    {
        b[k]=a[j];
        k++;
        j++;
    }
    for(int i=beg;i<=end;i++)
    {
        a[i]=b[i];
    }
}

void mergesort(int a[],int beg,int end)
{
    int mid;
    if(beg<end)
    {
        mid=(beg+end)/2;
        mergesort(a,beg,mid);
        mergesort(a,mid+1,end);
        merge(a,beg,mid,end);
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
    int a[8];
    int n=8;
    printf("\n enter a array element:");
    for(int k=0;k<n;k++)
    {
        scanf("%d",&a[k]);
    }
    printf("\n before sorting:\n");
    print(a,n);
    mergesort(a,0,7);
    printf("\n after sorting:\n");
    print(a,n);
    return 0;
}