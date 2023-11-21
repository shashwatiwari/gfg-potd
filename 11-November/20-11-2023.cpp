/*

Author : Shashvat Tiwari
Date : 20/11/2023
Problem : K Sum Paths
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/k-sum-paths/1
Video Solution : NA

*/

class Solution
{
public:
    int count_paths = 0;

    void dfs(Node *root, int target, unordered_map<int, int> &path_sum, int curr_sum)
    {
        if (!root)
            return;

        curr_sum += root->data;

        // Check if current_sum equals target
        if (curr_sum == target)
            count_paths++;

        // If (curr_sum - target) exists in the map, increment count_paths
        if (path_sum.find(curr_sum - target) != path_sum.end())
            count_paths += path_sum[curr_sum - target];

        // Increment the count of current sum in the hashmap
        path_sum[curr_sum]++;

        // DFS for left and right subtrees
        dfs(root->left, target, path_sum, curr_sum);
        dfs(root->right, target, path_sum, curr_sum);

        // Decrement the count of current sum after the subtree traversal
        path_sum[curr_sum]--;
    }

    int sumK(Node *root, int k)
    {
        unordered_map<int, int> path_sum;
        int curr_sum = 0;
        dfs(root, k, path_sum, curr_sum);
        return count_paths;
    }
};
