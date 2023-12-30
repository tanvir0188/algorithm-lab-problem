#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item
{
    int profit;
    int weight;
    double ratio;

    Item(int profit, int weight)
    {
        this->profit = profit;
        this->weight = weight;
        this->ratio = (double)profit / (double)weight;
    }
};

bool compareItems(const Item &a, const Item &b)
{
    return a.ratio > b.ratio;
}

int knapSack(vector<Item> &a)
{
    sort(a.begin(), a.end(), compareItems);
    int result = 0;
    int sack = 50;

    for (int i = 0; i < a.size(); i++)
    {
        if (sack >= a[i].weight)
        {
            result += a[i].profit;
            sack -= a[i].weight;
        }
        else
        {
            result += a[i].profit * ((double)sack / (double)a[i].weight);
        }
    }
    return result;
}

int main()
{
    vector<Item> items;
    items.push_back(Item(60, 10));
    items.push_back(Item(100, 20));
    items.push_back(Item(120, 30));

    cout << knapSack(items) << endl;
    return 0;
}