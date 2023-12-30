#include <bits/stdc++.h>
using namespace std;

int firstOccurrenceRabinKarp(string T, string s)
{
    int m = s.size();
    int n = T.size();
    int prime = 101;
    int d = 256;

    // applying the hash to the pattern you want to match
    int sHash = 0;
    for (int i = 0; i < m; i++)
    {
        sHash = (d * sHash + s[i]) % prime;
    }

    // removing the first character while sliding the window
    int offset = 1;
    for (int i = 0; i < m - 1; i++)
    {
        offset = (offset * d) % prime;
    }

    // applying the hash to the first window
    int tHash = 0;
    for (int i = 0; i < m; i++)
    {
        tHash = (d * tHash + T[i]) % prime;
    }

    int j;

    for (int i = 0; i <= n - m; i++)
    {
        if (tHash == sHash)
        {
            for (j = 0; j < m; j++)
            {
                if (T[i + j] != s[j])
                {
                    break;
                }
            }
            if (j == m)
            {
                return i;
            }
        }

        if (i < n - m)
        {
            tHash = (d * (tHash - T[i] * offset) + T[i + m]) % prime;

            if (tHash < 0)
            {
                tHash += prime;
            }
        }
    }
    return -1;
}

int main()
{
    string text, pattern;

    cout << "Text: ";
    getline(cin, text);
    cout << "pattern: ";
    cin >> pattern;

    int result = firstOccurrenceRabinKarp(text, pattern);

    cout << "Result: " << result << endl;
}