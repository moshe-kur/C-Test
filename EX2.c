#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)


int main2()
{
    char name[100];
    scanf("%s", name);


    int namelen = strlen(name);


   
    while (namelen!=0)  //OR:  !=1 to print without empty line
    {
        namelen = namelen / 2;
        int i = 0;
        char helf[50];
        strncpy(helf,name, namelen);
        helf[namelen] = 0;
        printf("%s\n", helf);


    }


    //printf("%s", name);
    return 0;
}