#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct Node
{
    string Value;
    string Value1;
    Node *Next;
};


class StringHashTable
{
    int Hash(string x);
    int Hash1(StringHashTable S, int start);
    int Hash1_find(StringHashTable S, int start, string goal);

    public:
        vector<Node> l;
        StringHashTable();
        void Insert(string x, string y);
        string Search(string x);
        void Delete(string x);
};

StringHashTable::StringHashTable()
{
    //l.reserve(1000000);
    l.resize(1000000);
    for(int i = 0; i < 1000000; i++)
    {
        l[i].Value = "none";
    }
}

int StringHashTable::Hash(string x)
{
    int seed = 199999;
   unsigned long long h = 0;
   for(int i = 0; i < x.length(); i++)
   {
      h = (h * seed) + x[i] + 1;
   }
   //cout << h << endl;
   return (h %  999623);
}

int StringHashTable::Hash1(StringHashTable S, int start)
{
    int i = start;
    int j = 1;
    while(S.l[i].Value != "none")
        {
            i += j * j;
            j++;
        }
    return i;
}

int StringHashTable::Hash1_find(StringHashTable S, int start, string goal)
{
    int i = start;
    int j = 1;
    while(S.l[i].Value != goal && i < 900000)
        {
            i += j * j;
            j++;
        }
    return i;
}
void StringHashTable::Insert(string x, string y)
{
    int h = Hash(x);
    if(l[h].Value == "none" || l[h].Value == x)
    {
        l[h].Value1 = y;
        l[h].Value = x;
    }

    else
    {
        h = Hash1(*this, h);
        l[h].Value1 = y;
        l[h].Value = x;
    }
    //cout << l[h] << endl;

}

string StringHashTable::Search(string x)
{
    //cout << 2 << endl;
    int h = Hash(x);
    //string* p = l.data() + h;
    //cout << "get " << p << l.begin()[h] << endl;
    if(l[h].Value == x)
        return (l[h].Value1);
    else
    {
        h = Hash1_find(*this, h, x);
        return(l[h].Value1);
    }
}

void StringHashTable::Delete(string x)
{
    int h = Hash(x);
    //string* p = l.data() + h;
    //cout << "delete " << p << *p << endl;
    if(l[h].Value != "none")
        l[h].Value = "none";
}

int main()
{
    ifstream fin("map.in");
    ofstream fout("map.out");
    StringHashTable S;
    string x, y;
    string Command;
    while (fin >> Command)
    {
        fin >> x;
        if (Command == "put")
        {
            fin >> y;
            S.Delete(x);
            S.Insert(x, y);
        }
        else if (Command == "delete")
        {
            S.Delete(x);
        }
        else if (Command == "get")
        {
            string res = S.Search(x);
            if(res != "")
                fout << S.Search(x) << endl;
            else
                fout << "none\n";
        }
    }
    return 0;
}
