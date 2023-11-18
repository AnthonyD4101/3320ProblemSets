#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

//! Problem Set 17
//! DIVIDE AND CONQUER ALGORITHMS FOR ROTATED SORTED ARRAYS

//* Suppose you are given a sorted array of n distinct numbers that has been rotated k steps, for some unknown integer k between 1 and n- 1. 
//* That is, you are given an array A[1 ..n] such that some prefix A[1.. k] is sorted in increasing order, the corresponding suffix A[k + 1 ..n] 
//* is sorted in increasing order, and A[n] < A[1].

//* For example, you might be given the following 16-element array (where k = 10): 9 13 16 18 19 23 28 31 37 42 1 3 4 5 7 8

//* (a) Describe and analyze a divide and conquer algorithm to compute the unknown integer k. The expected answer should be O (log n). 
//* (b) Describe and analyze a divide and conquer algorithm to determine if the given array contains a given number x. The algorithm 
//* should return the index of x if the array contains the number, otherwise return -1. The expected answer should be O (log n).

//! Input Format
// Array = [Elements of an array separated by space (1 2 3 4)]
// ValueToSearch = [Enter the value to find in array]


//! Input 1:
// 9 13  16  18  19  23  28  31  37  42  1 3 4 5 7 8
// 5

//! Output:
// 10
// 13


//! Input 2:
// 9 13  16  18  19  23  28  31  37  42  1 3 4 5 7 8
// 33

//! Output:
// 10
// -1

//* PASSING
//? Submission ID: a54e1285-b090-4024-8774-4e7fdeced01e


int computeK(vector<int> arr)
{
    int left = 0;
    int right = arr.size() - 1;
    //int result = arr[0];

    while(left < right)
    {
        // If arr[left] is our pivot
        // if(arr[left] < arr[right])
        // {
        //     result = min(result, arr[left]);
        //     break;
        // }

        int middle = left + (right - left) / 2;
        // result = min(result, arr[middle]);

        // If this, search in right subarray
        if(arr[middle] > arr[right])
            left = middle + 1;

        else
            right = middle;
    }
    
    return left;
}

// Binary Search Approach
int findIndexOfGivenValue(vector<int> arr, int valueToSearch)
{
    int left = 0;
    int right = arr.size() - 1;

    while(left <= right)
    {
        int middle = (left + right) / 2;

        if(arr[middle] == valueToSearch)
        {
            return middle;
        }

        // Left Sorted Portion Cases
        if(arr[left] <= arr[middle])
        {
            if(valueToSearch > arr[middle] || valueToSearch < arr[left])
                left = middle + 1;

            else
                right = middle - 1;
        }

        // Right Sorted Portion Cases
        else
        {
            if(valueToSearch < arr[middle] || valueToSearch > arr[right])
                right = middle - 1;

            else
                left = middle + 1;
        }
    }

    return -1;
}


int main(){
    //TODO: Read in Inputs
    vector<int> sortedArray;
    int valueToSearch;

    string arrString;
    getline(cin, arrString);

    stringstream ss(arrString);
    int temp;

    while(ss >> temp)
    {
        sortedArray.push_back(temp);
    }

    cin >> valueToSearch;

    //* START DEBUGGING
    // cout << "SortedArr: ";

    // for(int i = 0; i < sortedArray.size(); i++)
    // {
    //     cout << sortedArray[i] << " ";
    // }

    // cout << endl << endl << "ValueToSearch: " << valueToSearch << endl;
    //* END DEBUGGING

    cout << computeK(sortedArray) << "\n" << findIndexOfGivenValue(sortedArray, valueToSearch) << "\n";

}