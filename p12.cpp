#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

//! Problem Set 12
//! DIVIDE POSITIVE INTEGERS IN SETS OF K CONSECUTIVE NUMBERS

//* Given an array of positive integers nums and a positive integer k, check whether it is possible 
//* to divide nums into sets of k consecutive numbers.

//* Write a recursive function to solve this problem. Return true if it is possible. Otherwise, return false. 
//* The input has 2 lines. The first line is the array of positive integers nums. The second line 
//* is the positive integer k.

//! IMPORTANT INFO

//* You must solve this problem using recursion. If you do not use recursion, then you will not get any 
//* points for this assignment.

//* HINT: One data structure that is helpful in solving this problem is the heap (a.k.a. priority queue) data structure.

//* NOTE: There are some online solutions. However, most if not all of them are iterative algorithms. For example, there 
//* is a simple brute force solution that takes $O(n^2)$ time by checking all possible pairs. There are also solutions 
//* that use hashing (hashmaps, dictionaries, sets). These are not acceptable solutions. In any case, if we 
//* find a solution that is largely copied from another solution (e.g., in a verbatim manner or just simply changing 
//* variable names), it will be considered a violation of the academic honesty policy.


//! Example 1 Input
// Input:
// 1 2 3 3 4 5 5 6
// 4
// Output:
// false
//* Explanation: Array can be divided into [1,2,3,4] and [3,5,5,6]. However, [3,5,5,6] is not 
//* a set of 4 consecutive numbers.

//! Example 2 Input
// Input:
// 1 2 2 3
// 2
// Output:
// true
//* Explanation: Array can be divided into [1,2] and [2,3].

//! Example 3 Input
// Input:
// 1 2 3 4 5
// 2
// Output:
// false
//* Explanation: Array cannot be divided into sets of size 2.

//// FAILED
//// Submission ID: 4a199b5a-cb60-4716-a2c7-e9905e184498

//! PASSED
//? Submission ID: 854b39f0-e2a6-44c2-9c46-7446bc49ba72


bool isDivisibleAndConsective(vector<int>& v, int kDiv)
{
    //! If Empty, It's Consecutive
    if(v.size() == 0)
    {
        return true;
    }

    //! Check if Divisible by k First
    if(v.size() % kDiv != 0)
    {
        return false;
    }

    else
    {
        //1. Push 1st element to sampleVector
        //2. Push kDiv elements into sampleVector (making sure they're consecutive)
        //3. Remove those elements from v
        //4. Recursively call function until v is empty
        vector<int> sampleVector;
        int tempCounter = 0;

        for(int i = 0; i < v.size(); i++)
        {
            //if sampleVector empty, push first element
            if(sampleVector.size() == 0)
            {
                sampleVector.push_back(v[i]);
                tempCounter++;
            }

            //if sampleVector not empty, push kDiv elements into sampleVector
            else if(sampleVector.size() != 0)
            {
                //should skip already existing values to avoid duplicates in sampleVector
                if(v[i] == sampleVector.back())
                {
                    continue;
                }

                else
                {
                    sampleVector.push_back(v[i]);
                    tempCounter++;
                }
            }
            
            
            //once sampleVector has kDiv elements, break out of for loop
            if(tempCounter == kDiv)
            {
                break;
            }
        }

        //! TOO SLOWWW
        // //Delete Elements in sampleVector from v
        // vector<int> resultVect;

        // //Finds the difference between v and sampleVector and stores it in resultVect
        // set_difference(v.begin(), v.end(), sampleVector.begin(), sampleVector.end(), 
        // inserter(resultVect, resultVect.begin()));

        //Erase Elements in sampleVector from v
        for(int i = 0; i < sampleVector.size(); i++)
        {
            auto iter = find(v.begin(), v.end(), sampleVector[i]);
            
            if(iter != v.end())
            {
                v.erase(iter);
            }

            else
            {
                return false;
            }
        }

        return isDivisibleAndConsective(v, kDiv);
    }

}

int main(){

    //* Will hold our values in ascending order (needed to check if consecutive)
    vector<int> numsVector;
    int k;

    //TODO: Read in Input
    string arrInput;

    getline(cin, arrInput);
    stringstream ss(arrInput);

    while(!ss.eof())
    {
        int temp;

        ss >> temp;

        numsVector.push_back(temp);
    }

    cin >> k;

    //! Make sure that vector is sorted in ascending order
    sort(numsVector.begin(), numsVector.end());

    //! Check if Divisible and Consecutive
    if(isDivisibleAndConsective(numsVector, k))
    {
        cout << "true" << endl;
    }

    else
    {
        cout << "false" << endl;
    }


}