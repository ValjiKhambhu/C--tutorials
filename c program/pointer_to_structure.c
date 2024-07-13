#include <stdio.h>

struct student
{
    int rollno;
    char name[50];
};

int main()
{
    int i;
    struct student s[3],*ptr[3];

    for(i=0;i<3;i++)
    {
        ptr[i]=&s[i];

        printf("\n enter a rollno of student %d:",i+1);
        scanf("%d",&ptr[i]->rollno);
        printf("\n enter a name of student %d:",i+1);
        scanf("%s",ptr[i]->name);
    }

    for(i=0;i<3;i++)
    {
        printf("\n rollno of student %d:%d",i+1,ptr[i]->rollno);
        printf("\n name of student %d:%s",i+1,ptr[i]->name);
    }
    return 0;
}