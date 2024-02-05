/*

Author : Shashvat Tiwari
Date : 02/10/2023
Problem : Number of distinct subsequences
Difficulty : Hard
Problem Link : https://practice.geeksforgeeks.org/problems/number-of-distinct-subsequences0909/1
Video Solution : NA

*/

class Solution
{
public:
    int mod = 1e9 + 7;

    int distinctSubsequences(string s)
    {
        int n = s.size(); // Length of the input string

        // Create an array to store the last occurrence position of each character (a-z)
        vector<int> lastOccurrence(26, -1);

        // Create an array to store the count of distinct subsequences up to position i
        long long distinctSubsequencesCount[n + 1];

        // Initialize the count for an empty subsequence
        distinctSubsequencesCount[0] = 1;

        const int mod = 1000000007; // Modulo value

        for (int i = 1; i <= n; i++)
        {
            // Calculate the count of distinct subsequences up to position i by doubling the previous count
            distinctSubsequencesCount[i] = (distinctSubsequencesCount[i - 1] * 2) % mod;

            // Find the last occurrence position of the current character in the input string
            int lastPos = lastOccurrence[s[i - 1] - 'a'];

            // If the current character has occurred before, subtract the count of subsequences
            // that end with the last occurrence of this character
            if (lastPos != -1)
            {
                distinctSubsequencesCount[i] = (distinctSubsequencesCount[i] - distinctSubsequencesCount[lastPos] + mod) % mod;
            }

            // Store the current position as the last occurrence of the current character
            lastOccurrence[s[i - 1] - 'a'] = i - 1;
        }

        // Return the count of distinct subsequences for the entire input string
        return static_cast<int>(distinctSubsequencesCount[n]);
    }
};
