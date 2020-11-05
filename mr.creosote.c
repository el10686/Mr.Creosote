#include <stdio.h>
#include <stdlib.h>

int main()
{
    long int N, b, c, i, j;
    int a;

    scanf("%li %i %li %li", &N, &a, &b, &c);

    int *x;

    x = malloc(sizeof(int) * N);

    for(i = 0; i < N; i++)
    {
        scanf("%i", &x[i]);
    }

    long long *partial_sums, *max, temp;

    partial_sums = malloc(sizeof(long long int) * N);
    max = malloc(sizeof(long long int) * N);

    partial_sums[0] = x[0];

    max[0] = a * x[0] * x[0] + b * x[0] + c;

    for(i = 1; i < N; i++)
    {
        partial_sums[i] = partial_sums[i - 1] + x[i];

        max[i] = a * partial_sums[i] * partial_sums[i] + b * partial_sums[i] + c;

        for(j = 1; j <= i; j++)
        {
            temp = max[j - 1] + a * (partial_sums[i] - partial_sums[j - 1]) * (partial_sums[i] - partial_sums[j - 1]) + b * (partial_sums[i] - partial_sums[j - 1]) + c;

            if(temp > max[i])
            {
                max[i] = temp;
            }
        }
    }

    printf("%lli\n", max[N-1]);

    return 0;
}