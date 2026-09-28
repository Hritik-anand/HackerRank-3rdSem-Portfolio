#include <stdio.h>
#include <stdlib.h>

int* dynamicArray(int n, int q, int queries_columns, int** queries, int* result_count)
{
    int **seq = malloc(n * sizeof(int *));
    int *size = calloc(n, sizeof(int));
    int *answers = malloc(q * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        seq[i] = NULL;
    }

    int lastAnswer = 0;
    int answerCount = 0;

    for (int i = 0; i < q; i++)
    {
        int type = queries[i][0];
        int x = queries[i][1];
        int y = queries[i][2];

        int index = (x ^ lastAnswer) % n;

        if (type == 1)
        {
            seq[index] = realloc(
                seq[index],
                (size[index] + 1) * sizeof(int)
            );

            seq[index][size[index]] = y;
            size[index]++;
        }
        else if (type == 2)
        {
            int position = y % size[index];

            lastAnswer = seq[index][position];

            answers[answerCount] = lastAnswer;
            answerCount++;
        }
    }

    *result_count = answerCount;

    for (int i = 0; i < n; i++)
    {
        free(seq[i]);
    }

    free(seq);
    free(size);

    return answers;
}
