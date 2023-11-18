#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

//! Problem Set 5
//! RECONSTRUCT BINARY TREE

//* Recursion

//* Given the pre-order traversal and in-order traversal of a binary tree, 
//* output the post-order traversal of the binary tree.

//! Input Format:
// line 1: number of nodes
// line 2: the pre-order traversal
// line 3: the in-order traversal
// note: The tree nodes are labeled 1, 2, ..., n

//! Input:
// 9
// 1 2 3 4 5 6 7 8 9
// 3 2 5 4 6 1 8 7 9

//! Output:
// 3 5 6 4 2 8 9 7 1
// Explanation:
// The tree can be reconstructed from the input as:
//          1
//        /   \
//       2     7
//      / \   / \
//     3   4 8   9
//        / \
//       5   6

// Inorder: L Root R
// Preorder: Root L R
// Postorder: L R Root

//! FAILING 2 CASES
//? Submission ID: 4404084d-b541-4529-85fe-a2603cafe086

// void printPostOrder(vector<int>& pre, vector<int>& in, int preStart, int inStart, int n)
// {
//     if(n == 0) 
//     {
//         return; // Base case to handle empty subarrays
//     }

//     // Search for the root in the in-order traversal
//     int root = pre[preStart];

//     int i;

//     // Find the index of the root in the in-order traversal
//     for(i = inStart; i < inStart + n; i++)
//     {
//         if(in[i] == root)
//             break;
//     }

//     // Now we know everything to left of in[i] is in tree's left subtree
//     // and everything to right of in[i] is in tree's right subtree

//     // Recursively print the left subtree
//     printPostOrder(pre, in, preStart + 1, inStart, i - inStart);
//     // Recursively print the right subtree
//     printPostOrder(pre, in, preStart + i - inStart + 1, i + 1, n - (i - inStart + 1));

//     cout << pre[preStart] << " ";
// }

vector<int> getPostOrder(vector<int>& pre, vector<int>& in, int& index, int start, int end)
{
    if(start > end)
        return vector<int>();


    vector<int> postOrderTraversal;
    int rootIdx = pre[index];

    int split = start;
    
    while(in[split] != rootIdx)
    {
        split++;
    }

    index++;

    vector<int> left = getPostOrder(pre, in, index, start, split - 1);
    vector<int> right = getPostOrder(pre, in, index, split + 1, end);

    postOrderTraversal.insert(postOrderTraversal.end(), left.begin(), left.end());
    postOrderTraversal.insert(postOrderTraversal.end(), right.begin(), right.end());
    postOrderTraversal.push_back(rootIdx);

    return postOrderTraversal;
}

int main(){
    //TODO: Get Inputs
    int numNodes;
    cin >> numNodes;
    cin.ignore();

    vector<int> preOrder;

    string preOrderStr;
    getline(cin, preOrderStr);
    stringstream ss(preOrderStr);
    int temp;

    while(ss >> temp)
    {
        preOrder.push_back(temp);
    }

    vector<int> inOrder;

    string inOrderStr;
    getline(cin, inOrderStr);
    stringstream ss2(inOrderStr);

    while(ss2 >> temp)
    {
        inOrder.push_back(temp);
    }

    //! Useful Information
    
    //* The first element of the pre-order traversal is the root of the tree
    //* Where you find that element in the in-order traversal, everything to the left of that is in the left 
    //* subtree, everything to the right is in the right subtree

    int index = 0;
    vector<int> finalResult;

    finalResult = getPostOrder(preOrder, inOrder, index, 0, numNodes - 1);

    for(int i = 0; i < finalResult.size(); i++)
    {
        cout << finalResult[i] << " ";
    }
}