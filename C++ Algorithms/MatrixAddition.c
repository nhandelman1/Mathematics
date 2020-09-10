
/*****************************************Libraries***************************************/
#include <stdio.h>


/*******************************************Main******************************************/
int main()
{
	int numRow, numCol;

    do
    {
        printf("This program adds two matrices together. They must be the same size.\n");

        printf("Enter the number of rows: ");
        scanf("%d", &numRow);
        printf("\nEnter the number of columns: ");
        scanf("%d", &numCol);
        printf("\n");

        if( numRow < 1 || numCol < 1)
            printf("The value for rows and columns must be positive.\n");
        if( numRow != numCol )
            printf("The number of rows must equal the number of columns.\n");
        printf("\n");
    }while( numRow < 1 || numCol < 1 || numRow != numCol );

	float m1[numRow][numCol];
	float m2[numRow][numCol];
	float m3[numRow][numCol];

	int r, c;

	printf("Enter the values of Matrix 1 in row-major order.\n");
	for( r = 0; r < numRow; r++ )
		for( c = 0; c < numCol; c++ )
		{
			printf("Enter the value at position ( %d, %d ): ", r+1, c+1);
			scanf( "%f", &m1[r][c] );
			printf("\n");

		}//for

	printf("Enter the values of Matrix 2 in row-major order.\n");
	for( r = 0; r < numRow; r++ )
		for( c = 0; c < numCol; c++ )
		{
			printf("Enter the value at position ( %d, %d ): ", r+1, c+1);
			scanf( "%f", &m2[r][c] );
			printf("\n");

		}//for

    //add matrices
	for( r = 0; r < numRow; r++ )
		for( c = 0; c < numCol; c++ )
			m3[r][c] = m1[r][c] + m2[r][c];

	printf("Here is the sum of the two matrices: \n");
	for( r = 0; r < numRow; r++ )
	{
		for( c = 0; c < numCol; c++ )
			printf("%10.6f   ", m3[r][c]);

		printf("\n");

	}//for

}//end main

