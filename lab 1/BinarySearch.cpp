#include <iostream>
using namespace std;

int binarySearchAscending(int array[], int x, int low, int high)
{
    if (high >= low)
    {
        int mid = low + (high - low) / 2;

        // If found at mid, then return it
        if (array[mid] == x)
            return mid;

        // Search the left half
        if (array[mid] > x)
            return binarySearchAscending(array, x, low, mid - 1);

        // Search the right half
        return binarySearchAscending(array, x, mid + 1, high);
    }

    return -1;
}
int binarySearchDescending(int array[], int x, int low, int high)
{
    if (high >= low)
    {
        int mid = low + (high - low) / 2;

        // If found at mid, then return it
        if (array[mid] == x)
            return mid;

        // Search the left half
        if (array[mid] < x)
            return binarySearchDescending(array, x, low, mid - 1);

        // Search the right half

        return binarySearchDescending(array, x, mid + 1, high);
    }

    return -1;
}

int main(void)
{
    int array[] = {3, 4, 5, 6, 7, 8, 9};
    int array1[] = {9, 8, 7, 6, 5, 4, 3};
    int x = 4;
    int n = sizeof(array) / sizeof(array[0]);
    int m = sizeof(array1) / sizeof(array1[0]);
    int result = binarySearchAscending(array, x, 0, n - 1);
    int result1 = binarySearchDescending(array1, x, 0, n - 1);
    if (result == -1)
    {
        cout << "Not found " << endl;
    }
    else
    {
        cout << "element is found at " << result << endl;
    }
    if (result1 == -1)
    {
        cout << "Not found " << endl;
    }
    else
    {
        cout << "element is found at " << result1 << endl;
    }
}