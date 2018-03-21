#include <iostream>
#include <fstream>
using namespace std;

void merge(string arr[], string arr1[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    string L[n1], R[n2];
    string L1[n1], R1[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        {
            L[i] = arr[l + i];
            L1[i] = arr1[l + i];
        }
    for (j = 0; j < n2; j++)
        {
            R[j] = arr[m + 1+ j];
            R1[j] = arr1[m + 1 + j];
        }

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            arr1[k] = L1[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            arr1[k] = R1[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        arr1[k] = L1[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        arr1[k] = R1[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(string arr[], string arr1[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, arr1, l, m);
        mergeSort(arr, arr1, m+1, r);

        merge(arr, arr1, l, m, r);
    }
}

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("race.in");
    fout.open("race.out");
    int n;
    fin >> n;
    string country[n], name[n];
    int i;
    for(i = 0; i < n; i++)
    {
        fin >> country[i] >> name[i];
    }

    /*for(i = 0; i < n; i++)
    {
        fout << "i = " << i << " country = " << country[i] << " name = " << name[i] << endl;
    }*/

    mergeSort(country, name, 0, n - 1);

   /* for(i = 0; i < n; i++)
    {
        fout << "i = " << i << " country = " << country[i] << " name = " << name[i] << endl;
    }*/
    string currC;
    for(i = 0; i < n; i++)
    {
        currC = country[i];
        fout << "=== " << currC << " ===" << endl;
        fout << name[i] << endl;

        while(country[i + 1] == currC)
        {
            fout << name[i + 1] << endl;
            i++;
        }
    }



    return 0;
}


