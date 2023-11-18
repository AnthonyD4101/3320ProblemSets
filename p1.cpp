#include <iostream>

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