#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

//! Problem Set 25
//! OPTIMAL JOB PROFIT SCHEUDLING

//* Dynamic Programming

// Consider a scenario where there are n distinct tasks, each with a designated startTime[i], an endTime[i], and a profit[i]. 
// Design a DP algorithm to return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

// The input has 3 lines. The 1st line is the array for startTime. The 2nd line is the array for endTime. The 3rd line is the array for profit.

//* Important Info:

// You must solve this problem using dynamic programming (DP). If you do not use DP, you will not receive any credit for this assignment.

//! Input 1
// 1 1 1
// 2 3 4
// 5 6 4
// Output: 6

//* Explanation: Choose the 2nd job.

//! Input 2
// 1 2 3 4
// 3 4 5 6
// 50 10 40 70
// Output: 120

//* Explanation: Choose the 1st and 4th (last) job.

//! Input 3
// 1 2 3 4 6
// 3 5 9 6 9
// 20 20 100 70 60
// Output: 150

//* Explanation: Choose the 1st, 4th, and 5th job.

//? Submission ID: 8c72d8a7-636d-4464-a180-a1c514e3fb78

struct JobStruct
{
    int startTime;
    int endTime;
    int profit;
};

// custom comparator for sorting jobs by end time
bool jobSorter(JobStruct a, JobStruct b)
{
    return a.endTime < b.endTime;
}

int maxProfit(vector<int> &startTimes, vector<int> &endTimes, vector<int> &profits)
{
    int n = startTimes.size();

    vector<JobStruct> assignedJobs(n);

    for(int i = 0; i < n; i++)
    {
        assignedJobs[i].startTime = startTimes[i];
        assignedJobs[i].endTime = endTimes[i];
        assignedJobs[i].profit = profits[i];
    }

    sort(assignedJobs.begin(), assignedJobs.end(), jobSorter);

    vector<int> dp(n);
    dp[0] = assignedJobs[0].profit;

    for(int i = 1; i < n; i++)
    {
        int profitWithCurrJob = assignedJobs[i].profit;

        // find the last job that doesn't overlap with the current job
        for(int j = i - 1; j >= 0; j--)
        {
            if(assignedJobs[j].endTime <= assignedJobs[i].startTime)
            {
                profitWithCurrJob += dp[j];
                break;
            }
        }

        dp[i] = max(profitWithCurrJob, dp[i - 1]);
    }

    return dp[n - 1];
}

int main(){
    string startTime, endTime, profit;
    vector<int> startTimes, endTimes, profits;

    getline(cin, startTime);
    getline(cin, endTime);
    getline(cin, profit);

    stringstream startStream(startTime);
    stringstream endStream(endTime);
    stringstream profitStream(profit);

    int temp;

    while(startStream >> temp)
        startTimes.push_back(temp);
    
    while(endStream >> temp)
        endTimes.push_back(temp);

    while(profitStream >> temp)
        profits.push_back(temp);

    cout << maxProfit(startTimes, endTimes, profits) << endl;
}