#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int platformNumber(float a[], float b[], int n)
{
    vector<pair<float, float>> arr(n);

    for (int i = 0; i < n; i++)
    {
        arr[i] = {a[i], b[i]};
    }

    sort(arr.begin(), arr.end());

    priority_queue<int, vector<int>, greater<int>> p;
    int count = 1;
    p.push(arr[0].second);

    for (int i = 1; i < n; i++)
    {
        if (p.top() > arr[i].first)
        {
            count++;
        }
        else
        {
            p.pop();
        }
        p.push(arr[i].second);
    }

    return count;
}

int main()
{
    float arrival[] = {2.00, 2.10, 3.00, 3.20, 3.50, 5.00};
    float depart[] = {2.30, 3.40, 3.20, 4.30, 4.00, 5.20};

    int n = sizeof(arrival) / sizeof(arrival[0]);

    int result = platformNumber(arrival, depart, n);
    cout << "result = " << result;
}