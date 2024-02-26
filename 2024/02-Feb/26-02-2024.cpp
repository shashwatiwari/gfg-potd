/*

Author : Shashvat Tiwari
Date : 26/02/2024
Problem : Power Set
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/power-set4302/1
Video Solution : NA


--------------------------------------------------------------------------------------------


The code uses a recursive approach to generate all possible subsequences of the given string s. Here's a step-by-step explanation of the approach:

generateSubsequences Function:

This function recursively generates all subsequences of s.
It takes four arguments:
s: The input string.
index: The current index in the string.
current: The current subsequence being formed.
subsequences: A reference to a vector to store all generated subsequences.
If index reaches the end of the string s, the current subsequence current is added to subsequences if it's not empty.
Otherwise, for each character in s, two recursive calls are made:
One call excludes the current character by moving to the next index (index + 1) with the same current.
Another call includes the current character by appending it to current and then moving to the next index (index + 1).

allSubsequences Function:

This function is a wrapper around generateSubsequences.
It initializes an empty vector subsequences to store the generated subsequences.
After generating all subsequences, it sorts them lexicographically using std::sort.

Main Function:

The main function initializes the input string s.
It calls allSubsequences to generate and store all subsequences.
Finally, it prints the sorted subsequences.
This approach ensures that all possible subsequences of the input string s are generated and stored in lexicographically-sorted order.

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void generateSubsequences(string s, int index, string current, vector<string> &subsequences)
{
    if (index == s.length())
    {
        if (!current.empty())
        {
            subsequences.push_back(current);
        }
        return;
    }

    // Exclude current character
    generateSubsequences(s, index + 1, current, subsequences);

    // Include current character
    generateSubsequences(s, index + 1, current + s[index], subsequences);
}

vector<string> allSubsequences(string s)
{
    vector<string> subsequences;
    generateSubsequences(s, 0, "", subsequences);
    sort(subsequences.begin(), subsequences.end());
    return subsequences;
}

int main()
{
    string s = "abc";
    vector<string> subsequences = allSubsequences(s);

    for (const string &subsequence : subsequences)
    {
        cout << subsequence << " ";
    }
    cout << endl;

    return 0;
}
