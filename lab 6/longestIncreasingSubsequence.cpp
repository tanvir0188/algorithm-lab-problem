#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> &a)
{

    for (int i = 0; i < a.size(); i++)
    {
        if (i == a.size() - 1)
        {
            cout << a[i];
        }
        else
            cout << a[i] << "->";
    }
}

void lis(vector<int> &a)
{
    vector<int> b;
    int n = a.size();
    int sizeOfLis;

    for (int i = 0; i < a.size(); i++)
    {
        if (b.empty() || b[b.size() - 1] < a[i])
        {
            b.push_back(a[i]);
        }
        else
        {
            auto it = lower_bound(b.begin(), b.end(), a[i]);
            *it = a[i];
        }
    }

    sizeOfLis = b.size();
    cout << " LIS size: " << sizeOfLis << endl;
    cout << "LIS: ";
    print(b);
}

void input(vector<int> &a)
{

    int n, elm;

    cout << "Sequence size: ";
    cin >> n;
    cout << "Sequence: ";

    for (int i = 0; i < n; i++)
    {
        cin >> elm;
        a.push_back(elm);
    }
}

int main()
{
    vector<int> seq;
    input(seq);
    lis(seq);
}