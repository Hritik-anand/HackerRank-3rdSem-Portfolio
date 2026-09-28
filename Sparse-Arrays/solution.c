#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* matchingStrings(int stringList_count, char** stringList,
                     int queries_count, char** queries,
                     int* result_count)
{
    int *result = malloc(queries_count * sizeof(int));

    for (int i = 0; i < queries_count; i++)
    {
        result[i] = 0;

        for (int j = 0; j < stringList_count; j++)
        {
            if (strcmp(queries[i], stringList[j]) == 0)
            {
                result[i]++;
            }
        }
    }

    *result_count = queries_count;

    return result;
}
