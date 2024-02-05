/*

Author : Shashvat Tiwari
Date : 29/09/2023
Problem : Number Of Enclaves
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/number-of-enclaves/1
Video Solution : NA

*/

// Approach:

//     1. The code defines a dfs function that performs a depth-first search to mark land cells as visited (set to 0) and explores adjacent land cells.
//     2. The main function numberOfEnclaves iterates through the boundary cells (first row, last row, first column, last column) and calls dfs for each land cell found on the boundary. This is done to mark all land cells connected to the boundary as visited.
//     3. After marking land cells connected to the boundary, it iterates through the entire grid to count the remaining unvisited land cells, which are the ones that cannot be walked off the boundary.

class Solution
{
public:
    void dfs(vector<vector<int>> &grid, int i, int j, int n, int m)
    {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0)
            return;

        grid[i][j] = 0;

        dfs(grid, i + 1, j, n, m);
        dfs(grid, i - 1, j, n, m);
        dfs(grid, i, j + 1, n, m);
        dfs(grid, i, j - 1, n, m);
    }
    int numberOfEnclaves(vector<vector<int>> &grid)
    {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[0][j] == 1)
                    dfs(grid, 0, j, n, m);
                if (grid[n - 1][j] == 1)
                    dfs(grid, n - 1, j, n, m);
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][0] == 1)
                    dfs(grid, i, 0, n, m);
                if (grid[i][m - 1] == 1)
                    dfs(grid, i, m - 1, n, m);
            }
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == 1)
                    count++;
            }
        }

        return count;
        // Code here
    }