#include <stdio.h>

int main()
{
	int val = 0, x = 0;
	int fact = 1;

	printf("This program calculates the factorial of a given nonnegative integer.\n");

	do
	{
		printf("Enter the value for which the factorial will be calculated: ");
		scanf("%d", &val);
		printf("\n");

		if( val < 0 )
			printf("The value must be a nonnegative integer. \n");

	}while( val < 0 );

	for( x = val; x > 1; x-- )
		fact *= x;

	printf("The value of %d-factorial is: %d.\n", val, fact);
}//main
