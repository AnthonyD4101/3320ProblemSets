#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

//! Problem Set 24
//! Text Fitting


//* Given a text (a sequence of words) and a container with a certain width and height, find the number of text that 
//* can be fitted in the container without splitting any words. There must be a single space between two consecutive 
//* words on a line.

//* The input has 3 lines. The first line is an integer for width. The second line is an integer for height. 
//* The third line is a string for text.

//! Input 1
// 2
// 6
// cosc 3320
// Output: 1

//* Explanation: The text is a sequence of 2 words: cosc, 3320
//* c o s c - -
//* 3 3 2 0 - -
//* The character '-' signifies an empty space on the screen.

//! Input 2
// 3
// 7
// one a bc
// Output: 2

//* Explanation: The text is a sequence of 3 words: one, a, bc
//* o n e - a - -
//* b c - o n e -
//* a - b c - - -
//* The character '-' signifies an empty space on the screen.

//? Submission ID: 0fd9370b-4c14-4727-9cf4-121ac5d58703

int textFits(int w, int h, vector<int>& wordLengths, int wordLengthSize, int wordCount)
{
    // w -> num of rows
    // h -> length of rows
    vector<int> DPVals(w + 1, 0);

    int currentWord = 0;
    int spacesUsed = 0;
    int rowIndex = 0;
    int fittedTextCount = 0;

    do
    {
        // If the height is greater than or equal to the total number of words
        if(h >= wordCount)
        {
            // Calculate how many lines can be filled with the words
            int lines = h / wordCount;
            fittedTextCount += lines;
            DPVals[rowIndex] = fittedTextCount;
            spacesUsed = h - (h % wordCount);
        }

        else
            spacesUsed = 0;

        // While the length of the current word can fit within the available space
        while(wordLengths[currentWord] <= h - spacesUsed)
        {
            spacesUsed += wordLengths[currentWord] + 1; // Add word length and a space
            currentWord++;
            
            if(currentWord == wordLengthSize)
            {
                // If all words have been used, increment fittedTextCount and reset currentWord
                fittedTextCount++;
                currentWord = 0;
                DPVals[rowIndex] = fittedTextCount;
            }
        }

        rowIndex++; // Move to the next row
    } while(currentWord != 0 && rowIndex < w); // Continue until a full pass is made and the last word is not placed

    int tempVal = rowIndex;

    // Complete DPVals array for the remaining rows
    while(rowIndex < w)
    {
        DPVals[rowIndex] = fittedTextCount + DPVals[rowIndex - tempVal];
        rowIndex++;
    }

    return DPVals[w - 1]; // Return the final value for the last row
}

int main()
{
    int width, height;
    cin >> width >> height;

    string text;
    cin.ignore();
    getline(cin, text);

    vector<int> wordLengths;

    stringstream ss(text);
    string word;

    while (ss >> word)
    {
        wordLengths.push_back(word.size());
    }

    int wordCount = text.size() + 1;
    int wordLengthSize = wordLengths.size();

    int numOfFits = textFits(width, height, wordLengths, wordLengthSize, wordCount);

    cout << numOfFits << endl;
}