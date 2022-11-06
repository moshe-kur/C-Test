#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)


struct Lotto
{
	int ID;
	int LotoNumber;
	char Date[20];
	//char* UpNumbers[40];
	struct Lotto* next;
	struct Lotto* prev;
};
struct Lotto* HEAD;
struct Lotto* TAIL;
struct Lotto* curr=NULL;
void ReadMemory();
void MakeList(struct Lotto* curr);
void search(int number);


int main()
{

	ReadMemory();

	printf("Hi Dear User \nWhat would you like to do?\n N-Take One SnapShot\n Q-to EXIT\n");

	char userResponse = 0;
	int Usernumber;
	while (userResponse != 'Q')
	{

		scanf(" %c", &userResponse);

		switch (userResponse)
		{
		case 'N':
			scanf("%d", &Usernumber);
			search(Usernumber);
			break;

		}
		printf("Hi Dear User \nWhat would you like to do?\n N-Take One SnapShot\n Q-to EXIT\n");
	}


	return 0;
}


void ReadMemory()
{

	FILE* f = fopen("Lotto.txt", "r");
	if (!f)
	{
		//error
		
	}
	char str[1000];
	char* token = NULL;
	fgets(str, 1000, f);
	while (str[0] != NULL)
	{
		
		curr = (struct Lotto*)malloc(sizeof(struct Lotto));
		if (!curr)
		{
			//error
			break;
		}
		token = strtok(str, ",");
		int num;
		num = atoi(token);
		curr->LotoNumber = num;

		token = strtok(NULL, ",");
		strcpy(curr->Date, token);

		/*
		for (int i = 0; i < 9; i++)
		{
			token = strtok(NULL, ",");
			
			strcat(curr->UpNumbers, token);

		}
		*/

		MakeList(curr);
		//MATA-DATA

		str[0] = NULL;
		fgets(str, 1000, f);


	}

}


void MakeList(struct Lotto* curr)
{

	if (HEAD == NULL)
	{
		HEAD = TAIL = curr;
		curr->next = NULL;
		curr->prev = NULL;
	}
	else
	{
		TAIL->next = curr;
		curr->prev = TAIL;
		curr->next = NULL;

		TAIL = curr;
	}

}

void search(int number)
{
	struct Lotto* Look; 
	Look = HEAD;


	while (Look->LotoNumber != number)
	{
		if (Look->next != NULL)
		{
			Look = Look->next;
		}
		else
		{
			break;
		}
		
	}
	if (Look->next == NULL)
	{
		printf("NOT FOUND\n");
	}
	else
	{
		printf("%s\n", Look->Date);

		/*
		for (int i = 0; i < 9; i++)
		{
			printf("%s\n", Look->UpNumbers);
		}
		*/
	}
	
}