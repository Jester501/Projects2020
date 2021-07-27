#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define RATE 12.25   <----originally a define statement but changed it after reading directions again.

struct Payment // stucture which is creating your own global built-in function ex: int, float, char.
{
	float babyHour;
};


void loadData(char [], char []);
float CalcAvgPay(char [], char [], float);
void printData(float, char[]);
typedef struct Payment PAY; 

int main()
{
	char fileName[60];
	FILE *inFile;
	char babyName[60];
	float monthAvgPay, yearAvgPay;
	float payRate = 12.25;
	
	// NAME
	printf("Noe Sancen\n\n");
	
//	PAY 
	loadData(fileName, babyName);
	yearAvgPay = CalcAvgPay(fileName, babyName, payRate); // throws in 3 functions and returns the Average pay of the year.
	printData(yearAvgPay, babyName);

	return 0;
}

void loadData(char fileName[], char babyName[])
{
	FILE *inFile;
	
	printf("Type in the babysitters name: "); // type in the name of the wages of the person
	gets(babyName);
	printf("Type the filename: "); // type in the file with the informatioin
	gets(fileName);
	
	//babysitter.txt
}

float CalcAvgPay(char fileName[], char babyName[], float payRate)
{
	char str[11];	//array to hold 11 lines of data 
	FILE *inFile;
	char *p;
	int x=0;
	int month=0;
	float monthAvgPay, yearPay, yearAvgPay;
	PAY nArray[20];
	
	if ((inFile = fopen(fileName, "r")) == NULL)
	{
		printf("Error opening file - program ending");
		exit(1);
	}
	
	while(fgets(str, 11, inFile) != NULL) // array that grabs 11 lines from (inFile which is babysitter.txt). 12th line is the rate of pay which 12.25
	{
		p = strtok(str, ",");
		nArray[x].babyHour = atof(p);
	
		++x;	
	}
	
	printf("\nMonthly Totals for %s:", babyName);
	printf("\nMonth	   Hours	         Pay	", inFile);
	
	for(x=0; x<12;++x)
	{
		monthAvgPay = nArray[x].babyHour * payRate;
		
		month += 1;
		printf("\n%d", month);
		printf(" %13.2f", nArray[x].babyHour);
		printf("          %10.2f", monthAvgPay);
		yearPay += monthAvgPay;		
	}
	
	yearAvgPay = yearPay / 12;// averages the pay by the year.
	return yearAvgPay;
}

void printData(float yearAvgPay, char babyName[])
{
	printf("\n\nThe Average pay for %s for the year is $%.2f", babyName,yearAvgPay);// print out the data that extracts the information.
}





