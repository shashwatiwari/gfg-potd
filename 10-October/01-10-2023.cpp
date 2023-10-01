/*

Author : Shashvat Tiwari
Date : 01/10/2023
Problem : Boundary traversal of matrix
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/boundary-traversal-of-matrix-1587115620/1
Video Solution : NA

*/

class Solution
{
public:
    // Function to return list of integers that form the boundary
    // traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int>> &matrix, int n, int m)
    {
        vector<int> result;

        if (n == 1)
        {
            for (int i = 0; i < m; i++)
            {
                result.push_back(matrix[0][i]);
            }
        }
        else if (m == 1)
        {
            for (int i = 0; i < n; i++)
            {
                result.push_back(matrix[i][0]);
            }
        }
        else
        {
            for (int i = 0; i < m; i++)
            {
                result.push_back(matrix[0][i]);
            }
            for (int i = 1; i < n; i++)
            {
                result.push_back(matrix[i][m - 1]);
            }
            for (int i = m - 2; i >= 0; i--)
            {
                result.push_back(matrix[n - 1][i]);
            }
            for (int i = n - 2; i >= 1; i--)
            {
                result.push_back(matrix[i][0]);
            }
        }

        return result;
    }
};