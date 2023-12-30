#include <iostream>
#include <vector>
using namespace std;

struct Item
{
    int weight, value;
};

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

int knapsack(int i, int k, vector<Item> &items)
{
    int r1, r2;

    if (k == 0 || i == 0)
    {
        return 0;
    }
    if (items[i].weight > k)
    {
        return knapsack(i - 1, k, items);
    }
    else
    {
        r1 = knapsack(i - 1, k, items);
        r2 = knapsack(i - 1, k - items[i].weight, items) + items[i].value;

        return max(r1, r2);
    }
}

void result()
{
    int itemNumber;
    Item item;
    vector<Item> items;
    int knapSackWeight;

    cout << "Enter the number of items:" << endl;
    cin >> itemNumber;
    cout << "Enter the items (weight , value):" << endl;

    for (int i = 0; i < itemNumber; i++)
    {
        cin >> item.weight >> item.value;
        items.push_back(item);
    }

    cout << "Enter the knapsack weight:" << endl;
    cin >> knapSackWeight;

    int sol = knapsack(itemNumber - 1, knapSackWeight, items);
    cout << "Result = " << sol << endl;
}

int main()
{
    result();
    return 0;
}
