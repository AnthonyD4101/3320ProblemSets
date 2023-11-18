#include <iostream>
#include <vector>
using namespace std;

//! Problem Set 16
//! LAST REMAINING NUMBER

//? Submission ID: aa1d0913-915b-4c70-9182-7d2bc5c823be

//* Given the integer n, you have a list of all integers in the range [1, n] sorted in a strictly increasing 
//* order. Performing the following steps:

//* 1. Starting from left to right, remove the first number and every other number afterward until you 
//*    reach the end of the list.

//* 2. Repeat the previous step again, but this time from right to left, remove the rightmost number and 
//*    every other number from the remaining numbers.

//* 3. Keep repeating the steps again, alternating left to right and right to left, until a single number remains.

//* 4. Return the last remaining number.

//* Write a recursive function to solve this problem. The input contains 1 positive integer n with 1 <= n <= 10^9

//! IMPORTANT INFO -> MUST USE RECURSION

//! Example 1 Input
// Input: 4
// Output: 2
// Explanation: (bold indicate that the number is removed at that step)
// arr = [1, 2, 3, 4]
// arr = [2, 4]
// arr = [2]

//! Example 2 Input
// Input: 9
// Output: 6
// Explanation: (bold indicate that the number is removed at that step)
// arr = [1, 2, 3, 4, 5, 6, 7, 8, 9]
// arr = [2, 4, 6, 8]
// arr = [2, 6]
// arr = [6]


//! Leftmost Deletion = 0
//! Rightmost Deletion = 1
// void elementDeletion(vector<int> &vect, int elCount, int deletionType)
// {
//     //! Base Case
//     if(elCount == 1)
//         return;

//     else
//     {
//         //* LEFTMOST DELETION
//         if(deletionType == 0)
//         {
//             for(int i = 0; i < vect.size(); i += 2)
//             {
//                 //cout << "Element " << vect[i] << " erased" << endl;
//                 vect[i] = 0;
//                 elCount--;
//             }

//             for(int i = vect.size() - 1; i >= 0; i--)
//             {
//                 if(vect[i] == 0)
//                 {
//                     vect.erase(vect.begin() + i);
//                 }
//             }

//             return elementDeletion(vect, elCount, 1);
//         }

//         //* RIGHTMOST DELETION
//         else
//         {
//             for(int i = vect.size() - 1; i >= 0; i -= 2)
//             {
//                 //cout << "Element " << vect[i] << " erased" << endl;
//                 vect.erase(vect.begin() + i);
//                 elCount--;
//             }

//             return elementDeletion(vect, elCount, 0);
//         }
//     }
// }

int calculateLastRemainingElement(int num)
{
    if(num == 1)
        return 1;

    else
        return 2 * (num / 2 + 1 - calculateLastRemainingElement(num / 2));
}

int main(){

    int elementCount;

    cin >> elementCount;

    // vector<int> elementContainer(elementCount);

    // //! Fill in vector with numbers from 1 to n
    // for(int i = 0; i < elementCount; i++)
    // {
    //     elementContainer[i] = i + 1;
    // }

    // elementDeletion(elementContainer, elementCount, 0);

    // cout << elementContainer[0] << endl;

    cout << calculateLastRemainingElement(elementCount) << endl;

    return 0;
}