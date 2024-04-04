/*

Author : Shashvat Tiwari
Date : 03/04/2024
Problem : Kth Common Ancestor in BST
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/kth-common-ancestor-in-bst/1
Video Solution : NA

==============================================================================================

Intuition:

1. We can start by finding the LCA of nodes x and y, which is the lowest node in the tree that has both x and y as descendants.
2. Once we have the LCA, we can find the distance of each node (x and y) from the LCA.
3. The kth common ancestor will be the node that is k steps away from the LCA on the path to either x or y.

Approach:

1. We use a recursive approach to traverse the tree in a preorder manner.
2. At each node, we check if it is either x or y or if its left or right subtree contains x or y.
3. If both x and y are found in the left and right subtrees or if the current node is x or y and either
   of its subtrees contains the other node, we set a flag found to true.
4. If found is true and we have encountered one of the nodes x or y in either subtree, we decrement k and
   if k becomes 0, we update the result to the current node's data.
5. The function returns true if the current node is x or y or if x or y is found in the subtree, false otherwise.

Code Explanation:

1. The kthCommonAncestor function is the main function that initiates the preorder traversal and returns the kth common ancestor.
2. In the preorder function, we recursively traverse the tree.
3. We check if the current node is x or y, if yes, we set current to true.
4. We then recursively check if x or y is present in the left or right subtree.
5. If both x and y are found in the left and right subtrees or if the current node is x or y and either of its subtrees contains the other node, we set found to true.
6. If found is true and we have encountered one of the nodes x or y in either subtree, we decrement k and if k becomes 0, we update the result to the current node's data.
7. The function returns true if the current node is x or y or if x or y is found in the subtree, false otherwise.


*/

class Solution
{
public:
    int kthCommonAncestor(Node *root, int k, int x, int y)
    {
        bool found = false;
        int result = -1;
        preorder(root, x, y, k, found, result);
        return result;
    }

private:
    bool preorder(Node *root, int x, int y, int &k, bool &found, int &result)
    {
        if (!root)
            return false;

        bool left = preorder(root->left, x, y, k, found, result);
        bool right = preorder(root->right, x, y, k, found, result);
        bool current = (root->data == x) || (root->data == y);

        if ((left && right) || ((left || right) && current))
        {
            found = true;
        }

        if (found && (left || right) && --k == 0)
        {
            result = root->data;
        }

        return left || right || current;
    }
};
