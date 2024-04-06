/*

Author : Shashvat Tiwari
Date : 04/04/2024
Problem : Sum of all substrings of a number
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/sum-of-all-substrings-of-a-number-1587115621/1
Video Solution : NA

==============================================================================================

To solve this problem efficiently, we can use the concept of digit manipulation. For each digit in the string,
we calculate its contribution to the sum of all substrings. Let's say the current digit is d at position i (0-based indexing),
then its contribution to the sum of all substrings is d * (i+1) * (n-i), where n is the length of the string.

The total sum of all substrings is the sum of contributions of all digits in the string.

The contribution of a digit d at index i to the sum of all substrings can be understood as follows:
- The digit d contributes to all substrings that start from its position i and end at any position
  to the right of i. There are (n - i) such substrings.

- Each of these substrings has a length from 1 to n - i, and the digit d appears at the ones, tens, hundreds, etc.,
  places in these substrings. So, the total contribution of d at index i is the sum of d appearing at each place
  multiplied by the number of times it appears at that place in all substrings.

- If we consider the digit d at index i, its contribution to the sum of all substrings is:
    For the ones place: d * (n - i)
    For the tens place: d * (n - i - 1)
    For the hundreds place: d * (n - i - 2)
    ...
    For the nth place: d * 1

- Summing these contributions gives us the total contribution of d at index i to the sum of all substrings,
  which is d * (n - i) + d * (n - i - 1) + ... + d * 1 = d * (i + 1) * (n - i).

 */

#include <iostream>
#include <string>
using namespace std;

int sumSubstrings(string s)
{
    int MOD = 1000000007;
    long long result = 0;
    long long current = 0;

    for (int i = 0; i < s.length(); i++)
    {
        current = (current * 10 + (i + 1) * (s[i] - '0')) % MOD;
        result = (result + current) % MOD;
    }

    return result;
}

int main()
{
    string s1 = "1234";
    cout << sumSubstrings(s1) << endl; // Output: 1670

    string s2 = "421";
    cout << sumSubstrings(s2) << endl; // Output: 491

    return 0;
}
