#include <stdio.h>
#include <stdlib.h>
#include <fstream>

using namespace std;
int main()
{
    int n;
    int icounter = 0,
        ocounter = 0;
    char sign;
    int tmp;

    ifstream fin;
    ofstream fout;

    fin.open("queue.in");
    fout.open("queue.out");

    fin >> n;

    int *arr;
    arr = new int[n];
    for(int i = 0; i < n; i++)
    {
        fin >> sign;
        if(sign == '+')
        {
            fin >> arr[icounter++];
        }
        else
        {
            fout << arr[ocounter++] << endl;
        }
    }

    return 0;

}
