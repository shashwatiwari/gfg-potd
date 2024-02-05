/*

Author : Shashvat Tiwari
Date : 27/09/2023
Problem : Find the closest pair from two arrays
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/find-the-closest-pair-from-two-arrays4215/1
Video Solution : NA

*/

class Solution
{
public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x)
    {
        int best = 1e7;
        int l = 0, r = 0;
        int i = 0, j = m - 1;

        while (i < n and j > -1)
        {
            if (abs(arr[i] + brr[j] - x) < best)
            {
                best = abs(arr[i] + brr[j] - x);
                l = arr[i];
                r = brr[j];
            }

            if (arr[i] + brr[j] > x)
                --j;
            else
                ++i;
        }

        return {l, r};
    }
};
