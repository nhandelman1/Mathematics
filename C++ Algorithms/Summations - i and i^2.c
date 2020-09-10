#include <stdio.h>

int main()
{
    printf("This program calculates the summation (1 to n) for either i or i^2.\n\n");

    int i, n, val, ans;
    char *sumTo;
    do
    {
        printf("Enter 1 for i.\n");
        printf("Enter 2 for i^2.\n");
        scanf("%d", &i);
        printf("\n");
    }while(i < 1 || i > 2);

    do
    {
        printf("Enter a positive value for n.\n");
        scanf("%d", &n);
        printf("\n");
    }while( n < 1);

    val = n * ( n+1 );
    if( i == 1 )
    {
        ans = val / 2;
        sumTo = "i";
    }//if
    else
    {
        val = val * ( 2 * n + 1 );
        ans = val / 6;
        sumTo = "i^2";
    }//else

    printf("The sum of 1 to %d for %s is %d.\n", n, sumTo, ans);

}//end main
