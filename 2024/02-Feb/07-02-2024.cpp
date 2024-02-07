/*

Author : Shashvat Tiwari
Date : 07/02/2024
Problem : Minimu Nodes between two given node of a binary tree
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1
Video Solution : NA

-----------------------------------------------------------------------------------------------------

Intuition:

To find the minimum distance between two nodes a and b in a binary tree, we first need to find their lowest common ancestor (LCA).
Once we have the LCA, we calculate the distance from the LCA to each of the given nodes.
Finally, we add these distances to get the minimum distance between the nodes a and b.

Approach:

Finding the Lowest Common Ancestor (LCA):
We start from the root of the tree. If the root is NULL or if it matches either of the given nodes a or b, it's the LCA.
We recursively search for the LCA in the left and right subtrees.
If both left and right subtrees return non-NULL values (i.e., the given nodes a and b are found
 in different subtrees of the current root), then the current root is the LCA.
If only one subtree returns a non-NULL value, then the LCA is in that subtree.
If both subtrees return NULL, then the LCA doesn't exist.

Calculating Distance from a Node to a Target:
We recursively traverse the tree to find the target node.
At each step, we keep track of the distance from the current node to the target.
If the current node is the target node, we return the distance.
If the target node is not found in the left subtree, we search in the right subtree and vice versa.
If the target node is not found in either subtree, we return -1 indicating that the target node is not present.

Finding the Minimum Distance:
After finding the LCA, we calculate the distance from the LCA to each of the given nodes using the findDistance function.
Once we have the distances d1 and d2, we return their sum as the minimum distance between the nodes a and b.

Code Explanation:
The LCA function finds the lowest common ancestor of two nodes a and b using recursion.
The findDistance function calculates the distance from a given node to a target node.
Finally, the findDist function combines these steps to find the minimum distance between the nodes a and b.

*/

class Solution {
public:
    Node* LCA(Node* root, int a, int b) {
        if (!root) return NULL;

        if (root->data == a || root->data == b) return root;

        Node* left = LCA(root->left, a, b);
        Node* right = LCA(root->right, a, b);

        if (left != NULL && right != NULL) return root;

        if (!left && !right) return NULL;

        if (!left) return right;
        return left;
    }

    int findDistance(Node* root, int node, int dist) {
        if (!root) return -1;

        if (root->data == node) return dist;

        int left = findDistance(root->left, node, dist + 1);
        if (left != -1) return left;

        return findDistance(root->right, node, dist + 1);
    }

    int findDist(Node* root, int a, int b) {
        Node* lca = LCA(root, a, b);
        int d1 = findDistance(lca, a, 0);
        int d2 = findDistance(lca, b, 0);

        return d1 + d2;
    }
};