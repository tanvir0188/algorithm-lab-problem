#include <iostream>
#include <vector>
using namespace std;

vector<int> prefix(string pattern)
{
    int m = pattern.size();
    vector<int> pie(m + 1, 0);
    int k = 0;

    for (int q = 2; q <= m; q++)
    {
        while (k > 0 && pattern[k] != pattern[q - 1])
        {
            k = pie[k];
        }
        if (pattern[k] == pattern[q - 1])
        {
            k = k + 1;
        }
        pie[q] = k;
    }
    return pie;
}

int KMP_matcher(string text, string pattern)
{
    int n = text.size();
    int m = pattern.size();
    vector<int> preRes = prefix(pattern);
    int q = 0;

    for (int i = 0; i < n; i++)
    {
        while (q > 0 && pattern[q] != text[i])
        {
            q = preRes[q];
        }
        if (pattern[q] == text[i])
        {
            q = q + 1;
        }
        if (q == m)
        {
            return i - m + 1;
        }
    }
    return -1;
}

int main()
{
    string text, pattern;

    cout << "Text: ";
    getline(cin, text);
    cout << "Pattern: ";
    cin >> pattern;

    int result = KMP_matcher(text, pattern);

    cout << "Result: " << result << endl;

    return 0;
}
