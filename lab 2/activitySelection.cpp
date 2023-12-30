#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class activity
{

public:
    int start;
    int end;

    activity(int start, int end) : start(start), end(end)
    {
    }
};

void createActivities(vector<activity> &activities)
{
    activities.push_back(activity(3, 7));
    activities.push_back(activity(2, 4));
    activities.push_back(activity(5, 8));
    activities.push_back(activity(6, 9));
    activities.push_back(activity(1, 11));
    activities.push_back(activity(10, 12));
    activities.push_back(activity(0, 3));
}
bool compareActivities(activity &a, activity &b)
{
    return a.end < b.end;
}

void sortActivities(vector<activity> &a)
{
    sort(a.begin(), a.end(), compareActivities);
}

int numOfActivities(vector<activity> &a)
{

    int j = 0;
    int count = 1;

    for (int i = 1; i < a.size(); i++)
    {
        if (a[i].start >= a[j].end)
        {
            j = i;
            count++;
        }
    }

    return count;
}

void showActivities(vector<activity> &activities)
{
    for (int i = 0; i < activities.size(); i++)
    {
        cout << "activity(" << activities[i].start << ", " << activities[i].end << ")" << endl;
    }
}
int main()
{
    vector<activity> activties;

    createActivities(activties);
    sortActivities(activties);
    showActivities(activties);

    cout << "number of max activities: " << numOfActivities(activties);
}