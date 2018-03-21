#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fin, *fout;
    fin = fopen("sortland.in", "r");
    fout = fopen("sortland.out", "w");
    int i, n;
    fscanf(fin, "%d", &n);
    int j, tmp, Ind[n], i_tmp;

    float M[n];

    for(i = 0; i < n; i++)
    {
        fscanf(fin, "%f", &M[i]);
        Ind[i] = i + 1;
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if (M[j] > M[i])
            {
                tmp = M[j];
                i_tmp = Ind[j];
                M[j] = M[i];
                Ind[j] = Ind[i];
                M[i] = tmp;
                Ind[i] = i_tmp;
            }
        }
    }
    int r1, r2, r3;
    r1 = Ind[0];
    r2 = Ind[n - 1];
    r3 = Ind[(n - 1) / 2];
    for(i = 0; i < n; i++)
    {
        printf("%d %f\n", Ind[i], M[i]);
    }
    fprintf(fout, "%d %d %d", r1, r3, r2);
    return 0;
}
