#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minNumCoin(vector<int> &coins, int i, int k)
{
    if (k == 0)
    {
        return 0;
    }
    if (k < 0 || i == 0)
    {
        return INT_MAX;
    }

    int r1;
    if (k >= coins[i - 1])
    {
        r1 = minNumCoin(coins, i, k - coins[i - 1]) + 1;
    }
    else
    {
        r1 = INT_MAX;
    }
    int r2 = minNumCoin(coins, i - 1, k);
    return min(r1, r2);
}

void input(vector<int> &coins, int target)
{
    int n;
    int coin;
    cout << "enter the number of coins: ";
    cin >> n;
    cout << "enter the coins: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> coin;
        coins.push_back(coin);
    }
}

int main()
{
    vector<int> coins;
    int result;

    input(coins, 11);
    result = minNumCoin(coins, coins.size(), 11);
    if (result == INT_MAX)
    {
        cout << "not possible";
    }
    else
        cout << "result: " << result;
}