/*

Author : Shashvat Tiwari
Date : 16/10/2023
Problem : Making A Large Island
Difficulty : Hard
Problem Link :https : https://practice.geeksforgeeks.org/problems/making-a-large-island/1
Video Solution : NA

*/

class Solution
{
public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int maxIslandSize = 0;
        int islandId = 2; // Unique identifier for islands, starting from 2.

        // Assign each island a unique id and count their sizes.
        unordered_map<int, int> islandSizes; // Island id -> size
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    int size = dfs(grid, i, j, islandId);
                    islandSizes[islandId] = size;
                    maxIslandSize = max(maxIslandSize, size);
                    islandId++;
                }
            }
        }

        // Try changing each 0 to 1 and calculate the maximum island size.
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    unordered_set<int> neighborIslands;
                    for (auto &dir : directions)
                    {
                        int x = i + dir.first;
                        int y = j + dir.second;
                        if (x >= 0 && x < n && y >= 0 && y < n)
                        {
                            neighborIslands.insert(grid[x][y]);
                        }
                    }

                    int newSize = 1; // Change the 0 to 1.
                    for (int island : neighborIslands)
                    {
                        newSize += islandSizes[island];
                    }

                    maxIslandSize = max(maxIslandSize, newSize);
                }
            }
        }

        return maxIslandSize;
    }

private:
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int dfs(vector<vector<int>> &grid, int i, int j, int islandId)
    {
        int n = grid.size();
        if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] != 1)
        {
            return 0;
        }

        grid[i][j] = islandId;
        int size = 1;
        for (auto &dir : directions)
        {
            size += dfs(grid, i + dir.first, j + dir.second, islandId);
        }

        return size;
    }
};
