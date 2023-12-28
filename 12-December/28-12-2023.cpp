/*

Author : Shashvat Tiwari
Date : 28/12/2023
Problem : Wildcard String Matching
Difficulty : Hard
Problem Link : https://www.geeksforgeeks.org/problems/wildcard-string-matching1126/1
Video Solution : NA

*/

class Solution
{
public:
    bool match(string p, string s)
    {
        int i = 0, j = 0, star = -1, match = 0;
        while (j < s.size())
        {
            if (i < p.size() and (p[i] == s[j] || p[i] == '?'))
            {
                i++;
                j++;
            }
            else if (p[i] == '*')
            {
                if (i == p.size() - 1)
                {
                    return true;
                }
                else
                {
                    star = i;
                    match = j;
                    i++;
                }
            }
            else if (star != -1)
            {
                i = star + 1;
                match++;
                j = match;
            }
            else
            {
                return false;
            }
        }
        while (i < p.size() and p[i] == '*')
            i++;
        return i == p.size();
    }
};

/*

This code maintains two pointers, i for the pattern string p and j for the input string s. It also uses two variables, star and match, to keep track of the last encountered * character in the pattern and the position where the last match happened in the input string.

Loop through the input string s:

Check if the current characters in s and p match (p[i] == s[j]) or if p[i] is a question mark ('?'). If they match or if p[i] is a question mark, increment both i and j to move to the next characters in p and s.
If the current character in the pattern is '*':
If '*' is the last character in the pattern, return true because it matches any sequence.
Otherwise, store the current positions of i and j in star and match, respectively. Increment i to check for the next character in the pattern.
If the characters don't match, and there is no '*' to backtrack, return false.
After matching all characters in s, handle remaining '*' characters in the pattern:

If there are consecutive '*' at the end of the pattern, move i until you reach the end of the pattern.
Finally, check if you've reached the end of the pattern p. If i equals the size of the pattern string p, it means you've matched all characters in s according to the wildcard pattern.

The code ensures that for each '*' encountered in the pattern, it tries to match any sequence of characters in the input string. If a mismatch occurs, it backtracks to the last '*' encountered in the pattern and restarts the matching process.

-------------------------------------------------------------------------------------------

s = "aacdfb"
p = "aa*fb"

Start with i = 0 (for pattern p) and j = 0 (for string s).

Match the characters until a wildcard character ('*') is encountered in the pattern or until a mismatch occurs:

p[i] matches s[j] ('a' matches 'a'). Increment both i and j.
p[i] matches s[j] ('a' matches 'a'). Increment both i and j.
p[i] is a wildcard ('*'). Store star = i and match = j, and then increment i to move to the next character in p.
Continue matching from the stored position star and match:

Now, i = 2 and j = 2.
Check if p[i] matches s[j]. Since p[i] is a wildcard, we move only j to j = 3.
Continue matching from the stored position star and match:

Now, i = 2 and j = 3.
Check if p[i] matches s[j]. Since p[i] is a wildcard, we move only j to j = 4.
Continue matching from the stored position star and match:

Now, i = 2 and j = 4.
Check if p[i] matches s[j]. Since p[i] is a wildcard, we move only j to j = 5.
Continue matching from the stored position star and match:

Now, i = 2 and j = 5.
Check if p[i] matches s[j]. Since p[i] is 'f' and s[j] is 'b', there's a mismatch.
Since there's a mismatch and we had a wildcard ('*') earlier in the pattern, we go back to the last wildcard position:

star = 2 and match = 4.
Now, increment match by one (match++), so match = 5.
Continue matching from the stored position star and the updated match:

Now, i = 2 and j = 5.
Check if p[i] matches s[j]. Since p[i] is a wildcard, we move only j to j = 6.
Check if we have reached the end of the pattern:

i reaches the end of the pattern, and we've successfully matched all characters in s according to the wildcard pattern.
So, in this case, the wildcard pattern "aa*fb" matches the entire string "aacdfb".


*/