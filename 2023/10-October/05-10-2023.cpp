/*

Author : Shashvat Tiwari
Date : 05/10/2023
Problem : Count number of substrings
Difficulty : Medium
Problem Link :https://practice.geeksforgeeks.org/problems/count-number-of-substrings4528/1
Video Solution : NA

*/

class Solution
{
public:
    long long int substrCount(string s, int k)
    {
        int left = 0;         // Left pointer of the sliding window.
        int right = 0;        // Right pointer of the sliding window.
        vector<int> f(26, 0); // Array to store the frequency of each character (initialized to all zeros).
        int uniqueChar = 0;   // Count of unique characters in the current window.

        long long ans = 0; // Variable to store the final answer.

        long long extra = 0; // Extra substrings that can be formed within the same window.

        while (right < s.size())
        {
            // Check if the character at 'r' is not seen before in the current window.
            if (f[s[right] - 'a'] == 0)
                ++uniqueChar; // Increment the count of unique characters.

            ++f[s[right] - 'a']; // Increment the frequency of the character at 'r'.

            while (uniqueChar > k)
            {
                // If there are more than 'k' unique characters in the window, shrink it from the left.
                --f[s[left] - 'a']; // Decrement the frequency of the character at 'l'.
                if (f[s[left] - 'a'] == 0)
                    --uniqueChar; // If the frequency becomes zero, decrement the count of unique characters.

                ++left;    // Move the left pointer to the right.
                extra = 0; // Reset the extra count to zero.
            }

            if (uniqueChar == k)
            {
                // If there are exactly 'k' unique characters in the window, count substrings.
                while (f[s[left] - 'a'] > 1)
                {
                    ++extra;            // Count the extra substrings that can be formed.
                    --f[s[left] - 'a']; // Decrement the frequency of the character at 'l'.
                    ++left;             // Move the left pointer to the right.
                }

                ans += extra + 1; // Add the extra substrings and the current substring to the answer.
            }

            ++right; // Move the right pointer to the right.
        }

        return ans; // Return the final count of substrings with 'k' distinct characters.
    }
};
