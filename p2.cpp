#include <iostream>

//! Problem Set 2
//! FIND MAXIMUM DIFFERENCE

//* Given an array A, write a program to find the max(A[j]-A[i]) where i < j. 
//* If max(A[j]-A[i])<0, output 0. The input will start with an integer n, which indicates 
//* the length of the given array. The next line will be the array.

//! Example 1 Input
// Input:
// 2
// 1 5
// Output:
// 4

//! Example 2 Input
// Input:
// 4
// 1 5 8 2
// Output:
// 7

//! Example 3:
// Input:
// 6
// 8 7 4 3 2 1
// Output:
// 0

//? Submission ID: e2915497-ab90-4e7a-a141-02a70b71b5ec


bool isDescending(int *arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i] < arr[i + 1])
        {
            return false;
        }
    }

    return true;
}


int main(){

    int arrSize;
    std::cin >> arrSize;

    int myArray[arrSize];

    //* insert elements into array from standard input
    for(int i = 0; i < arrSize; i++)
    {
        std::cin >> myArray[i];
    }

    //* If array is in descending order, return 0, since there is no such case where max(A[j] - A[i]) where i < j
    if(isDescending(myArray, arrSize))
    {
        std::cout << 0 << std::endl;
    }
    
    //* Else, find max difference between A[j] and A[i] where i < j
    //* We can find the largest value starting from the right of the array, then
    //* subtract the value to the left of it. If the difference is greater than the
    //* current max, then set the current max to the difference.
    else
    {
        int maxVal = myArray[arrSize - 1];
        int minVal = myArray[arrSize - 2];
        int maxDiff = maxVal - minVal;

        for(int i = arrSize - 2; i >= 0; i--)
        {
            if(myArray[i] > maxVal)
            {
                maxVal = myArray[i];
            }

            if(maxVal - myArray[i] > maxDiff)
            {
                maxDiff = maxVal - myArray[i];
            }
        }

        std::cout << maxDiff << std::endl;
    }

    return 0;
}