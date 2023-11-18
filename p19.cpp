#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

//! Problem Set 19
//! RANDON NUMBER GAME

//* Two players, Robert and Rachel, play a game with random numbers. On each round, Robert and Rachel each choose 
//* a random positive integer. They then earn points, equal to the number of integers chosen by the other player 
//* in previous rounds, which are less than their chosen integer. Players earn no points in the first round.

//* Develop an efficient divide-and-conquer algorithm for computing the final scores of the game for Robert and Rachel, 
//* given the series of numbers chosen by each player in each round. A runtime complexity of O(n log n) will be possible.

//* Hint: Use mergesort as a base for your algorithm. The fact that the subarrays of games under consideration are 
//* sorted will help you to efficiently count game wins.


//! Example of play with a game of four rounds:
// Round 1: Robert chooses 5, Rachel chooses 7.

// Round 2: Robert chooses 3, Rachel chooses 5. Neither player earns points, as Rachel's 5 is equal to Robert's 5 
// from round 1, while Robert's 3 is less than Rachel's 7.

// Round 3: Robert chooses 6, Rachel chooses 8. Rachel gets 2 points, for besting Robert's 5 and 3. 
// Robert gets 1 point for besting Rachel's 5

// Round 4: Robert chooses 9, Rachel chooses 4. Robert gets 3 points as his 9 bests Rachel's 7, 5, and 8. 
// Rachel gets one point for besting Robert's 3.

// The total points for Robert is 4, and for Rachel, is 3.

//! The input format for this problem is:
// First line is Robert's chosen numbers, separated by spaces
// Second line is Rachel's chosen numbers, separated by spaces
// The output expected is a single line, with Robert's final score first, followed by Rachel's.

// Input:
// 5 3 6 9
// 7 5 8 4
// Output:
// 4 3

//* PASSING!!!
//? Submission ID: a60bcec7-af4e-4f3b-8bf9-4ce680d3be5d

int playerFinalScores(vector<int> &leftSubarr, vector<int> &rightSubarr)
{
    int i = 0;
    int tempScore = 0;
    int finalScore = 0;

    while(i < rightSubarr.size())
    {
        while(tempScore < leftSubarr.size() && rightSubarr[i] > leftSubarr[tempScore])
        {
            tempScore++;
        }

        finalScore += tempScore;
        i++;
    }

    return finalScore;
}

void merge(vector<int> &robertArr, vector<int> &rachelArr, int &robertScore, int &rachelScore, int begin, int middle, int end)
{
    //! Find Midpoints of Left and Right Subarrays
    int leftSubarraySize = middle - begin + 1;
    int rightSubarraySize = end - middle;
    
    //! Create 4 Subarrays
    vector<int> leftArrRobert(leftSubarraySize);
    vector<int> rightArrRobert(rightSubarraySize);

    vector<int> leftArrRachel(leftSubarraySize);
    vector<int> rightArrRachel(rightSubarraySize);

    //! Copy Data to Each Subarray
    for(int i = 0; i < leftSubarraySize; i++)
    {
        leftArrRobert[i] = robertArr[begin + i];
        leftArrRachel[i] = rachelArr[begin + i];
    }

    for(int i = 0; i < rightSubarraySize; i++)
    {
        rightArrRobert[i] = robertArr[middle + 1 + i];
        rightArrRachel[i] = rachelArr[middle + 1 + i];
    }

    //! Indexes for Subarrays
    int iRobert = 0;
    int iRachel = 0;

    int jRobert = 0;
    int jRachel = 0;

    //* Indexes of Merged Subarrays
    int kRobert = begin;
    int kRachel = begin;

    //! Add Points Before Merging
    if(iRobert < leftSubarraySize && jRobert < rightSubarraySize)
    {
        robertScore += playerFinalScores(leftArrRachel, rightArrRobert);
    }

    if(iRachel < leftSubarraySize && jRachel < rightSubarraySize)
    {
        rachelScore += playerFinalScores(leftArrRobert, rightArrRachel);
    }

    //! Merge Subarrays (Normal Merge Sort)
    while(iRobert < leftSubarraySize && jRobert < rightSubarraySize)
    {
        if(leftArrRobert[iRobert] <= rightArrRobert[jRobert])
        {
            robertArr[kRobert] = leftArrRobert[iRobert];
            iRobert++;
        }
        else
        {
            robertArr[kRobert] = rightArrRobert[jRobert];
            jRobert++;
        }

        kRobert++;
    }

    while(iRachel < leftSubarraySize && jRachel < rightSubarraySize)
    {
        if(leftArrRachel[iRachel] <= rightArrRachel[jRachel])
        {
            rachelArr[kRachel] = leftArrRachel[iRachel];
            iRachel++;
        }
        else
        {
            rachelArr[kRachel] = rightArrRachel[jRachel];
            jRachel++;
        }

        kRachel++;
    }

    //! Copy Remaining Elements
    while(iRobert < leftSubarraySize)
    {
        robertArr[kRobert] = leftArrRobert[iRobert];
        iRobert++;
        kRobert++;
    }

    while(jRobert < rightSubarraySize)
    {
        robertArr[kRobert] = rightArrRobert[jRobert];
        jRobert++;
        kRobert++;
    }

    while(iRachel < leftSubarraySize)
    {
        rachelArr[kRachel] = leftArrRachel[iRachel];
        iRachel++;
        kRachel++;
    }

    while(jRachel < rightSubarraySize)
    {
        rachelArr[kRachel] = rightArrRachel[jRachel];
        jRachel++;
        kRachel++;
    }

}

void mergeSort(vector<int> &robertArr, vector<int> &rachelArr, int &robertScore, int &rachelScore, int begin, int end)
{
    if(begin < end)
    {
        int middle = begin + (end - begin) / 2;

        mergeSort(robertArr, rachelArr, robertScore, rachelScore, begin, middle);
        mergeSort(robertArr, rachelArr, robertScore, rachelScore, middle + 1, end);

        merge(robertArr, rachelArr, robertScore, rachelScore, begin, middle, end);
    }
}


int main(){

    vector<int> robertPoints;
    vector<int> rachelPoints;

    //TODO: Read in the input for Robert and Rachel's points
    string robertInput;
    string rachelInput;

    getline(cin, robertInput);
    getline(cin, rachelInput);

    stringstream robertStream(robertInput);
    stringstream rachelStream(rachelInput);

    int temp;

    while(robertStream >> temp)
    {
        robertPoints.push_back(temp);
    }

    while(rachelStream >> temp)
    {
        rachelPoints.push_back(temp);
    }

    int robertScore = 0;
    int rachelScore = 0;

    mergeSort(robertPoints, rachelPoints, robertScore, rachelScore, 0, robertPoints.size() - 1);

    cout << robertScore << " " << rachelScore << endl;

    return 0;
}