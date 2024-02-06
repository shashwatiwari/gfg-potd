/*

Author : Shashvat Tiwari
Date : 06/02/2024
Problem : Node at distance
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/node-at-distance/1
Video Solution : NA

------------------------------------------------------------------------------------------

Approach:

The goal of the code is to count the number of nodes that are at a distance of k from a leaf node in a binary tree. The approach uses a recursive DFS (Depth-First Search) to traverse the tree and keep track of the nodes at the specified distance.

DFS Function (find):
The find function performs a depth-first search on the binary tree.
It takes the current node (root), the current level (level), a vector of nodes (v), and the target distance (k) as parameters.
If the current node is a leaf node, it calculates the distance to the ancestor node at level level - k and adds the ancestor node to the ans set if the distance is non-negative.
The function then recursively calls itself for the left and right children of the current node.

Main Function (printKDistantfromLeaf):
The main function initializes an empty vector (v) to keep track of the path from the root to the current node during the DFS.
It calls the find function, starting from the root, with the initial level set to 0.
The result is the size of the ans set, representing the count of unique nodes at a distance of k from a leaf node.

Intuition:
The recursive DFS explores each path in the binary tree, maintaining a vector v that represents the current path from the root to the current node.
When a leaf node is encountered, the code calculates the distance to the ancestor node at a level k above it. If the distance is non-negative, it adds the ancestor node to the set ans.
The use of a set ensures that each unique node meeting the distance criteria is only counted once.
The final result is the count of unique nodes at a distance of k from a leaf node.

Note:
The use of a set (ans) ensures uniqueness in the final count. The set automatically handles the uniqueness of nodes, preventing the same node from being counted multiple times.
*/

class Solution
{
public:
    set<Node *> ans;
    void find(Node *root, int level, vector<Node *> v, int k)
    {
        if (!root)
            return;

        v.push_back(root);
        if (!root->left and !root->right)
        {
            int dist = level - k;
            if (dist >= 0)
                ans.insert(v[dist]);
            return;
        }

        find(root->left, level + 1, v, k);
        find(root->right, level + 1, v, k);
    }

    int printKDistantfromLeaf(Node *root, int k)
    {
        vector<Node *> v;
        find(root, 0, v, k);
        return ans.size();
    }
};