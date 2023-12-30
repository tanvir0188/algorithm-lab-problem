#include <iostream>
using namespace std;

int euclideGCDRecursive(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return euclideGCDRecursive(b, a % b);
    }
}

int main()
{
    int result;
    result = euclideGCDRecursive(546, 63);
    cout << "GCD: " << result;
}