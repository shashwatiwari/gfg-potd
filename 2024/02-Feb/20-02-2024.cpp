/*

Author : Shashvat Tiwari
Date : 20/02/2024
Problem : Word Break
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/word-break1352/1
Video Solution : NA


--------------------------------------------------------------------------------------------

Approach:

- We can solve this problem using a recursive approach with backtracking.
- First, we create a helper function find which takes the input string s
 and a map m containing the dictionary words as keys and their frequencies as values.
- Inside the find function, we iterate over the characters of the input string s and
construct a substring check starting from the first character and expanding one character at a time.
- For each substring check, we check if it is present in the dictionary map m.
If it is present, we recursively call find on the remaining part of the
input string s (substring starting from the next character after check).
- If we are able to break down the entire input string s into dictionary
words using this recursive approach, we return true. Otherwise, we return false.

Explanation of the code:

- The wordBreak function initializes an unordered map m to store the frequencies of dictionary words.
- It then calls the find function with the input string A and the dictionary map m.
- Inside the find function, it iterates over the characters of the input string s and constructs a substring check.
- For each substring check, it checks if it is present in the dictionary map m. If it is present,
 it recursively calls find on the remaining part of the input string s.
- If the entire input string s is successfully broken down into dictionary words, the find
 function returns true, indicating that the input string A can be segmented into
  a space-separated sequence of dictionary words. Otherwise, it returns false.


*/

class Solution
{
public:
    bool find(string &s, unordered_map<string, int> &m)
    {
        if (s.size() == 0)
            return true;
        string check = "";
        for (int i = 0; i < s.size(); i++)
        {
            check += s[i];
            if (m[check] > 0)
            {
                string str = s.substr(i + 1);
                if (find(str, m))
                    return true;
            }
        }
        return false;
    }
    int wordBreak(string A, vector<string> &B)
    {
        unordered_map<string, int> m;
        for (auto i : B)
        {
            m[i]++;
        }
        return find(A, m);
    }
};