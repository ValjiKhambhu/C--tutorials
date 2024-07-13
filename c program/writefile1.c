#include <stdio.h>

int main()
{
    FILE *ptr=NULL;
    char str[50]="software developer";

    ptr=fopen("writefile1.txt","w");
    fprintf(ptr,"%s",str);
    
    return 0;
}