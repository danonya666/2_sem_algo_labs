#include <fstream>
#include <vector>
#include <queue>

using namespace std;

struct top
{
	vector<int> near;
	int distance = 0;
	int color = 0;
};

void BFS(vector<top> &t, int start)
{
	t[start].color = 1;
	queue<int> q;
	q.push(start);
	while (!q.empty())
	{
		int U = q.front();
		q.pop();

		for(int i = 0; i < t[U].near.size(); i++)
        {
            if (t[t[U].near[i]].color == 0)
			{
				t[t[U].near[i]].color = 1;
				t[t[U].near[i]].distance = t[U].distance + 1;

				q.push(t[U].near[i]);
			}
        }

		t[U].color = 2;
	}
}

int main()
{
	ifstream fin("pathbge1.in");
	ofstream fout("pathbge1.out");
	int n, m, num1, num2;

	fin >> n >> m;

	vector<top> t(n);

	for(int i = 0; i < m; i++)
	{
		fin >> num1 >> num2;

		t[num1 - 1].near.push_back(num2 - 1);
		t[num2 - 1].near.push_back(num1 - 1);
	}

	BFS(t, 0);

	for(int i = 0; i < n; i++)
    {
        fout << t[i].distance << " ";
    }

	return 0;
}
