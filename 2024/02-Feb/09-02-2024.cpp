/*

Author : Shashvat Tiwari
Date : 09/02/2024
Problem : Children sum parent
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/leaf-at-same-level/1
Video Solution : NA

*/

#include <iostream>
#include <cstdlib> // For NULL

// Define the structure of a node in the tree
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Function to create a new node
Node *createNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to check whether all nodes of a tree have the value equal to the sum of their child nodes
bool isSumProperty(Node *root)
{
    // Base case: If the tree is empty or if it's a leaf node (no child), return true
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return true;

    // Recursively check for left and right subtrees
    int leftSum = root->left ? root->left->data : 0;
    int rightSum = root->right ? root->right->data : 0;

    return (root->data == leftSum + rightSum) &&
           isSumProperty(root->left) &&
           isSumProperty(root->right);
}

int main()
{
    // Create a sample tree
    Node *root = createNode(10);
    root->left = createNode(8);
    root->right = createNode(2);
    root->left->left = createNode(3);
    root->left->right = createNode(5);
    root->right->right = createNode(2);

    // Check if the tree satisfies the sum property
    if (isSumProperty(root))
        std::cout << "Tree satisfies the sum property.\n";
    else
        std::cout << "Tree does not satisfy the sum property.\n";

    return 0;
}
