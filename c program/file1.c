#include <stdio.h>

int main()
{
    FILE *ptr=NULL;
    //char *ptr;
    char str[30];
    ptr=fopen("file1.txt","r");
    fscanf(ptr,"%s",str);

    printf("%s",str);
    return 0;
}