/*

Author : Shashvat Tiwari
Date : 02/03/2024
Problem : First Element to occur K times
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/first-element-to-occur-k-times5150/1
Video Solution : NA

*/

class Solution
{
public:
    int firstElementKTime(int n, int k, int a[])
    {
        vector<int> f(201, 0);
        for (int i = 0; i < n; i++)
        {
            f[a[i]]++;
            if (f[a[i]] == k)
                return a[i];
        }
        return -1;
    }
};