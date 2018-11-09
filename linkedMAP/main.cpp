#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

typedef struct Node
{
    string key;
    string value;
}Node;

int Hash(string x)
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

int main()
{
    vector<vector<Node> > n;
    n.resize(1000000);
    n.reserve(1000000);
    Node rez;
    ifstream fin("linkedmap.in");
    ofstream fout("linkedmap.out");
    string x, y;
    int h;
    string Command;
    while (fin >> Command)
    {
        fin >> x;
        //cout << x;
        h = Hash(x);
       // cout << h<< endl;
        if (Command == "put")
        {
            fin >> y;
            //cout << 1;
            n[h].push_back({x, y});
            //cout << n[h][n[h].size() - 1].key << n[h][n[h].size() - 1].value;
            //n[h].flip();
            //cout << 4;
        }
        else if (Command == "delete")
        {
            //cout << 2;
            n[h].push_back({x, "none"});
        }
        else if (Command == "get")
        {
            //cout << 3;
            bool b = 0;
            for(int i = n[h].size() - 1; i > -1; i--)
            {
                if(n[h][i].key == x)
                    {
                         //cout << n[h][n[h].size() - 1].key << n[h][n[h].size() - 1].value;
                        fout << n[h][i].value << endl;
                        b = true;
                        break;
                    }
            }
            if (!b) fout << "none" << endl;
        }
        else if(Command == "prev")
        {
            //cout << 3;
            bool b = 0;
            for(int i = n[h].size() - 1; i > -1; i--)
            {
                if(n[h][i].key == x)
                    {
                         //cout << n[h][n[h].size() - 1].key << n[h][n[h].size() - 1].value;
                        {
                            i--;
                            while(n[h][i].value == "none" || n[h][i].key != x && i > -1)
                                i--;
                            if(n[h][i].key == x)
                                fout << n[h][i].value << endl;
                            else
                                fout << "none" << endl;
                        }
                        b = true;
                        break;
                    }
            }
            if (!b) fout << "none" << endl;
        }
        else if(Command == "next")
        {
            //cout << 3;
            bool b = 0;
            for(int i = n[h].size() - 1; i > -1; i--)
            {
                if(n[h][i].key == x)
                    {
                         //cout << n[h][n[h].size() - 1].key << n[h][n[h].size() - 1].value;
                        {
                            i++;
                            while(n[h][i].value == "none" || n[h][i].key != x && i < n[h].size())
                                i++;
                            if(n[h][i].key == x)
                                fout << n[h][i].value << endl;
                            else
                                fout << "none" << endl;
                        }
                        b = true;
                        break;
                    }
            }
            if (!b) fout << "none" << endl;
        }
    }
    return 0;
}
