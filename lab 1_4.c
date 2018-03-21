#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fin, *fout;
    int n, i, j;
    fin = fopen("smallsort.in","r");
    fout = fopen("smallsort.out", "w");
    fscanf(fin, "%d", &n);
    int A[n], tmp;
    for(i = 0; i < n; i++)
    {
        fscanf(fin, "%d", &A[i]);
    }
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if (A[j] > A[i])
            {
                tmp = A[j];
                A[j] = A[i];
                A[i] = tmp;
            }
        }
    }
    for(i = 0; i < n; i++)
    {
        fprintf(fout, "%d ", A[i]);
    }
    return 0;
}
