#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string.h>

using namespace std;

vector<int> detectPrimeFactor(int n)
{
    vector<int> primes;

    while (n % 2 == 0)
    {
        primes.push_back(2);
        n /= 2;
    }

    for (int i = 3; i <= sqrt(n); i += 2)
    {
        while (n % i == 0)
        {
            primes.push_back(i);
            n /= i;
        }
    }

    if (n > 2)
    {
        primes.push_back(n);
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

    vector<int> result = detectPrimeFactor(n);
    printArray(result);
}