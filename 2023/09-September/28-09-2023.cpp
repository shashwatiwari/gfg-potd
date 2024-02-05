/*

Author : Shashvat Tiwari
Date : 28/09/2023
Problem : Wave Array
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/wave-array-1587115621/1
Video Solution : NA

*/

class Solution
{
public:
    // arr: input array
    // n: size of array
    // Function to sort the array into a wave-like array.
    void convertToWave(int n, vector<int> &arr)
    {
        for (int i = 0; i < n; i += 2)
        {
            if (i + 1 <= n - 1)
            {
                swap(arr[i], arr[i + 1]);
            }
        }
        // Your code here
    }
};