#include <stdio.h>
#include <stdlib.h>

int* compareTriplets(int a_count, int* a, int b_count, int* b, int* result_count)
{
    int *result = malloc(2 * sizeof(int));

    result[0] = 0;  // Alice
    result[1] = 0;  // Bob

    for (int i = 0; i < 3; i++)
    {
        if (a[i] > b[i])
        {
            result[0]++;
        }
        else if (a[i] < b[i])
        {
            result[1]++;
        }
    }

    *result_count = 2;

    return result;
}
