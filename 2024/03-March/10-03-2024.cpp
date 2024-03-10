/*

Author : Shashvat Tiwari
Date : 10/03/2024
Problem : Remove all Duplicates from a given string
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/remove-all-duplicates-from-a-given-string4321/1
Video Solution : NA

-------------------------------------------------------------------------------------


1. unordered_map<char, int> f;: This line declares an unordered map f where the key is a character (char) and
the value is an integer (int). This map is used to store the last occurrence index of each character in the input string s.

2. int n = s.size();: This line calculates the size of the input string s and stores it in the variable n.

3. for (int i = 0; i < n; i++) { ... }: This for loop iterates over each character in the input string s.

4. if (f.find(s[i]) == f.end()) { f[s[i]] = i; }: For each character s[i], this line checks if the character is
already present in the map f. If it is not present (f.find(s[i]) == f.end()), it adds the character to the map
with its index i as the value (f[s[i]] = i). This ensures that f contains the index of the first occurrence of each character in s.

5. The second for loop for (int i = n - 1; i >= 0; i--) { ... } iterates over each character in the input string
s in reverse order (from the last character to the first).

if (f.find(s[i]) != f.end()) { ... }: For each character s[i], this line checks if the character is present in the map f. If it is present (f.find(s[i]) != f.end()), it means that this character has a duplicate later in the string.

if (f[s[i]] < i) { s.erase(s.begin() + i); }: If the first occurrence index of the character s[i] (f[s[i]]) is
less than the current index i, it means that there is a duplicate of s[i] later in the string. In this case, the
current character at index i is removed from the string s using s.erase(s.begin() + i).

6. Finally, the function returns the modified string s with all duplicate characters removed, keeping only the last occurrence of each character.

*/

class Solution
{
public:
    string removeDuplicates(string s)
    {
        unordered_map<char, int> f;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (f.find(s[i]) == f.end())
            {
                f[s[i]] = i;
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (f.find(s[i]) != f.end())
            {
                if (f[s[i]] < i)
                {
                    s.erase(s.begin() + i);
                }
            }
        }

        return s;
    }
};