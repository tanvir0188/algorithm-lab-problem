#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Students
{
    int id;
    char name[100];
    char section;
    int totalMark;
};

void input(Students &student)
{
    cout << "id: ";
    cin >> student.id;
    cout << "name: ";
    cin >> student.name;
    cout << "section: ";
    cin >> student.section;
    cout << "total mark: ";
    cin >> student.totalMark;
}

void printHighest(Students &s1, Students &s2, Students &s3)
{
    if (s1.totalMark > s2.totalMark && s1.totalMark > s3.totalMark)
    {
        cout << s1.id << " " << s1.name << " " << s1.section << " " << s1.totalMark;
    }

    else if (s2.totalMark > s1.totalMark && s2.totalMark > s3.totalMark)
    {
        cout << s2.id << " " << s2.name << " " << s2.section << " " << s2.totalMark;
    }

    else if (s3.totalMark > s1.totalMark && s3.totalMark > s2.totalMark)
    {
        cout << s3.id << " " << s3.name << " " << s3.section << " " << s3.totalMark;
    }

    else if (s1.totalMark == s2.totalMark == s3.totalMark)
    {
        if (s1.id < s2.id && s1.id < s3.id)
        {
            cout << s1.id << " " << s1.name << " " << s1.section << " " << s1.totalMark;
        }
        else if (s2.id < s1.id && s2.id < s3.id)
        {
            cout << s2.id << " " << s2.name << " " << s2.section << " " << s2.totalMark;
        }
        else
        {
            cout << s3.id << " " << s3.name << " " << s3.section << " " << s3.totalMark;
        }
    }

    else if (s1.totalMark == s2.totalMark)
    {
        if (s1.id < s2.id)
        {
            cout << s1.id << " " << s1.name << " " << s1.section << " " << s1.totalMark;
        }
        else
        {
            cout << s2.id << " " << s2.name << " " << s2.section << " " << s2.totalMark;
        }
    }

    else if (s1.totalMark == s3.totalMark)
    {
        if (s1.id < s3.id)
        {
            cout << s1.id << " " << s1.name << " " << s1.section << " " << s1.totalMark;
        }
        else
        {
            cout << s3.id << " " << s3.name << " " << s3.section << " " << s3.totalMark;
        }
    }

    else
    {
        if (s2.id < s3.id)
        {
            cout << s2.id << " " << s2.name << " " << s2.section << " " << s2.totalMark;
        }
        else
        {
            cout << s3.id << " " << s3.name << " " << s3.section << " " << s3.totalMark;
        }
    }
}

int main()
{
    Students s1, s2, s3;
    input(s1);
    input(s2);
    input(s3);
    cout << endl;
    printHighest(s1, s2, s3);
}