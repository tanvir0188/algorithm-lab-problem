#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

bool sortProfit(const tuple<char, int, int> &job1, const tuple<char, int, int> &job2)
{
    return get<2>(job1) > get<2>(job2);
}

void createJob(vector<tuple<char, int, int>> &jobList)
{
    char job;
    int deadline;
    int profit;
    int numOfJob;

    cout << "Number of job: ";
    cin >> numOfJob;
    cout << endl;

    cout << "JobName  Deadline  Profit" << endl;
    for (int i = 0; i < numOfJob; i++)
    {
        cin >> job >> deadline >> profit;
        jobList.push_back(make_tuple(job, deadline, profit));
    }

    cout << "Job List:" << endl;
    for (int i = 0; i < numOfJob; i++)
    {
        cout << get<0>(jobList[i]) << "  " << get<1>(jobList[i]) << "  " << get<2>(jobList[i]) << endl;
    }
}

vector<char> getJobSeq(vector<tuple<char, int, int>> &jobList)
{
    sort(jobList.begin(), jobList.end(), sortProfit);
    int maxDeadline = get<1>(jobList[0]);

    for (int i = 1; i < jobList.size(); i++)
    {
        maxDeadline = max(maxDeadline, get<1>(jobList[i]));
    }
    vector<char> slot;
}

int main()
{
    vector<tuple<char, int, int>> jobList;
    createJob(jobList);

    return 0;
}
