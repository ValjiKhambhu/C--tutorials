#include <stdio.h>

int binarysearch(int a[],int n,int k)
{
    int start,mid,end;
    start=0;
    end=n-1;

    while(start<=end)
    {
        mid=(start+end)/2;

        if(a[mid]==k)
        {
            return mid;
        }
        if(a[mid]<k)
        {
             start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return -1;
}

int main()
{
    //int a[8]={10,20,30,40,50,50,60,70};
    int a[6],j;
    int k,n=sizeof(a)/sizeof(a[0]);

    printf("\n enter array element:");
    for(j=0;j<n;j++)
    { 
        scanf("%d",&a[j]);
    }
    printf("\n enter a found element:");
    scanf("%d",&k);
    int index=binarysearch(a,n,k);

    printf("\n the element is found index:%d",index);
    return 0;
}