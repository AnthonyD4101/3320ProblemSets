#include <iostream>
#include <string>
#include <vector>
using namespace std;

//! Problem Set 1
//! WAYS TO PLACE CHESS PIECES


//* Backtracking

//* Given a board with irregular shape, your task is to place chess pieces and make sure no more than 1 chess pieces is placed on the same row or the same column. 
//* Output the number of different ways of such placement.

//* The first line of the input consists of two integers n and k. n means the size of board is nÃ—n and k is the number of chess pieces to be placed. 
//* The next n lines describe the shape of the chess board: '#' describes the board region and '.' is the blank region (cannot place chess piece here)


//! Example Inputs

//! Input 1
// 2 1
// .#
// #.

//! Output 1
// 2


//! Input 2
// 3 3
// #.#
// .##
// .##

//! Output 2
// 2


//! Input 3
// 4 4
// ...#
// ..#.
// .#..
// #...

//! Output 3
// 1

//? Submission ID: 17b641d6-06ef-49ee-834a-722c0ec14394

bool isValidPlacement(vector<int> &temp, int column, int row)
{
    for(int i = 0; i < row; i++)
        if(temp[i] == column)
            return false;

    return true;
}

int placePieces(vector<string> &chessBoard, vector<int> &temp, int numPieces, int row, int queensPlaced)
{
    if(queensPlaced == numPieces)
        return 1;

    if(row == chessBoard.size())
        return 0;

    int numWays = 0;

    for(int i = 0; i < chessBoard.size(); i++)
    {
        if(chessBoard[row][i] == '#' && isValidPlacement(temp, i, row))
        {
            temp[row] = i;
            numWays += placePieces(chessBoard, temp, numPieces, row + 1, queensPlaced + 1);
            temp[row] = -1;
        }
    }

    numWays += placePieces(chessBoard, temp, numPieces, row + 1, queensPlaced);

    return numWays;
}

int main()
{
    //TODO: Read in Input
    int boardSize, numPieces;
    cin >> boardSize >> numPieces;

    vector<string> chessBoard(boardSize);

    for (int i = 0; i < boardSize; i++)
    {
        cin >> chessBoard[i];
    }

    //Make a temp vector to store the column of each queen
    vector<int> temp(boardSize, -1);

    int numWays = placePieces(chessBoard, temp, numPieces, 0, 0);

    cout << numWays << endl;
}