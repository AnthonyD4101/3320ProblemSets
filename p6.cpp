#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

//! Problem Set 6
//! GRAPH TRAVERSAL

//* Graph

//* Given a n * n grid of square; each square can be 1 (land) or 0 (water). An island is a maximally connected land square;
//* two land square are connected if they have common edges.

//* Find the number of islands for the given grid of squares

//! Example 1

//! Input 1
// 6
// 1 1 0 0 1 1
// 1 0 1 1 0 0
// 1 0 0 1 1 1
// 0 0 0 0 0 1
// 1 0 0 0 0 1
// 1 1 1 1 1 1

//! Output 1
// 3

//! Explanation
// There are three connected land areas: top left, top right, and bottom.

//! Example 2

//! Input 2
// 10
// 1 1 1 0 0 0 0 0 1 1
// 0 1 0 0 1 1 1 1 0 0
// 1 1 1 1 0 1 1 0 0 1
// 1 0 0 1 0 1 1 1 1 1
// 1 0 1 0 1 1 0 1 0 1
// 1 1 0 0 0 0 0 0 0 1
// 0 0 1 0 1 1 1 0 0 1
// 0 1 1 1 1 0 1 0 1 1
// 1 0 1 1 1 1 1 0 1 0
// 0 1 1 0 0 0 0 1 0 0

//! Output 2
// 7

//? Submission ID: 3c0655dc-496a-43df-aafe-601d534d6199

void dfs(vector<vector<int> > &grid, int i, int j, int m, int n){
    if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
    {
        return;
    }

    grid[i][j] = 0;

    dfs(grid, i - 1, j, m, n);
    dfs(grid, i + 1, j, m, n);
    dfs(grid, i, j - 1, m, n);
    dfs(grid, i, j + 1, m, n);
}

int numIslands(vector<vector<int> > &grid){
    int m = grid.size();
    int n = grid[0].size();

    int numIslands = 0;

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(grid[i][j] == 1)
            {
                dfs(grid, i, j, m, n);
                numIslands++;
            }
        }
    }

    return numIslands;
}

int main()
{
    //TODO: Read in Input
    int gridDimensions;

    cin >> gridDimensions;
    cin.ignore();

    vector<vector<int> > grid(gridDimensions, vector<int>(gridDimensions));

    for(int i = 0; i < gridDimensions; i++)
    {
        string inputString;
        getline(cin, inputString);
        stringstream ss(inputString);
        int inputTemp;

        for(int j = 0; j < gridDimensions; j++)
        {
            ss >> inputTemp;
            grid[i][j] = inputTemp;
        }
    }

    //TODO: Read in Input


    cout << numIslands(grid) << endl;
}