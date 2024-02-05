/*

Author : Shashvat Tiwari
Date : 10/10/2023
Problem : Nodes at given distance in binary tree
Difficulty : Hard
Problem Link :https : // practice.geeksforgeeks.org/problems/nodes-at-given-distance-in-binary-tree/1
Video Solution : NA

*/

class Solution
{
private:
    void printSubTreeNode(Node *root, int k, vector<int> &ans)
    {
        if (root == NULL || k < 0)
            return;
        if (k == 0)
        {
            ans.push_back(root->data);
            return;
        }
        printSubTreeNode(root->left, k - 1, ans);
        printSubTreeNode(root->right, k - 1, ans);
    }

public:
    vector<int> KDistanceNodes(Node *root, int target, int k)
    {
        vector<int> ans;
        KDistanceNodesHelper(root, target, k, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }

    int KDistanceNodesHelper(Node *root, int target, int k, vector<int> &ans)
    {
        if (root == NULL)
            return -1;

        if (root->data == target)
        {
            printSubTreeNode(root, k, ans);
            return 0;
        }
        int dl = KDistanceNodesHelper(root->left, target, k, ans);
        if (dl != -1)
        {
            if (dl + 1 == k)
                ans.push_back(root->data);
            else
                printSubTreeNode(root->right, k - dl - 2, ans);
            return 1 + dl;
        }
        int dr = KDistanceNodesHelper(root->right, target, k, ans);
        if (dr != -1)
        {
            if (dr + 1 == k)
                ans.push_back(root->data);
            else
                printSubTreeNode(root->left, k - dr - 2, ans);
            return 1 + dr;
        }
        return -1;
    }
};
