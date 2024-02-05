/*

Author : Shashvat Tiwari
Date : 04/10/2023
Problem : Roman Number to Integer
Difficulty : Easy
Problem Link :https://practice.geeksforgeeks.org/problems/roman-number-to-integer3201/1
Video Solution : NA

*/

class Solution
{
public:
    int romanToDecimal(string &str)
    {
        int result = 0;
        unordered_map<char, int> m = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        for (int i = 0; i < str.length(); i++)
        {
            if (m[str[i]] < m[str[i + 1]])
            {
                result -= m[str[i]];
            }
            else
            {
                result += m[str[i]];
            }
        }
        return result;
        // code here
    }
};