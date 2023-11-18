#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

//! Problem Set 23
//! Optimal Skiing Route

//? Dynamic Programming

// Imagine that a skiier (S) is skiing down a slope depicted as an N x N matrix of characters. The skiier starts at the top of the slope (top-left square) 
// and can only go downhill (down or to the right). In the skiier's path, there is regular snow (.), obstacles (O), and flags (F). Passing through regular 
// snow or flags takes 1 second on each square, while obstacles require slowing down to avoid and take 3 seconds to pass through. Each flag is collected 
// when passed through. Upon reaching the bottom of the slope (bottom-right square) the player receives 5 points for every flag collected. The player also 
// loses 1 point for every second slower they take to traverse the course than a specified pace time, though if they have a time faster than pace time, 
// they gain one point for every second they travel faster than pace time.

// Return the highest score possible, and the number of flags collected on that run. If there are multiple runs with the same highest score, pick one with 
// the maximum number of flags. A dynamic programming solution should have runtime O(n^2).

//* -------------------------------------------------------------------------------------------

//! Input format:
//* [integer N: the size of the matrix] 
//* [integer pace: pace time in seconds] 
//* [N X N matrix of characters (., S, O, or F), without spaces, each row on a separate line]

//! Output format: 
//* [integer score: the total score] [integer flags: the number of flags collected]

//* -------------------------------------------------------------------------------------------

//! EXAMPLE INPUTS

//! Input 1
// 4
// 6
// S...
// .OF.
// .O.O
// ....

//! Output 1
// 5 1

//* Explanation: In this case, the pace time 6 is the time taken by the fastest route: the skiier grabs the flag while avoiding obstacles: 
//* each step depicted by a number below: 

//* S12 
//* .O3.
//* .O4O
//* ..56

//* Thus the player gets 5 points for one flag, and loses no points for being slower than pace.


//! Input 2
// 3
// 4
// SOF
// ..F
// ...

//! Output 2
// 8 2

//* Explanation: In this case, the optimal route is not the fastest route, since the 10 points earned by flags offsets the 2 additional seconds 
//* caused by the obstacle. Steps depicted below:

//* S12
//* ..3
//* ..4

//* The final score is 8, for 10 points from the two flags, and -2 points for requiring 6 seconds to traverse (2 more than the pace time)

//? Submission ID: 3ded55d5-44bf-4d96-9bb8-b1638fafc647z

vector<int> optimalRoute(int matrixSize, int paceTime, vector<vector<char> >& slopeMatrix)
{
    vector<vector<int> > score(matrixSize, vector<int>(matrixSize, -1e5));
    vector<vector<int> > flags(matrixSize, vector<int>(matrixSize, 0));

    score[0][0] = 0;

    for(int i = 0; i < matrixSize; i++)
    {
        for(int j = 0; j < matrixSize; j++)
        {
            if(i == 0 && j == 0)
                continue;

            int finalScore = -1e5;
            int finalFlags = 0;

            if(i > 0)
            {
                int newScore = score[i - 1][j] - 1;
                int newFlags = flags[i - 1][j];

                if(slopeMatrix[i][j] == 'O')
                {
                    newScore -= 2;
                }

                else if(slopeMatrix[i][j] == 'F')
                {
                    newScore += 5;
                    newFlags += 1;
                }

                if(newScore > finalScore || (newScore == finalScore && newFlags > finalFlags))
                {
                    finalScore = newScore;
                    finalFlags = newFlags;
                }
            }

            if(j > 0)
            {
                int newScore = score[i][j - 1] - 1;
                int newFlags = flags[i][j - 1];

                if(slopeMatrix[i][j] == 'O')
                {
                    newScore -= 2;
                }

                else if(slopeMatrix[i][j] == 'F')
                {
                    newScore += 5;
                    newFlags += 1;
                }

                if(newScore > finalScore || (newScore == finalScore && newFlags > finalFlags))
                {
                    finalScore = newScore;
                    finalFlags = newFlags;
                }
            }

            score[i][j] = finalScore;
            flags[i][j] = finalFlags;
        }
    }

    vector<int> result;
    result.push_back(score[matrixSize - 1][matrixSize - 1] + paceTime);
    result.push_back(flags[matrixSize - 1][matrixSize - 1]);
    return result;
}

int main()
{
    int matrixSize;
    int paceTime;

    cin >> matrixSize >> paceTime;
    cin.ignore();

    //cout << "Size of Matrix: " << matrixSize << endl;
    //cout << "Pace Time: " << paceTime << endl;

    //TODO: Fill in the matrix

    //* initialize 2D vector to access elements like a matrix
    vector<vector<char> > slopeMatrix(matrixSize, vector<char>(matrixSize));

    for(int i = 0; i < matrixSize; i++)
    {
        string line;
        getline(cin, line);

        for(int j = 0; j < matrixSize; j++)
        {
            slopeMatrix[i][j] = line[j];
        }
    }

    // pair<int, int> optimizedScore = optimalSkiingRoute(matrixSize, paceTime, slopeMatrix);

    // cout << optimizedScore.first << " " << optimizedScore.second << endl;

    vector<int> optimizedScore = optimalRoute(matrixSize, paceTime, slopeMatrix);

    cout << optimizedScore[0] << " " << optimizedScore[1] << endl;
}