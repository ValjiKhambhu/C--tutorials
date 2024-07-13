#include<stdio.h>


void merge(int a[], int low,int  mid,int  high)
{
    int i,j,k,b[100];
    i=low;
    j=mid+1;
    k=low;

    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];
            i++;
            k++;
        }
        else
        {
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
    while(j<=high)
    {
        b[k]=a[j];
        k++;
        j++;
    }

    for(int i=low;i<=high;i++)
    {
        a[i]=b[i];
    }

}

void mergesort(int a[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
} 

void print(int a[],int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}

int main()
{   
    int a[]={5,9,35,15,7,3,2,12};
    int n=8;

    printf("\n before sorting:\n");
    print(a,n);
    mergesort(a,0,7);
    printf("\n after sorting:\n");
    print(a,n);
    return 0;
}