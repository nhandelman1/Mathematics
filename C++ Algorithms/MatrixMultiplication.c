
/*****************************************Libraries***************************************/
#include <stdio.h>


/*******************************************Main******************************************/
int main()
{
	int firstRow, firstColSecRow, secCol;

        printf("This program multiplies two matrices together.\n");
        printf("The number of columns in the first matrix must equal the number of rows in the second matrix.\n");
        printf("The resulting matrix will be of size numberOfRowsMatrixOne x numberOfColumnsMatrixTwo.\n");
    do
    {
        printf("Enter the number of rows in Matrix 1: ");
        scanf("%d", &firstRow);
        printf("\nEnter the number of columns in Matrix 1 (same as number of rows in Matrix 2): ");
        scanf("%d", &firstColSecRow);
        printf("\nEnter the number columns in Matrix 2: ");
        scanf("%d", &secCol);
        printf("\n");

        if( firstRow < 1 || firstColSecRow < 1 || secCol < 1 )
            printf("Row and column values must be positive.");
        printf("\n");

    }while( firstRow < 1 || firstColSecRow < 1 || secCol < 1 );

	float m1[firstRow][firstColSecRow];
	float m2[firstColSecRow][secCol];
	float m3[firstRow][secCol];

	int r, c, x, mult, sum;

	printf("Enter the values of Matrix 1 in row-major order.\n");
	for( r = 0; r < firstRow; r++ )
		for( c = 0; c < firstColSecRow; c++ )
		{
			printf("Enter the value at position ( %d, %d ): ", r+1, c+1);
			scanf( "%f", &m1[r][c] );
			printf("\n");

		}//for

	printf("Enter the values of Matrix 2 in row-major order.\n");
	for( r = 0; r < firstColSecRow; r++ )
		for( c = 0; c < secCol; c++ )
		{
			printf("Enter the value at position ( %d, %d ): ", r+1, c+1);
			scanf( "%f", &m2[r][c] );
			printf("\n");

		}//for

    //multiply matrices
	for( x = 0; x < firstRow ; x++ )
	{

		for( r = 0; r < secCol; r++ )
		{
			sum = 0;

			for( c = 0; c < firstColSecRow; c++ )
				sum += ( m1[x][c] * m2[c][r] );

			m3[x][r] = sum;
		}//for

	}//for

	printf("Here is the multiplication of the two matrices: \n");
	for( r = 0; r < firstRow; r++ )
	{
		for( c = 0; c < secCol; c++ )
			printf("%10.6f   ", m3[r][c]);

		printf("\n");

	}//for

}//end main









