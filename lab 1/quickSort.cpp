#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int partition(vector<int> &a, int p, int r)
{
    int x = a[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (a[j] <= x)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}

void quickSort(vector<int> &a, int p, int r)
{

    if (p < r)
    {
        int q = partition(a, p, r);
        quickSort(a, p, q - 1);
        quickSort(a, q + 1, r);
    }
}

int main()
{
    vector<int> A = {2, 8, 7, 1, 2, 3, 5, 6, 4};

    int end = A.size() - 1;
    quickSort(A, 0, end);
    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i] << endl;
    }
}