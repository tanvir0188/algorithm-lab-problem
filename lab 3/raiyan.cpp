#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int id1, id2, id3;
        char name1[100], name2[100], name3[100];
        char section1, section2, section3;
        int marks1, marks2, marks3;
        cin >> id1 >> name1 >> section1 >> marks1;
        cin >> id2 >> name2 >> section2 >> marks2;
        cin >> id3 >> name3 >> section3 >> marks3;
        if (marks1 > marks2)
        {
            if (marks1 > marks3)
            {

                cout << id1 << " " << name1 << " " << section1 << " " << marks1 << endl;
            }
            else if (marks3 > marks1)
            {

                cout << id3 << " " << name3 << " " << section3 << " " << marks3 << endl;
            }
            else if (marks3 == marks1)
            {

                if (id1 < id3)
                {

                    cout << id1 << " " << name1 << " " << section1 << " " << marks1 << endl;
                }
                else
                {

                    cout << id3 << " " << name3 << " " << section3 << " " << marks3 << endl;
                }
            }
        }
        else if (marks2 > marks3)
        {

            cout << id2 << " " << name2 << " " << section2 << " " << marks2 << endl;
        }
        else if (marks3 > marks2)
        {

            cout << id3 << " " << name3 << " " << section3 << " " << marks3 << endl;
        }
        else
        {

            if (id2 < id3)
            {

                cout << id2 << " " << name2 << " " << section2 << " " << marks2 << endl;
            }
            else
            {

                cout << id3 << " " << name3 << " " << section3 << " " << marks3 << endl;
            }
        }
    }

    return 0;
}