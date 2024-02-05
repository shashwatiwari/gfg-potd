/*

Author : Shashvat Tiwari
Date : 16/11/2023
Problem : Find The String
Difficulty : Hard
Problem Link : https://www.geeksforgeeks.org/problems/find-the-string/1
Video Solution : NA

*/

/*

### Approach:
1. **Depth-First Search (DFS):**
    - The solution employs a depth-first search to generate strings.
    - `dfs` function recursively explores all possible combinations of strings of size `N` using characters from `0` to `K-1`.
    - It appends characters to the current string (`prev`) and keeps track of visited strings in a set (`set`).
    - If a new string is found (not in the set), it is added to the set and the recursive DFS continues.
    - During the DFS, the function appends characters to the result string (`ans`) as it explores the possibilities.

2. **Finding Minimum String:**
    - The `findString` function initiates the DFS by passing the initial prefix string (`s` initialized with `N-1` zeros), an empty set, and an empty result string (`ans`).
    - After the DFS completes, the `s` is appended to the `ans` string to ensure it contains all substrings of size `N`.
    - The resulting `ans` string is returned as the minimum string that contains all possible substrings of size `N`.

### Intuition:
- The problem involves generating all possible strings of size `N` using characters from `0` to `K-1` and constructing a minimum length string that includes all these substrings.
- The DFS algorithm explores the search space by generating all possible strings of length `N` and ensuring that each possible substring is included in the final result.
- By constructing strings recursively and checking for uniqueness using a set, the algorithm ensures that it covers all possible combinations while maintaining a minimum length string.

The time complexity of this approach is approximately O(KNlogK) due to the recursive DFS and insertion into the set, and the space complexity is O(KNN) due to storing all possible strings in the set and recursive stack space for DFS.

This algorithm efficiently solves the problem by exhaustively exploring all possible string combinations and constructing the minimum length string satisfying the given condition.

*/

class Solution
{
public:
    void dfs(int k, string prev, unordered_set<string> &set, string &ans)
    {
        for (int i = 0; i < k; i++)
        {
            string curr = prev + to_string(i);

            if (set.find(curr) == set.end())
            {
                set.insert(curr);
                dfs(k, curr.substr(1), set, ans);
                ans.push_back(i + '0');
            }
        }
    }
    string findString(int n, int k)
    {
        string s(n - 1, '0');
        string ans;
        unordered_set<string> set;
        dfs(k, s, set, ans);
        ans += s;
        return ans;
    }
};