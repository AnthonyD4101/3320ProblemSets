#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//! Problem Set 18
//! SERIALIZATION AND DESERIALIZATION OF A BINARY TREE

//* Serialization is the process of converting a data structure or object into a sequence of bits/bytes so that it 
//* can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed 
//* later in the same or another computer environment. De-serialization is the opposite of serialization, namely, 
//* reading the stream of bytes and reconstructing the original data structure/object in memory.

//* This problem is about de-serialization of a binary tree from a certain format B, and print out its in-order 
//* travesal trace.

//* Constraints:

//* There are less than 10,000 nodes in the tree
//* Each node consists of left child, right child and a value of int type, which is in the range of [-10,000, 10,000]

//* Format B is based on the pre-order traversal of the binary tree. The format B serialized string for the 
//* shown binary tree is

//* {3 {9 {} {}} {20 {15 {} {}} {7 {} {}}}}
//* The format is formally defined as

//* Tree = {Value {Tree} {Tree}} | {}
//* {} stands for an empty tree, otherwise Tree is consists of a value and two sub-trees (left, right).

//? Submission ID: d18b6e71-d2a0-4687-83dc-5cdf34cd073a

struct treeNode{
    int nodeData;
    treeNode *left;
    treeNode *right;

    treeNode(int data){
        nodeData = data;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree{
    private:
        treeNode *root;

    public:
        BinaryTree(){root = nullptr;}

        treeNode* getRoot(){return root;}

        treeNode* parsingHandling(string serializedStr)
        {
            istringstream ss(serializedStr);

            return treeDeserialization(ss);
        };

        //! ParsingHandling Helper Function
        //! Builds Tree Recursively
        treeNode* treeDeserialization(istringstream &ss)
        {
            char charBuffer;

            // Read in the first '{'
            ss >> charBuffer;

            // If the first character is '}' after the '{' then return nullptr, since it is an empty tree
            if(ss.peek() == '}')
            {
                ss >> charBuffer;

                return nullptr;
            }

            // Read in the value of the node
            int nodeValue;
            ss >> nodeValue;

            treeNode *subTreeRoot = new treeNode(nodeValue);

            // Read in the left subtree
            subTreeRoot->left = treeDeserialization(ss);

            // Read in the right subtree
            subTreeRoot->right = treeDeserialization(ss);

            // Read in the last '}'
            ss >> charBuffer;

            return subTreeRoot;
        }

        //! Inorder Print Function
        void inorderTraversal(treeNode* currNode)
        {
            if(currNode == nullptr) return;

            inorderTraversal(currNode -> left);
            cout << currNode -> nodeData << " ";
            inorderTraversal(currNode -> right);
        }
};

int main(){
    BinaryTree BT;

    string serializedString;

    //TODO: Input Parsing
    getline(cin, serializedString);

    //Deserialization Process
    treeNode* treeRoot = BT.parsingHandling(serializedString);

    //Inorder Traversal Print
    BT.inorderTraversal(treeRoot);
}