#include <stdio.h>
#include <stdlib.h>

int diagonalDifference(int arr_rows, int arr_columns, int** arr)
{
    int primary = 0;
    int secondary = 0;

    for (int i = 0; i < arr_rows; i++)
    {
        primary += arr[i][i];
        secondary += arr[i][arr_columns - 1 - i];
    }

    return abs(primary - secondary);
}
