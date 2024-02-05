/*

Author : Shashvat Tiwari
Date : 22/11/2023
Problem : Symmetric Tree
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/symmetric-tree/1
Video Solution : NA

*/

class Solution
{
public:
    bool isSymmetricHelper(Node *left, Node *right)
    {
        // Base case: if both nodes are NULL, they are symmetric
        if (left == NULL && right == NULL)
            return true;

        // If only one of them is NULL or their values don't match, not symmetric
        if (left == NULL || right == NULL || left->data != right->data)
            return false;

        // Recursively check subtrees' symmetry
        return isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);
    }

    bool isSymmetric(Node *root)
    {
        if (root == NULL) // Empty tree is symmetric
            return true;

        // Pass the left and right subtrees to the helper function
        return isSymmetricHelper(root->left, root->right);
    }
};
