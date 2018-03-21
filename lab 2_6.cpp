#include <fstream>
#include <vector>
#include <string>

using namespace std;

void count_sort(vector<string> &array, int cicle)
{
    int scope;

	scope = 'z' - 'A' + 1;

	vector<int> copy(scope);

	vector<string> tmp(array.size());

	for(int i = 0; i < scope; i++)
    {
        copy[i] = 0;
    }

	for(int i = 0; i < array.size(); i++)
    {
        copy[array[i][cicle] - 'A']++;
    }
	for(int i = 1; i < scope; i++)
    {
        copy[i] += copy[i - 1];
    }
	for(int i = (array.size() - 1); i >= 0; i--)
    {
        tmp[--copy[array[i][cicle] - 'A']] = array[i];
    }
	array = tmp;
}

void radix_sort(vector<string> &array, int m, int k)
{
	for(int i = (m - 1); i >= (m - k); i--)
    {
        count_sort(array, i);
    }
}

int main()
{
	ifstream input("radixsort.in");
	ofstream output("radixsort.out");

	int n, m, k;

	input >> n >> m >> k;

	vector<string> array(n);

	for(int i = 0; i < n; i++)
    {
        input >> array[i];
    }

	radix_sort(array, m, k);

	for(int i = 0; i < n; i++)
    {
        output << array[i] << endl;
    }

	return 0;
}

