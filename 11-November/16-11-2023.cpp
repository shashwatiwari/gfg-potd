/*

Author : Shashvat Tiwari
Date : 16/11/2023
Problem : Find The String
Difficulty : Hard
Problem Link : https://www.geeksforgeeks.org/problems/find-the-string/1
Video Solution : NA

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