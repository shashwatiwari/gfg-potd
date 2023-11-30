/*

Author : Shashvat Tiwari
Date : 01/12/2023
Problem : Check whether BST contains dead end
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1
Video Solution : NA

------------------------------------------------------------------------------------------------


Approach Intuition:

Understanding Dead End:
- In a BST, a dead end occurs when a leaf node is such that inserting any value within its range (i.e., between min and max values)
leads to a conflict. This conflict occurs when the tree structure restricts the insertion of a new node, causing the tree to violate the BST property.

Traversal with Range Checking:
- To identify a dead end, we need to traverse the BST while maintaining the range for each node.
- For each node, consider the range within which the node's value must lie to preserve the BST property.

Recursive Exploration:
- Recursively traverse the tree, passing the minimum and maximum ranges for each node.
- For leaf nodes, check if it satisfies the dead end condition:
- If the node is a leaf and the min value is equal to the max value or, in the case of value 1, if min is equal to 1, then it's a dead end.


Code Explanation:

1. isDeadEndUtil Function:
- This function performs the actual recursive traversal of the BST.
- Checks if the current node is a leaf node and satisfies the dead end condition.
- Recursively calls itself for the left and right subtrees while updating the ranges.

2. isDeadEnd Function:
- Initializes the minimum range as 1 (since 1 is also a possible dead end value).
- Calls the isDeadEndUtil function to start the traversal from the root node.

*/

#include <iostream>
#include <climits>

// Definition for a binary tree node.
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    bool isDeadEndUtil(Node *root, int min, int max)
    {
        if (root == nullptr)
            return false;
        if (root->left == nullptr && root->right == nullptr)
        {
            if (min == max || (root->data == 1 && min == 1))
                return true;
        }
        return isDeadEndUtil(root->left, min, root->data - 1) || isDeadEndUtil(root->right, root->data + 1, max);
    }

    bool isDeadEnd(Node *root)
    {
        if (root == nullptr)
            return false;

        int min = 1;       // Initialize the minimum range as 1 (smallest possible value)
        int max = INT_MAX; // Initialize the maximum range

        return isDeadEndUtil(root, min, max);
    }
};

// Test cases
int main()
{
    Node *root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(9);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->left->left->left = new Node(1);

    Solution solution;
    std::cout << "Output: " << (solution.isDeadEnd(root) ? "Yes" : "No") << std::endl;

    return 0;
}

/*

Revised Code Details:

Adjustment for Value 1:
- Special handling added to check if the node value is 1 and min is equal to 1 to address the special case where 1 is a dead end.

Range Initialization:
- Minimum value initialized as 1 instead of INT_MIN to consider the special case of value 1 being a dead end.

*/