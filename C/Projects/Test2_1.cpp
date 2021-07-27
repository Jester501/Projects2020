/*
	Noe Sancen

*/


#include <stdio.h>
void calcMetric(float*, float*);

int main()
{
	char answer;
	do{
	
	float userFeet, userInches, totalInches=0, userMeter1=0, userMeter2=0;
	
	
	printf("Welcome to the Metric Calculation program!");
	printf("\nEnter a length in feet and inches");
	printf("\nand I will convert it to meters and centimeters for you");
	printf("\n\nEnter the feet: ");
	scanf("%f", &userFeet);
	printf("Enter the inches: ");
	scanf("%f", &userInches);
	
	userMeter1 += userFeet;
	userMeter2 += userInches;
	totalInches = (userFeet * 12) + userInches;
	
	printf("Total inches = %.2f", totalInches);
	
	calcMetric(&userMeter1,&userMeter2);
	
	printf("\n\n%.0f feet, %.0f inches is equivalent to",userFeet, userInches);
	printf("\n%.0f meters and %.2f centimeters", userMeter1, userMeter2);
	
	printf("\nDo you wish to continue? (y/n) ");
	scanf(" %c",&answer);
	printf("\n");
	}
	while(answer == 'y'|| answer == 'Y');
	
	return 0;
}

void calcMetric(float *feet,float *inches)
{
	float meters=0;
	
	*feet = ((*feet * 12) / .39370) / 100;
	*inches = (*inches * .39370) * 10;
	
	
}
