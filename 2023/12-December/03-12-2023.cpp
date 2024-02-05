/*

Author : Shashvat Tiwari
Date : 03/12/2023
Problem : Brothers from different root
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/brothers-from-different-root/1
Video Solution : NA

*/

#include <vector>

// Definition of a BST node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Function to perform inorder traversal on a BST and store values in a vector
void inorderTraversal(Node *root, std::vector<int> &values)
{
    if (root == nullptr)
        return;

    inorderTraversal(root->left, values);
    values.push_back(root->data);
    inorderTraversal(root->right, values);
}

// Function to count pairs in BSTs with sum equal to x
int countPairs(Node *root1, Node *root2, int x)
{
    std::vector<int> values1, values2;
    inorderTraversal(root1, values1); // Convert BST1 to a sorted array
    inorderTraversal(root2, values2); // Convert BST2 to a sorted array

    int count = 0;
    int ptr1 = 0, ptr2 = values2.size() - 1; // Initialize pointers for two-pointer approach

    // Two-pointer approach to find pairs that sum up to x
    while (ptr1 < values1.size() && ptr2 >= 0)
    {
        int sum = values1[ptr1] + values2[ptr2];
        if (sum == x)
        {
            count++;
            ptr1++;
            ptr2--;
        }
        else if (sum < x)
        {
            ptr1++;
        }
        else
        {
            ptr2--;
        }
    }

    return count;
}
