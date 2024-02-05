/*

Author : Shashvat Tiwari
Date : 30/09/2023
Problem : Boolean Matrix
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/boolean-matrix-problem-1587115620/1
Video Solution : NA

*/

class Solution
{
public:
    void booleanMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        // Use the first row and first column to store information about row and column flips
        bool firstRowHasOne = false;
        bool firstColHasOne = false;

        // Check if the first row needs to be flipped
        for (int j = 0; j < n; ++j)
        {
            if (matrix[0][j] == 1)
            {
                firstRowHasOne = true;
                break;
            }
        }

        // Check if the first column needs to be flipped
        for (int i = 0; i < m; ++i)
        {
            if (matrix[i][0] == 1)
            {
                firstColHasOne = true;
                break;
            }
        }

        // Use the first row and first column to mark rows and columns to be flipped
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (matrix[i][j] == 1)
                {
                    matrix[i][0] = 1; // Mark the first column
                    matrix[0][j] = 1; // Mark the first row
                }
            }
        }

        // Flip rows based on first column
        for (int i = 1; i < m; ++i)
        {
            if (matrix[i][0] == 1)
            {
                for (int j = 1; j < n; ++j)
                {
                    matrix[i][j] = 1;
                }
            }
        }

        // Flip columns based on first row
        for (int j = 1; j < n; ++j)
        {
            if (matrix[0][j] == 1)
            {
                for (int i = 1; i < m; ++i)
                {
                    matrix[i][j] = 1;
                }
            }
        }

        // Flip the first row if necessary
        if (firstRowHasOne)
        {
            for (int j = 0; j < n; ++j)
            {
                matrix[0][j] = 1;
            }
        }

        // Flip the first column if necessary
        if (firstColHasOne)
        {
            for (int i = 0; i < m; ++i)
            {
                matrix[i][0] = 1;
            }
        }
    }
};
