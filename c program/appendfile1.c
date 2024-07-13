#include <stdio.h>

int main()
{
    FILE *ptr=NULL;
    char str[50]=" software engineer IT";

    ptr=fopen("file2.txt","a");
    fprintf(ptr,"%s",str);
    return 0;
}