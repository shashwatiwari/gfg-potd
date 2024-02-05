/*

Author : Shashvat Tiwari
Date : 24/10/2023
Problem : Palindromic Partitioning
Difficulty : Hard
Problem Link :https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1
Video Solution : NA

*/

#include <iostream>
#include <vector>
#include <climits>

bool isPalindrome(const std::string &s, int start, int end)
{
    while (start < end)
    {
        if (s[start] != s[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int minCutForPalindromePartition(const std::string &str)
{
    int n = str.length();

    // Create a DP table to store the minimum cuts needed for palindrome partitioning
    std::vector<int> dp(n, 0);

    // Initialize dp[i] with the maximum possible cuts
    for (int i = 0; i < n; i++)
    {
        dp[i] = i;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            // If str[j..i] is a palindrome, update dp[i]
            if (isPalindrome(str, j, i))
            {
                dp[i] = (j == 0) ? 0 : std::min(dp[i], dp[j - 1] + 1);
            }
        }
    }

    // dp[n-1] will contain the minimum cuts needed for palindrome partitioning
    return dp[n - 1];
}

int main()
{
    std::string str1 = "ababbbabbababa";
    std::string str2 = "aaabba";

    int result1 = minCutForPalindromePartition(str1);
    int result2 = minCutForPalindromePartition(str2);

    std::cout << "Minimum cuts for palindrome partitioning in str1: " << result1 << std::endl;
    std::cout << "Minimum cuts for palindrome partitioning in str2: " << result2 << std::endl;

    return 0;
}
