#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

//! Problem Set 13
//! DISTANCES IN BINARY SEARCH TREES

//* Given an array representing values to be added to an empty binary search tree in order, 
//* and a pair of these values, return the shortest path distance between these values in the 
//* tree after all values have been inserted.

//* Input format:
//* line 1: [node values for input tree]
//* line 3: [node1] [node2]


//! Example 1 Input
// Input:
// 3 1 5 7 2 4
// 1 7
// Output:
// 3
//* The shortest path from 1 to 7 is through their common ancestor 3.

//! Example 2 Input
// Input:
// 3 1 5 7 2 4
// 3 4
// Output:
// 2
//* This is because in the completed tree, 5 is a child of 3, and 4 is a child of 5.

//// FAILED
//// Submission ID: cc49977e-196e-4f28-8f94-510ad4d8d69a

//! PASSED
//? Submission ID: ccbb18b2-cce7-4a3b-ad31-2cf732da17f8


//!BST Struct and Class
struct treeNode
{
    int data;
    treeNode *left;
    treeNode *right;

    treeNode(int d)
    {
        data = d;
        left = right = nullptr;
    }
};

class BST
{
    private:
        treeNode* root;

    public:
        BST() {root = nullptr;}
        treeNode* getRoot() {return root;}

        treeNode* insertToTree(treeNode* curr, int val)
        {
            //if tree empty & curr runs off tree
            if(curr == nullptr)
            {
                treeNode *temp = new treeNode(val);

                //if empty
                if(root == nullptr)
                {
                    root = temp;
                    return root;
                }

            else
                return temp;
            }

            
            //if val > data
            else if(val > curr -> data)
            {
                curr -> right = insertToTree(curr -> right, val);
            }

            //if val < data
            else if (val < curr -> data)
            {
                curr -> left = insertToTree(curr -> left, val);
            }

            //if val == data
            else
            {
                curr -> data = val;
            }

            return curr;
        }

        treeNode* findCommonAncestor(treeNode* root, int n1, int n2)
        {

            //! If No Root
            if(root == nullptr)
                return nullptr;
            
            if(root -> data > n1 && root -> data > n2)
                return findCommonAncestor(root -> left, n1, n2);

            if(root -> data < n1 && root -> data < n2)
                return findCommonAncestor(root -> right, n1, n2);


            return root;
        }

        int firstNodeDistance(treeNode* root, int n1)
        {
            int distance = 0;

            //! if n1 is root node, no distance traveled
            if(root -> data == n1)
                return distance;

            else if(root -> data > n1)
            {
                distance++;
                return distance + firstNodeDistance(root -> left, n1);
            }

            else
            {
                distance++;
                return distance + firstNodeDistance(root -> right, n1);
            }

        }

        int secondNodeDistance(treeNode* root, int n2)
        {
            int distance = 0;

            //! if n2 is root node, no distance traveled
            if(root -> data == n2)
                return distance;

            else if(root -> data > n2)
            {
                distance++;
                return distance + secondNodeDistance(root -> left, n2);
            }

            else
            {
                distance++;
                return distance + secondNodeDistance(root -> right, n2);
            }

        }
};


int main(){

    //initializations
    BST ourBST;
    vector<int> treeInputValues;
    vector<int> nodeValues;
    int firstNode, secondNode;

    //* ---------------------------------------------------------------------------------------------------------------------------------

    //TODO: Take in Inputs from Line 1
    string intInput;
    
    getline(cin, intInput);
    stringstream ss(intInput);
    
    //parse integers until end of 1st stream
    while(!ss.eof())
    {
        int tempNum;

        ss >> tempNum;

        treeInputValues.push_back(tempNum);
    }


    //TODO: Take in Inputs from Line 3
    string nodeInput;

    getline(cin, nodeInput);
    stringstream ss2(nodeInput);

    while(!ss2.eof())
    {
        int tempNum;

        ss2 >> tempNum;

        nodeValues.push_back(tempNum);
    }

    firstNode = nodeValues[0];
    secondNode = nodeValues[1];

    //* ---------------------------------------------------------------------------------------------------------------------------------

    //TODO: Insert Values into BST

    for(int i = 0; i < treeInputValues.size(); i++)
    {
        ourBST.insertToTree(ourBST.getRoot(), treeInputValues[i]);
    }

    //TODO: Find firstNode & secondNode Common Ancestor in BST

    treeNode* commonAncestor = ourBST.findCommonAncestor(ourBST.getRoot(), firstNode, secondNode);

    //* Debugging
    ////cout << "Common Ancestor of " << firstNode << " and " << secondNode << " is " << commonAncestor -> data << endl;

    //TODO: Find Shortest Path Distance Between firstNode & secondNode

    int totalShortestDistance = ourBST.firstNodeDistance(commonAncestor, firstNode) + ourBST.secondNodeDistance(commonAncestor, secondNode);
    
    //* Debugging
    ////cout << ourBST.firstNodeDistance(commonAncestor, firstNode) << endl;
    ////cout << ourBST.secondNodeDistance(commonAncestor, secondNode) << endl;

    //! FINAL OUTPUT
    cout << totalShortestDistance << endl;
}