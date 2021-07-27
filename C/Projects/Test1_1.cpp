/*
	Noe Sancen
	program will ask user 
	to enter number hours and miles while multiplying them together
*/




#include <stdio.h>

int main()
{
	//Define variables
	int userSpeed, userHour,x,totalDistance;
	
	//input(functions)
	printf("What is the speed of the vehicle in mph? ");
	scanf("%d", &userSpeed);
	printf("How many hours has it traveled? ");
	scanf("%d", &userHour);
	printf("\nHour		DistanceTraveled");
//	process
	
	for (x = 0; x <= userHour; x += 1) // ; semicolon will make for loop a NULL
	{	
		//OutPut
		printf("\n%.0d ", x);
		totalDistance = userSpeed * x;
	
		printf(" %20.0d ", totalDistance);
	}
	
	return 0;
}


