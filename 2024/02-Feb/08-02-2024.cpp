/*

Author : Shashvat Tiwari
Date : 08/02/2024
Problem : Leaf at same level
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/leaf-at-same-level/1
Video Solution : NA

------------------------------------------------------------------------------------------


Approach and Intuition :
 -This code aims to determine whether all leaves in a binary tree are at the same level or not .The approach uses depth - first search(DFS)
to traverse the tree and keep track of the
level of each leaf node encountered.If all leaf nodes are found to be at the same level,
the function returns true; otherwise, it returns false.

Here's a breakdown of the code:

Global Set s:
- The code defines a global set s to store the levels of leaf nodes encountered during the DFS traversal.

DFS Traversal (Recursive Function):
- The check function is a recursive DFS function that takes the current node and its level as parameters.
- If the current node is null, the function returns true, indicating that this node (subtree) satisfies the condition.
- If the current node is a leaf node (both left and right children are null), its level is inserted into the set s.
- The function then recursively calls itself for the left and right children of the current node, incrementing the level by 1 each time.

Checking Condition:
- After the DFS traversal completes, the function checks if all leaf nodes were found at the same level by comparing the size of set s with 1.
- If s.size() is 1, it means all leaf nodes were at the same level, and the function returns true; otherwise, it returns false.

Explanation of the Code:
- The global set s is used to store the levels of leaf nodes encountered during the traversal.
 Since it is declared globally, it retains its state across recursive calls.
- The check function performs a depth-first traversal of the tree, recursively calling
itself for the left and right children of each node.
- Leaf nodes are identified and their levels are inserted into the set s.
- After the traversal completes, the size of set s is checked. If it contains only one
 element, it means all leaf nodes were at the same level, and the function returns true.
  Otherwise, it returns false, indicating that leaf nodes were at different levels.

*/

class Solution
{
public:
    set<int> s;
    bool check(Node *root, int level = 0)
    {
        if (!root)
            return true;

        if (!root->left and !root->right)
            s.insert(level);

        check(root->left, level + 1);
        check(root->right, level + 1);

        return s.size() == 1;
    }
};