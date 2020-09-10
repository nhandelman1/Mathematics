
/*******************************************Libraries************************************/
#include <stdio.h>



/**************************************Function Prototypes*******************************/
int factorial( int n );



/*********************************************Main***************************************/
int main()
{
	int obj, box, perm;

	printf("This program calculates the r-permutations of a set with n distinct elements.\n");

	do
	{
		printf("Enter the number (n) of distinct elements (n > 0): ");
		scanf("%d", &obj);
		printf("\nEnter the value for r (1 <= r <= n): ");
		scanf("%d", &box);
		printf("\n");

		if( obj <= 0 )
			printf("The number of distinct elements must be greater than 0. \n");

		if( box < 1 || box > obj )
			printf("The value of r must be greater than 0 and less than or equal to the number of distinct elements. \n");

	}while( obj <= 0 || box < 1 || box > obj );

	perm = (factorial( obj ) / factorial( obj - box ));

	printf("The number of %d-permutations for a set of %d distinct elements is: %d. \n", box, obj, perm);

}//main


/*******************************************Factorial************************************/
int factorial( int n )
{
	int x;
	int fact = 1;

	for( x = n; x > 1; x-- )
		fact *= x;

	return fact;

}//factorial
