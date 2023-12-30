#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int countInversion(vector<int> &a)
{
    int n = a.size();
    int inversion = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                inversion++;
            }
        }
    }
    return inversion;
}

void createArray(int size, vector<int> &a)
{

    int elem;
    cout << "enter the size: ";
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

    int result = countInversion(arr);

    cout << "result = " << result;
}