#include <iostream>
#include <fstream>
using namespace std;

long long int merge(int arr[], int l, int m, int r)
{
    long long int counter = 0;
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            //counter++;
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
            counter += m - i;
            cout << "counter += " << m - i << endl;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    return counter;
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
long long int mergeSort(int arr[], int l, int r)
{
    long long counter = 0;
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = (l + r) / 2;

        // Sort first and second halves
        counter = mergeSort(arr, l, m);
        counter += mergeSort(arr, m+1, r);

        counter += merge(arr, l, m, r);

    }
    return counter;
}
int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");
    int n;
    fin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        fin >> arr[i];
    }
    cout << mergeSort(arr, 0, n - 1) << endl;

    /*for(int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }*/

    return 0;
}
