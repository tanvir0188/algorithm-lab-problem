#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int combine(vector<int> &a, int p, int q, int r)
{
}

int countInversion(vector<int> &a, int p, int r)
{
    int q;
    if (p < r)
    {
        q = (p + r) / 2;
        int L = countInversion(a, p, q);
        int R = countInversion(a, q + 1, r);
    }
    return 0;
}

void createArray(int size, vector<int> &a)
{

    int elem;
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        cout << "element no " << i << ":";
        cin >> elem;
        a.push_back(elem);
    }
}

int main()
{
    vector<int> arr;
    int size;

    createArray(5, arr);
    int start = 0;
    int end = size;

    int result = countInversion(arr, start, end);

    cout << "result = " << result;
}