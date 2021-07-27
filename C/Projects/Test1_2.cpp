/*
	Noe Sancen
	program will ask user 
	to add or subtract the numbers and score wether they are right or wrong.
*/




#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void printMenu();
void add();
void subtract();
int randFunction();

int main()
{
	srand(time(NULL));
	//Define variables
	int userChoice;
	
	//input(functions)
	printMenu();
	scanf("%d", &userChoice);
	
	switch(userChoice)
	{
	case 1:
		add();
		break;
	case 2:
		subtract();
		break;
	case 3:
		break;
	default:
		printf("ERROR: select 1, 2, or 3");
	}
	
	return 0;
}

void printMenu()
{
	printf("1. Addition problems\n2.Subtraction problems\n3.Quit ");
}

void add()
{
	//declare variables
	int userAnswer, num, num2, x=0, userScore=0;
	num = randFunction();
	num2 = randFunction();
	//process
	for (x=0; x <= 4; ++x) 
	{
		//input
		num = (int)rand() % 1000;
		num2 = (int)rand() % 1000;
		printf("%d + %d = ",num, num2,x);
		scanf("%d", &userAnswer);
		if (userAnswer == (num + num2))
		{
			userScore += 1;
		}
		else if (userAnswer != (num + num2))
		{
			userScore += 0;
		}
	}
	//output
	printf("Here is how many you got correct %d", userScore);
	
}

void subtract()
{
	//declare variables
	int userAnswer, num, num2, x=0, userScore=0;
	num = randFunction();
	num2 = randFunction();
	//process
	for (x=0; x <= 4; ++x) 
	{	//input
		num = (int)rand() % 1000;
		num2 = (int)rand() % 1000;
		printf("%d - %d = ",num, num2,x);
		scanf("%d", &userAnswer);
		if (userAnswer == (num - num2))
		{
			userScore += 1;
		}
		else if (userAnswer != (num - num2))
		{
			userScore += 0;
		}
	}
	//output
	printf("Here is how many you got correct %d", userScore);		
}

int randFunction()
{
	int num, num2;
	// get a random number
	num = rand() % 100+1;
	num2 = rand() % 100+1;
	return num, num2;	
}





