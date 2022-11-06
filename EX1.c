#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)


int main1()
{
    char name[100];
    scanf("%s", name);


    int namelen = strlen(name);


    for (int i = 0; i < namelen; i++)
    {
        if (i==namelen/2)
        {
            printf("\n");

        }
        printf("%c", name[i]);

    }

    //printf("%s", name);
    return 0;
}