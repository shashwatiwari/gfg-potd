/*

Author : Shashvat Tiwari
Date : 01/03/2024
Problem : Peak Element
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/peak-element/1
Video Solution : NA


--------------------------------------------------------------------------------------------

The given code is a simple solution to find a peak element in an array. A peak element is an
element that is greater than its neighbors. The approach used here is to iterate through the
array and check if the current element is less than the previous element. If it is, then
the previous element is a peak. If no such element is found, then the last element is a peak.

Approach:
- Start iterating from the second element to the last element of the array.

- Check if the current element is less than the previous element. If it is, return the index of the previous element as it is a peak.

- If no peak is found during the iteration, return the index of the last element as it is also a peak.

*/

class Solution
{
public:
    int peakElement(int arr[], int n)
    {
        for (int i = 1; i < n; i++)
        {
            if (arr[i] < arr[i - 1])
                return i - 1;
        }
        return n - 1;
    }
};
