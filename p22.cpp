#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>

using namespace std;

//! Problem Set 22
//! BACKTRACKING ALGORITHM FOR MAXIMUM POSSIBLE INTEGER THROUGH DIGIT SWAPS

//* Consider a positive number, denoted as M. For instance, if M = 385, by swapping the first digit (3) with the second
//* digit (8), we obtain a larger number M' = 835. Further, by swapping the second and third digits of M', we get 
//* M" = 853, which is the largest number that can be formed using the digits of M.

//* Questions

//* A) Provide a Backtracking Algorithm that for given two positive numbers, M and K, determine the highest possible 
//* number that can be obtained by performing at most K swap operations on the digits of M.

//* B) Provide a Backtracking Algorithm that for a given positive integer M, identify the minimum number of swaps, 
//* represented as K required to produce the maximum possible number using the digits of M.

//! Example 1

//! Input 1
// 129845
// 3

//! Output 1
// 985241
// 4


//! Example 2

//! Input 2
// 129814999
// 2

//! Output 2
// 999814921
// 4

//? Submission ID: 05495c07-c366-48bd-870f-18809b693d57


void backTrack(string M, string &ans, int kSwaps, int counter, unordered_map<string, string>& memo)
{
    // Base Case
    if (kSwaps == 0)
        return;

    // Memoization Case
    if (memo.find(M) != memo.end())
    {
        if (M.compare(ans) > 0)
            ans = M;
        
        return;
    }

    char maxDigit = M[counter];

    // Find the maximum digit in the remaining string
    for (int i = counter + 1; i < M.length(); i++)
    {
        if (M[i] > maxDigit)
        {
            maxDigit = M[i];
        }
    }

    // If the maximum digit is not the current digit, decrement the number of swaps
    if (maxDigit != M[counter])
    {
        kSwaps--;
    }

    // Find the first occurence of the maximum digit in the remaining string
    for (int j = M.length() - 1; j >= counter; j--)
    {
        if (M[j] == maxDigit)
        {
            swap(M[j], M[counter]);

            if (M.compare(ans) > 0)
            {
                ans = M;
            }
            
            // Recurse
            backTrack(M, ans, kSwaps, counter + 1, memo);
            swap(M[j], M[counter]);
        }
    }

    // Memoize
    memo[M] = ans;
}

void minSwaps(string &M, string maxNum, int swaps, int &minKSwaps, int counter, unordered_map<string, int>& minSwapsMemo)
{
    // Base Case
    if (counter == M.length())
    {
        if (M == maxNum)
        {
            minKSwaps = min(minKSwaps, swaps);
        }
        return;
    }

    // Pruning
    if (swaps >= minKSwaps)
        return;

    // If the current digit is not the maximum digit, swap it with the first occurence of the maximum digit
    if (M[counter] != maxNum[counter])
    {
        for (int i = counter + 1; i < M.length(); i++)
        {
            if (M[i] == maxNum[counter])
            {
                swap(M[i], M[counter]);

                // Recurse
                if (minSwapsMemo.find(M) == minSwapsMemo.end() || minSwapsMemo[M] > swaps + 1)
                {
                    minSwaps(M, maxNum, swaps + 1, minKSwaps, counter + 1, minSwapsMemo);
                    minSwapsMemo[M] = swaps + 1;
                }

                // Backtrack
                swap(M[i], M[counter]); // Backtrack
            }
        }
    }

    // If the current digit is the maximum digit, do not swap it
    else
    {
        minSwaps(M, maxNum, swaps, minKSwaps, counter + 1, minSwapsMemo);
    }
}

int main()
{
    //* ----------------- Part A -------------------------------------- *//

    string inputNum = "";
    int kSwaps = 0;

    cin >> inputNum >> kSwaps;

    string resultString = inputNum;
    unordered_map<string, string> swapsMemo;

    backTrack(inputNum, resultString, kSwaps, 0, swapsMemo);

    cout << resultString << "\n";


    //* ----------------- Part B -------------------------------------- *//

    vector<char> inputNums2;

    for (int i = 0; i < inputNum.length(); i++)
    {
        inputNums2.push_back(inputNum[i]);
    }

    // Sort the digits in descending order
    sort(inputNums2.begin(), inputNums2.end());
    // Reverse the digits
    reverse(inputNums2.begin(), inputNums2.end());

    string maxNum = "";
    for (int i = 0; i < inputNums2.size(); i++)
    {
        maxNum += inputNums2[i];
    }

    int minKSwaps = INT_MAX;
    unordered_map<string, int> minSwapsMemo;
    resultString = inputNum;

    minSwaps(inputNum, maxNum, 0, minKSwaps, 0, minSwapsMemo);

    cout << minKSwaps;
}