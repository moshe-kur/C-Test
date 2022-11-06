#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)


int add100(int num)
{
	printf("%d\n", num);
	return num == 100 ? 0 : add100(num + 1);
}

int main3()
{
	add100(1);

	return 0;
}