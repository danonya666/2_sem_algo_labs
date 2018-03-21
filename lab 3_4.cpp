#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <ctype.h>
using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;

    fin.open("postfix.in");
    fout.open("postfix.out");

    char *str;
    str = new char[201];
    char sign, str1[100];
    int nums[100];
    int n_count = 0;
    int i = 0;

    for(i = 0; i < 2 * strlen(str); i++)
    {
        fin >> str[i];
       // printf("%c", str[i]);
        if (isdigit(str[i]))
        {
            //printf("num ");
            n_count++;
            nums[n_count] = int(str[i]) - 48;


            //printf("%d", nums[num_count]);

        }
        if (!isdigit(str[i]))
        {
            if (str[i] == '+')
            {
                nums[--n_count] += nums[n_count + 1];
                //printf("num[%d] = %d\n", n_count, nums[n_count]);
            }

            else if (str[i] == '*')
            {

                nums[--n_count] *= nums[n_count + 1];
                //printf("num[%d] = %d\n", n_count, nums[n_count]);
            }

            else if (str[i] == '-')
            {
                nums[--n_count] -= nums[n_count + 1];
                //printf("num[%d] = %d\n", n_count, nums[n_count]);
            }

        }
    }
   fout << nums[1];
    return 0;
}
