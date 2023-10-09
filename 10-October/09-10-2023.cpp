/*

Author : Shashvat Tiwari
Date : 09/10/2023
Problem : Height of Binary Tree
Difficulty : Easy
Problem Link :https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1
Video Solution : NA

*/

class Solution
{
public:
    // Function to find the height of a binary tree.
    int height(struct Node *node)
    {
        // If the tree is empty, its height is 0.
        if (node == NULL)
        {
            return 0;
        }

        // Recursively calculate the height of the left and right subtrees.
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        // Return the maximum of the left and right subtree heights, plus 1 for the current node.
        return 1 + max(leftHeight, rightHeight);
    }
};
