#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

//! Problem Set 15
//! RECURSIVE METHOD TO TRAVERSE STAIRCASE

//* You're given two positive integers representing the height of a staircase and the maximum number of steps 
//* that you can advance up the staircase at a time. Write a function that returns the number of ways in which 
//* you can climb the staircase.

//* For example, if you were given a staircase of height = 3 and maxSteps = 2 you could climb the staircase in 
//* 3 ways. You could take 1 step, 1 step, then 1 step, you could also take 1 step, then 2 steps, and you could 
//* take 2 steps, then 1 step.

//! Input format:
// height = [The height of the staircase]
// maxSteps = [The maximum number of steps you can take at a time]

//! Input 1:
// 4
// 2

//! Output 1:
// 5

//? Submission ID: e0922216-12f6-4e44-afb6-6146124fc752


//! DYNAMIC PROGRAMMING

int numberOfStepCombinations(int height, int steps)
{
    // we initialize the number of combinations to 0
    int numCombinations = 0;

    // if height is 0, then we have reached the top of the staircase
    // so we return 1
    if(height == 0)
    {
        return 1;
    }

    // if height is less than 0, then we have gone past the top of the staircase
    // so we return 0
    if(height < 0)
    {
        return 0;
    }

    // we iterate through all the steps we can take
    for(int i = 1; i <= steps; i++)
    {
        // we add the number of combinations we can take from the current step
        // to the total number of combinations
        numCombinations += numberOfStepCombinations(height - i, steps);
    }

    // we return the total number of combinations
    return numCombinations;
}


int main(){
    int staircaseHeight;
    int maxSteps;

    cin >> staircaseHeight >> maxSteps;

    cout << numberOfStepCombinations(staircaseHeight, maxSteps) << "\n";
}