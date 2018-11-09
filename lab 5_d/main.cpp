#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
struct map {
    string key;
    string value;
    map *next = NULL;
    map *prev = NULL;
};
int myhash(string s)
{
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        ans *= 53;
        ans += s[i];
        ans %= 1000003;
    }
    return ans;
}
int main()
{
    ifstream fin("linkedmap.in");
    ofstream fout("linkedmap.out");
    string s, s1, s2;
    vector <vector<map>> a(1000003);// , vector<map>(100))
    //vector <int> b(1000003, 0);
    int t;
    bool flag;
    map *prev = NULL;
    while (fin >> s)
    {
        if (s[0] == 'p'&&s.size() == 3)
        {
            fin >> s1 >> s2;
            t = myhash(s1);
            flag = false;
            for (int i = 0; i < a[t].size(); i++)
            {
                if (a[t][i].key == s1)
                {
                    flag = true;
                    a[t][i].value = s2;
                }
            }
            if (flag == false)
            {
                if (a[t].size() == 0)
                    a[t].reserve(100);
                map x;
                x.key = s1;
                x.value = s2;
                x.next = NULL;
                x.prev = prev;
                a[t].push_back(x);
                if(prev!=NULL)
                prev->next= &a[t][a[t].size() - 1];
                prev = &a[t][a[t].size() - 1];

            }
        }
        else if (s[0] == 'd')
        {
            fin >> s1;
            t = myhash(s1);
            for (int i = 0; i < a[t].size(); i++)
            {
                if (a[t][i].key == s1)
                {
                    if (a[t][i].next == NULL)
                        prev = a[t][i].prev;
                    else
                        a[t][i].next->prev = a[t][i].prev;
                    if (a[t][i].prev != NULL)
                        a[t][i].prev->next = a[t][i].next;
                    a[t][i].value ="";
                    a[t][i].next = NULL;
                    a[t][i].prev = NULL;
                    a[t][i].key ="";
                    break;
                }
            }

        }
        else if (s[0] == 'g')
        {
            fin >> s1;
            t = myhash(s1);
            flag = false;
            for (int i = 0; i < a[t].size(); i++)
            {
                if (s1 == a[t][i].key)
                {
                    fout << a[t][i].value << endl;
                    flag = true;
                }
            }
            if (flag == false) fout << "none\n";
        }
        else if (s[0] == 'p'&&s.size() == 4)
        {
            fin >> s1;
            t = myhash(s1);
            flag = false;
            for (int i = 0; i < a[t].size(); i++)
            {
                if (s1 == a[t][i].key)
                {
                    if (a[t][i].prev != NULL) {
                        fout << a[t][i].prev->value << endl;
                        flag = true;
                    }
                }
            }
            if (flag == false) fout << "none\n";
        }
        else if (s[0] == 'n')
        {
            fin >> s1;
            t = myhash(s1);
            flag = false;
            for (int i = 0; i < a[t].size(); i++)
            {
                if (s1 == a[t][i].key)
                {
                    if (a[t][i].next != NULL) {
                        fout << a[t][i].next->value << endl;
                        flag = true;
                    }
                }
            }
            if (flag == false) fout << "none\n";
        }
    }
    return 0;
}
