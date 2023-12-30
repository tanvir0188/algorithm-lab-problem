#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string.h>

using namespace std;

vector<int> detectPrime(int n)
{
    vector<int> primes;
    int status[n + 1] = {0};
    status[1] = 1;
    status[2] = 0;

    for (int i = 4; i <= n; i += 2)
    {
        status[i] = 1;
    }

    for (int i = 3; i <= sqrt(n); i += 2)
    {
        if (status[i] == 0)
        {
            for (int j = i * i; j <= n; j += 2 * i)
            {
                status[j] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (status[i] == 0)
        {
            primes.push_back(i);
        }
    }
    return primes;
}

void printArray(vector<int> n)
{
    for (int i = 0; i < n.size(); i++)
    {
        cout << n[i] << endl;
    }
}

int main()
{
    int n;

    cout << "Enter the number: ";
    cin >> n;

    vector<int> result = detectPrime(n);
    printArray(result);
}