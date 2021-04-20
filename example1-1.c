#include <stdio.h>
#include <omp.h>

void simple(int n, float *a, float *b)
{
    int i;
    printf("%d\n", i);

#pragma omp parallel for
    for (i = 1; i < n; i++)
    {
        b[i] = (a[i] + a[i - 1]) / 2.0;
        printf("Thread# %d: b[%d] = %f\n", omp_get_thread_num(), i, b[i]);
    } /* i is private by default */
}

int main()
{
    float a[5] = {1.9, 1.0, 10.0, 1.7, 9.0};
    float b[5];
    simple(5, a, b);
    return 0;
}