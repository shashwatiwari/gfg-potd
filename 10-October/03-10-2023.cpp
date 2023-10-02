/*

Author : Shashvat Tiwari
Date : 03/10/2023
Problem : Column name from a given column number
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/column-name-from-a-given-column-number4244/1
Video Solution : NA

*/

class Solution
{
public:
    string colName(long long int n)
    {
        string result = "";
        while (n > 0)
        {
            n--;
            int remainder = n % 26;
            char letter = 'A' + remainder;
            result = letter + result;
            n /= 26;
        }
        return result;
        // your code here
    }
};