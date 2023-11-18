#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

//! Problem Set 20
//! STEPPING NUMBER

//* Backtracking

//* A stepping number is an integer such that all of its adjacent digits have an absolute difference of exactly 1. 
//* For example, 321 is a stepping number while 421 is not. A single digit integer, is always a stepping number. 
//* Given two integers low and high, return a sorted list of all the stepping numbers in the inclusive range [low, high].

//* Write a backtracking algorithm to solve this problem. The input contains 2 lines. The integer on the first line is 
//* low. The integer on the second line is high.

//* Constraint: 0 <= low <= high <= 2 * 109

//! IMPORTANT INFO
// You must solve this problem using backtracking. If you do not use backtracking, then you will not get any 
// points for this assignment.


//! Input 1
// 0
// 15

//! Output
// 0 1 2 3 4 5 6 7 8 9 10 12


//! Input 2
// 300
// 350

// Output
// 321 323 343 345

//* PASSING
//? Submission ID: 30752200-c613-401d-a5c2-9179b288e512

bool isSteppingNumber(int num)
{
    int prevDigit = -1;

    while(num > 0)
    {
        // gets last digit of number
        int currDigit = num % 10;

        // if prevDigit is not -1, then we have a prevDigit, which we can compare to currDigit
        // to see if they are stepping numbers
        if(prevDigit != -1)
        {
            // if the absolute difference between currDigit and prevDigit is not 1, then
            // we do not have a stepping number
            if(abs(currDigit - prevDigit) != 1)
            {
                return false;
            }
        }

        // set prevDigit to currDigit
        prevDigit = currDigit;
        
        // remove last digit from num
        num /= 10;
    }

    return true;
}

void backtrack(int low, int high, int curr, vector<int> &stepNums)
{
    if(low <= curr &&  curr <= high && isSteppingNumber(curr))
        stepNums.push_back(curr);

    if(curr > high || curr == 0)
        return;

    int lastDig = curr % 10;

    if(lastDig < 9)
        backtrack(low, high, curr * 10 + lastDig + 1, stepNums);

    if(lastDig > 0)
        backtrack(low, high, curr * 10 + lastDig - 1, stepNums);
}

// Use Bactracking
vector<int> steppingNums(int low, int high)
{
    vector<int> result;

    for(int i = 0; i < 10; i++)
    {
        backtrack(low, high, i, result);
    }

    return result;
}


int main(){
    int lowRange, highRange;

    cin >> lowRange;
    cin >> highRange;

    vector<int> steppingNumsVector;

    steppingNumsVector = steppingNums(lowRange, highRange);

    sort(steppingNumsVector.begin(), steppingNumsVector.end());

    for(int i = 0; i < steppingNumsVector.size(); i++)
    {
        cout << steppingNumsVector[i] << " ";
    }
}