/*
	Noe Sancen

*/


#include <stdio.h>
void getInfo(char[],float *);
void getScores(float[]);
int calcScore(float[], float *,float *);

int main()
{
	char answer;
	do{
	char diverName[50];
	float scores[7], userDif, totS, total=0;
	getInfo(diverName, &userDif);
	getScores(scores);
	calcScore(scores, &totS, &userDif);
	total = totS + (userDif/10);
	
	printf("\nDiver name: %s", diverName);
	printf("\nDegree of difficulty: %.1f", userDif);
	printf("\nTotal score: %.2f", total);// add score and difficulty together

	printf("\nDo you wish to continue? (y/n) ");
	scanf(" %c",&answer);
	printf("\n");
	}
	while(answer == 'y'|| answer == 'Y');

	return 0;
}

int calcScore(float scores[], float *totS,float *userDif)
{
	float score=0, total=0;
	int x,difNum=0;
	difNum += *userDif;
	for(x=0; x<7; ++x)
	{
	score += scores[x];	
		
	}
	total = (difNum / 10) + score;
	*totS+= total;
	
	return 0;
	
}

void getScores(float scores[])
{
	int x;
	
	for(x=0; x < 7; ++x)
	{
		printf("Enter judge %d score: ", x+1);
		scanf("%f", &scores[x]);
	}
}

void getInfo(char diverName[],	float *userDif)
{
	float difNum=0;

	printf("Noe Sancen\n");
	printf("Welcome to the Olympic Diving Program!\n");
	printf("Please enter divers name: ");
	gets(diverName);
	printf("Please enter the degree of difficulty:  ");
	scanf("%f", &difNum);
	*userDif += difNum;
	
	//validate
	if ((*userDif > 1.2) && (*userDif < 3.8))
	{

	}
	else
	{
		printf("Invalid Entry! Values must be between 1.2 and 3.8");
	}
	
}





