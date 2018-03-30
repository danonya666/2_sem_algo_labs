#include <iostream>
#include <fstream>
using namespace std;

typedef struct Node {
    Node * r;
    Node * l;
}Node;

int Node_Height(const Node* p, const Node* pn){
    int l = 0, r = 0, h = 0;
    //cout << p->value << " " << p << " " << p->l << " " << p->r << endl;
    if(p->l != pn){
            //cout << "l";
        l = Node_Height(p->l, pn);
    }

    if(p->r != pn)
        r = Node_Height(p->r, pn);

        h = ((l > r) ? l : r) + 1;

    return h;
}

int main()
{

    ifstream fin;
    ofstream fout;
    fin.open("height.in");
    fout.open("height.out");
    int h = 1;
    fin >> h;
    if(h == 0)
    {
        fout << 0;
        return 0;
    }
    int value;
    Node * node;
    node = new Node[h];
    int a, b;
    const Node* pn = &node[0];
    for(int i = 0; i < h; i++)
    {
        fin >> value >> a >> b;
        (a != 0)? a--:1;
        (b != 0)? b--:1;
        //cout << a << " " << b << endl;
        node[i].l = &node[0] + a;
        node[i].r = &node[0] + b;
        //cout << node[i].l << " " << node[i].r << endl;
        //cout << node;
    }
    fout << Node_Height(node, pn) << endl;
    return 0;
}
