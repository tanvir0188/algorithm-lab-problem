#include <iostream>
#include <vector>
using namespace std;

int lcs(const string &text1, const string &text2, int m, int n, vector<vector<int>> &dp)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }

    if (dp[m][n] != 0)
    {
        return dp[m][n];
    }

    int result;
    if (text1[m - 1] == text2[n - 1])
    {
        result = 1 + lcs(text1, text2, m - 1, n - 1, dp);
    }
    else
    {
        result = max(lcs(text1, text2, m, n - 1, dp), lcs(text1, text2, m - 1, n, dp));
    }

    dp[m][n] = result;
    return result;
}

void printLcs(const string &text1, const string &text2, vector<vector<int>> &dp)
{
    int m = text1.size();
    int n = text2.size();
    string lcsString;

    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (text1[i - 1] == text2[j - 1])
        {
            lcsString = text1[i - 1] + lcsString;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    cout << "LCS: " << lcsString << endl;
}

int main()
{
    string a = "ABCDGH";
    string b = "AEDFHR";
    int m = a.size();
    int n = b.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int result = lcs(a, b, m, n, dp);
    cout << "Lcs Length: " << result << endl;
    printLcs(a, b, dp);
}