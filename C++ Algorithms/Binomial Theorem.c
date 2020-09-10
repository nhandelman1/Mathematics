#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*********************************************Function Prototypes************************************************************/

int comb( int obj, int box );
int factorial( int n );
int power( int val, int power);

int main()
{
    printf("This program expands an expression of the form (x+y)^n and calculates a value for that expression.\n\n");

    int x, y, n;

    printf("Enter a value for x: ");
    scanf("%d", &x );
    printf("\nEnter a value for y: ");
    scanf("%d", &y);
    printf("\n");

    do
    {
        printf("Enter a value for n: ");
        scanf("%d", &n);

        if( n < 0 )
            printf("n must be nonnegative.\n\n");
    }while( n < 0 );

    int i, val;
    char exp[100];
    char a[5], b[5], c[5];

    for( i = 0; i <= n; i++)
    {
        val = comb( n, i );
        itoa( n-i, a, 10 );// x power
        itoa( i, b, 10 );// y power
        itoa( val, c, 10 ); //binomial coefficient

        //binomial coefficient
        if( val != 1)
            strcat( exp, c );

        //x term
        if( n-i != 0 )
        {
            strcat( exp, "x" );

            //no need for exponenet of "1"
            if( n-i != 1 )
            {
                strcat( exp, "^");
                strcat( exp, a );
            }//if
        }//if

        //multiplication sign for two terms
        if( n-i != 0 && i != 0 )
            strcat( exp, "*");

        //y term
        if( i != 0 )
        {
            strcat( exp, "y");

            //no need for exponent of "1"
            if( i != 1)
            {
                strcat( exp, "^");
                strcat( exp, b );
            }//if
        }//if

        //addition for next term
        if( i != n)
            strcat( exp, " + ");
    }//for

    int prod;
    prod = power( x + y, n );

    printf("\nBinomial Expansion: %s\n", exp );
    printf("The value of (%d+%d)^%d = %d. \n", x, y, n, prod );
}//main

int comb( int obj, int box )
{
    return (factorial( obj ) / ( factorial( box ) * factorial( obj - box )));

}//combination

int factorial( int n )
{
	int x;
	int fact = 1;

	for( x = n; x > 0; x-- )
		fact *= x;

	return fact;

}//factorial

int power(int val, int power)
{
    int i, product = 1;
    for( i = 0; i < power; i++)
        product *= val;

    return product;
}//power
