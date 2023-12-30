#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    // Create a min-heap priority queue of integers.
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Insert elements into the min-heap.
    minHeap.push(3);
    minHeap.push(1);
    minHeap.push(4);
    minHeap.push(1);
    minHeap.push(5);

    // Get the minimum element from the min-heap.
    int minElement = minHeap.top();
    cout << "Minimum element: " << minElement << endl;

    // Remove the minimum element.
    minHeap.pop();

    // Get the new minimum element.
    minElement = minHeap.top();
    cout << "Minimum element after removal: " << minElement << endl;

    return 0;
}
