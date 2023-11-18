#include <iostream>
#include <vector>
using namespace std;

//! Problem Set 3
//! MINIMUM MAXIMUM SUM

//* Backtracking

//* We are given an integer array numbers where numbers[i] is the i-th number. We assign the n numbers to k groups. Each number is assigned to exactly one group. 
//* Find the assignment such that the maximum sum of the groups is minimized.

//* Return the minimum maximum sum.

//* The input consists of two lines; the second line is the numbers array; the first line has the length of the numbers array n and number of groups k. 
//* Output should be a single number that is the minimum maximum sum among the groups.

//! Example Inputs

//! Input 1
// 3 3
// 3 2 3

//! Output 1
// 3

//* Explanation:
// Assigning each number to each worker leads to maximum sum 3.
// No other assignment can have lower maximum sum.


//! Input 2
// 5 2
// 1 2 4 7 8

//! Output 2
// 11

//* Explanation:
// Assignment: group 1: 1,2,8, sum: 11
// group 2: 4,7, sum: 11
// No other assignments can be lower maximum sum.

int main()
{
    //TODO: Read in Input
    int numsArrayLength, numGroups;

    cin >> numsArrayLength >> numGroups;

    vector<int> numsArray(numsArrayLength);

    for (int i = 0; i < numsArrayLength; i++)
    {
        cin >> numsArray[i];
    }
}