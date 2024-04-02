/*

Author : Shashvat Tiwari
Date : 02/04/2024
Problem : Minimum absolute difference in BST
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/minimum-absolute-difference-in-bst-1665139652/1
Video Solution : NA

--------------------------------------------------------------------------------------------------------------

Intuition:
In a binary search tree (BST), the inorder traversal visits nodes in sorted order. If we do an inorder traversal
 of a BST and keep track of the previously visited node, we can easily calculate the absolute difference between adjacent nodes.
 The minimum of these differences will be the minimum absolute difference between any two nodes in the BST.

The inorder function is a helper function that performs an inorder traversal of the binary search tree (BST) rooted at node. It takes three arguments: node, a reference to the previous node visited (prev), and a reference to the minimum absolute difference found so far (minDiff).

In the inorder function:

If the current node is nullptr, it returns, as there's nothing to process.
It recursively calls inorder on the left subtree of the current node.
If the prev node is not nullptr, it calculates the absolute difference between the current node's value and the previous node's value and updates minDiff if this difference is smaller than the current minDiff.
It then updates prev to point to the current node.
Finally, it recursively calls inorder on the right subtree of the current node.
The absolute_diff function is the main function that calculates the minimum absolute difference between any two nodes in the BST. It takes the root of the BST as input and returns the minimum absolute difference.

It initializes minDiff to INT_MAX to store the minimum absolute difference found so far and prev to nullptr to store the previous node visited during the inorder traversal.

It then calls the inorder function with the root node, prev, and minDiff as arguments.

After the inorder traversal is complete, the minDiff variable will contain the minimum absolute difference between any two nodes in the BST, which is then returned by the absolute_diff function.
*/

class Solution
{
public:
    void inorder(Node *node, Node *&prev, int &minDiff)
    {
        if (node == nullptr)
            return;

        inorder(node->left, prev, minDiff);

        if (prev != nullptr)
        {
            minDiff = min(minDiff, node->data - prev->data);
        }
        prev = node;

        inorder(node->right, prev, minDiff);
    }

    int absolute_diff(Node *root)
    {
        int minDiff = INT_MAX;
        Node *prev = nullptr;
        inorder(root, prev, minDiff);
        return minDiff;
    }
};