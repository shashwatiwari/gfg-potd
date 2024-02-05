/*

Author : Shashvat Tiwari
Date : 23/10/2023
Problem : Maximum sum increasing subsequence
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1
Video Solution : NA

*/

#include <iostream>
#include <vector>

int maxIncreasingSubsequenceSum(std::vector<int> &arr)
{
    int n = arr.size();
    std::vector<int> dp(n);

    for (int i = 0; i < n; i++)
    {
        dp[i] = arr[i]; // Initialize dp[i] with the element itself

        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = std::max(dp[i], dp[j] + arr[i]);
            }
        }
    }

    // Find the maximum sum in dp array
    int maxSum = 0;
    for (int i = 0; i < n; i++)
    {
        maxSum = std::max(maxSum, dp[i]);
    }

    return maxSum;
}

int main()
{
    std::vector<int> arr = {1, 101, 2, 3, 100, 4, 5};
    int result = maxIncreasingSubsequenceSum(arr);
    std::cout << "Maximum Sum of Increasing Subsequence: " << result << std::endl;
    return 0;
}
