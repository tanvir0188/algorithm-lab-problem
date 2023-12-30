#include <iostream>
#include <string>
using namespace std;

int firstOccurance(string str, string ptrn)
{
    int n = str.size();
    int m = ptrn.size();
    int firstOccur = -1;
    bool flag;

    for (int i = 0; i <= n - m; i++)
    {
        flag = true;
        for (int j = 0; j < m; j++)
        {
            if (str[i + j] == ptrn[j])
            {
                continue;
            }
            else
            {
                flag = false;
                break;
            }
        }
        if (flag == true)
        {
            firstOccur = i;
            break;
        }
    }
    return firstOccur;
}

int main()
{
    string text, pattern;

    cout << "Text: ";
    getline(cin, text);
    cout << "pattern: ";
    cin >> pattern;

    int result = firstOccurance(text, pattern);

    cout << "Result: " << result << endl;
}