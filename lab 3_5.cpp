#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;

    fin.open("isheap.in");
    fout.open("isheap.out");

    int n;
    bool result = 1;
    fin >> n;
    //printf("1");
    int *a;
    a = new int[n + 1];

    for(int i = 1; i <= n; i++)
        fin >> a[i];


    for(int i = 1; i <= n; i++)
        if(2 * i <= n)
            for(int j = 2 * i; j <= n; j++)
                if (a[i] > a[j])
                    result = 0;

   fout << (result? "YES": "NO");



    return 0;
}
