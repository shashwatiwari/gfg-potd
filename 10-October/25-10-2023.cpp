/*

Author : Shashvat Tiwari
Date : 25/10/2023
Problem : Knapsack with Duplicate Items
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
Video Solution : NA

*/

class Solution
{
public:
    int find(int val[], int wt[], int W, int n, vector<vector<int>> &dp)
    {
        if (dp[n][W] != -1)
            return dp[n][W];
        int maxVal = 0;

        for (int i = 0; i < n; i++)
        {
            if (wt[i] <= W)
            {
                maxVal = max(maxVal, val[i] + find(val, wt, W - wt[i], n, dp));
            }
        }

        return dp[n][W] = maxVal;
    }

    // Function to return max value that can be put in a knapsack of capacity W.
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N + 1, vector<int>(W + 1, -1));

        for (int i = 0; i <= W; i++)
        {
            dp[0][i] = 0;
        }

        for (int i = 0; i <= N; i++)
        {
            dp[i][0] = 0;
        }

        return find(val, wt, W, N, dp);
    }
};
