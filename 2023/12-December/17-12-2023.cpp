/*

Author : Shashvat Tiwari
Date : 17/12/2023
Problem : Max Sum Without Adjacents
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1
Video Solution : NA

*/

class Solution
{
public:
    int find(int *arr, int i, int n, vector<int> &dp)
    {
        if (i >= n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int ans;
        ans = arr[i] + find(arr, i + 2, n, dp);
        if (i + 1 < n)
            ans = max(ans, arr[i + 1] + find(arr, i + 3, n, dp));

        dp[i] = ans;
        return dp[i];
    }
    int findMaxSum(int *arr, int n)
    {
        vector<int> dp(n + 1, -1);
        return find(arr, 0, n, dp);
    }
};