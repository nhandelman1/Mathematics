/******************************************************************************
Random Matrix Generator

Generates a 16x16 matrix consisting of ascii 7-bit typable characters
Saves the matrix to a file.

*******************************************************************************/

#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

int main ()
{
    char file_name[20] = "";
    char matrix_array[16][16] = {};
    int temp;

    cout << "Enter a name for the file.\n";
    cin >> file_name;

    for(int r = 0; r < 16; r++)
        for(int c = 0; c < 16; c++)
        {
            temp = 0;
            while( temp < 33 )
                temp = rand() % 127;

            matrix_array[r][c] = temp;
        }//for c

    ofstream open_file(file_name,ios::out | ios::app);
    for(int r = 0; r < 16; r++)
    {
        for(int c = 0; c < 16; c++)
            open_file << matrix_array[r][c];

        open_file << endl;
    }//for r

    open_file.close();

}//main
