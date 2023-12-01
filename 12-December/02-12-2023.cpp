/*

Author : Shashvat Tiwari
Date : 01/12/2023
Problem : Check whether BST contains dead end
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1
Video Solution : NA

*/

class Solution
{
public:
    int isRepresentingBST(int arr[], int N)
    {
        int prev = INT_MIN;
        for (int i = 0; i < N; i++)
        {
            if (arr[i] <= prev)
                return false;
            prev = arr[i];
        }
        return true;
        // code here
    }
};