#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAX 0.06

struct Purchase
{
	int invNum;
	float price;
	float tax;
	float total;		
};

typedef struct Purchase PR;
void loadArray(PR[]);
void calc(PR[]);
char printMenu(PR[]);
void searchInvoices(PR[]);

int main()
{
	
	
	PR objects[20];
	char choice;
	do{
	
	loadArray(objects);
	calc(objects);
	choice = printMenu(objects);
	switch(choice)
	{
		case 'P': case 'p':
		//	display(objects);
			break;
		case 'I': case'i':
			searchInvoices(objects);
			break;
		case 'H': case'h':
		//	findHighest(objects);
			break;
		case 'Q': case'q':
			break;
		default:
			printf("\nERROR - Invalid entry");
	}
	}while(choice != 'Q' || choice != 'q');
	
	return 0;
}

void loadArray(PR oArray[])
{
	//file pointer *inFile
	FILE *inFile;
	char filename[50];
	char str[81];
	char *p;
	int x = 0; //counter set to a 0 for first position.
	
//	printf("Enter the file name: ");
//	gets(filename);
	
	if ((inFile = fopen("Purchases.csv", "r")) == NULL)
	{
		printf("Error opening file - program ending");
		exit(1);
	}
	
	//Tokenize
	while(fgets(str, 80, inFile) != NULL)
	{
		p = strtok(str, ",");// picks up from beginning of str
		oArray[x].invNum = atoi(p);
		p = strtok(NULL, ",");
		oArray[x].price = atof(p);
		p = strtok(NULL, ",");
		oArray[x].tax = atof(p);
		p = strtok(NULL, ",");
		oArray[x].total = atof(p);
	//	printf("\n%d    %.2f", oArray[x].invNum,	oArray[x].price); check if the data is there
		
		++x; // increment AFTER printing for debug
	}
	
	
}

void calc(PR oArray[])
{
	int x;
	for (x=0; x<20; ++x)
	{
		oArray[x].tax = oArray[x].price * TAX;
		oArray[x].total = oArray[x].price + oArray[x].tax;
		printf("\n%d %.2f %.2f", oArray[x].invNum, oArray[x].tax, oArray[x].total);
		
	}
}

char printMenu(PR oArray[])
{
	char choice;
	printf("\n\n ****** MENU *******");
	printf("\n p - print all invoices");
	printf("\n I - search by invoice number");
	printf("\n H - search for highest cost invoice");
	printf("\n Q - Quit");
	printf("\nEnter choice: ");
	scanf(" %c", &choice);
	
	return choice;
}

void searchInvoices(PR oArray[])
{
	int x;
	int invoice;
	do
	{
	
	printf("Enter invoice to search for: ");
	scanf("%d", &invoice);
	}while(invoice < 1000 || invoice > 8000);
	
	for(x = 0; x<20; ++x)
	{
		if (invoice == oArray[x].invNum)
		{
			printf("\n%d", oArray[x].invNum);
			break;
		}
	}
	if (x == 20)
		printf("\nInvoice not found");	
	
	
	
	
}
	/*
	char str[]="This is my string";
	int x;
	
	for(x=0;x<7;++x)
		printf(" %c",*(str+x));
	
	float prices[]={3.99,5.99,2.99,12.99};
	float *pPtr = &prices[0]
	
	
	
	*/
