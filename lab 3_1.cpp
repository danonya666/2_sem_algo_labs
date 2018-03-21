#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;

    char str[100000],
         str1[100000];
    str[0] = 'a';
    char sign;
    int counter = 0;
    int ocounter = 0;
    //int ccounter = 0;
    bool result = 1;
    bool result_bool = 0;


    fin.open("brackets.in");
    fout.open("brackets.out");
    //fin >> str;
    while(str[0] != 'k')
    {
    result = 1;
    ocounter = 0;
    //result_bool = !fin.eof();
    str[0] = 'k';
    fin >> str;
    printf("%s\n", str);

     if (str[0] != '(' && str[0] != '[')
        {
            result = 0;
            printf("f");
        }
    for(int i = 0; i < strlen(str); i++)
    {


       sign = str[i];
       //fout << str1[counter - 1];
       if((sign == '(') || (sign == '['))
            {
                str1[counter++] = sign;
                ocounter++;
                printf("+");
            }

       else if ((sign == ')' && str1[counter - 1] == '(') || ((sign == ']' && str1[counter - 1] == '[')))
       {
           counter--;
           ocounter--;
           printf("-");
           if(ocounter < 0)
           {
               printf("ocounter\n");
               result = 0;
               break;
           }
       }
       else if ((sign == ')' && str1[counter - 1] != '(') || ((sign == ']' && str1[counter - 1] != '[')))
       {
           printf("!");
           result = 0;
           break;
       }
    }
    //if(result_bool)
    if (str[0] != 'k')
        fout << (result && !ocounter? "YES": "NO") << endl;
    //str[501] = 'a';

    //fout << str << endl;
    }



    return 0;
}
