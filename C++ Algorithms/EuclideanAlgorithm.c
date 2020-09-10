

/****************************Libraries, Constants and Global Variables***********************/
#include <stdio.h>


/**************************************Function Prototypes***********************************/
int eucAlg( int a, int b );




/*********************************************Main********************************************/
int main()
{
	int firstInt;
	int secondInt;
	int gcd;

	printf("The Euclidean Algorithm determines the greatest common denominator of two positive integers. \n");
	do
	{
		printf("Enter the first integer: ");
		scanf("%d", &firstInt);
		printf("\nEnter the second integer: ");
		scanf("%d", &secondInt);
		printf("\n");

		if( firstInt <= 0 || secondInt <= 0 )
			printf("Positive integers (greater than 0) must be entered.\n");

	}while( firstInt <= 0 || secondInt <= 0 );

	gcd = eucAlg( firstInt, secondInt );

	printf("\n");
	printf("The greatest common denominator of %d and %d is: %d.\n", firstInt, secondInt, gcd);

}//end main


/********************************************EucAlg*******************************************/
int eucAlg( int a, int b )
{
	int r;

	while( b != 0 )
	{
		r = a % b;
		a = b;
		b = r;

	}//end while

	return a;

}//end eucAlg




