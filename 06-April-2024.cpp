/*

Author : Shashvat Tiwari
Date : 06/04/2024
Problem : Count ways to nth stair order does not matter
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter1322/1
Video Solution : NA


*/

class Solution
{
public:
    long long countWays(int n)
    {
        vector<long long> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++)
        {
            dp[i] = min(dp[i - 1], dp[i - 2]) + 1;
        }

        return dp[n];
    }
};