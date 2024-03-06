/*

Author : Shashvat Tiwari
Date : 06/03/2024
Problem : Search Pattern (Rabin-Karp-Algorithm)
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/search-pattern-rabin-karp-algorithm--141631/1
Video Solution : NA

-------------------------------------------------------------------------------------


The Z algorithm is used for pattern matching within a string. It efficiently finds all occurrences of a pattern
string in a text string in linear time complexity, O(n + m), where n is the length of the text string and m is
the length of the pattern string. The basic idea behind the Z algorithm is to preprocess the pattern and text
strings to create a "Z array" that stores the length of the longest substring starting from each position that is also a prefix of the pattern string.

Here's how the algorithm works:

1. Concatenate the pattern string, a special character (not present in the pattern or text strings, such as '#'), and
the text string.

2. Initialize two pointers, l and r, such that l = r = 0, and an array Z of size equal to the concatenated string, initialized with zeros.

3. For each position i from 1 to the length of the concatenated string minus 1:

    a. If i > r, set l = r = i and compare characters starting from r to find the length of the common prefix. Increment
    r if a match is found.

    b. If i <= r, calculate k = i - l and check if Z[k] is less than r - i + 1. If it is, set Z[i] equal to Z[k]. Otherwise,
    set l = i and compare characters starting from r to find the length of the common prefix. Increment r if a match is found.

If the value of Z[i] is equal to the length of the pattern string, the pattern is found at index i - m - 1 in the concatenated
string, where m is the length of the pattern string.


*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> zAlgorithm(const string &text, const string &pattern)
{
    string concat = pattern + "#" + text;
    int n = concat.length();
    int m = pattern.length();
    vector<int> Z(n, 0);

    int l = 0, r = 0;
    for (int i = 1; i < n; i++)
    {
        if (i <= r)
        {
            Z[i] = min(r - i + 1, Z[i - l]);
        }
        while (i + Z[i] < n && concat[Z[i]] == concat[i + Z[i]])
        {
            Z[i]++;
        }
        if (i + Z[i] - 1 > r)
        {
            l = i;
            r = i + Z[i] - 1;
        }
    }

    vector<int> indexes;
    for (int i = m + 1; i < n; i++)
    {
        if (Z[i] == m)
        {
            indexes.push_back(i - m - 1);
        }
    }

    return indexes;
}

int main()
{
    string text = "geeksforgeeks";
    string pattern = "geek";
    vector<int> indexes = zAlgorithm(text, pattern);

    cout << "Pattern found at indexes: ";
    for (int index : indexes)
    {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}
