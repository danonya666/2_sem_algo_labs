#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fin, *fout;
    fin = fopen("antiqs.in", "r");

    fout = fopen("antiqs.out", "w");
    int i;
    int n;

    fscanf(fin, "%d", &n);
    //printf("%d ", n);

    int *pa;
    pa = (int*) malloc(n * sizeof(int));



    for(i = 0; i < n; i++)
    {
        pa[i] = i;
        //printf("%d\n", pa[i]);
    }

    int tmp;

    for(i = (n - 1); i >= 0; i--)
    {
        tmp = pa[i];
        pa[i] = pa[i / 2];
        pa[i / 2] = tmp;
    }

    for(i = 0; i < n; i++)
    {
        fprintf(fout, "%d ", pa[i]);
    }


    return 0;
}
