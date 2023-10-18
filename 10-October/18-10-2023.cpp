/*

Author : Shashvat Tiwari
Date : 18/10/2023
Problem : Eventual Safe States
Difficulty : Medium
Problem Link :https : https://practice.geeksforgeeks.org/problems/eventual-safe-states/1
Video Solution : NA

*/

class Solution
{
public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        vector<int> result;
        vector<int> visited(V, 0); // 0 - unvisited, 1 - visiting, 2 - visited (safe)

        for (int i = 0; i < V; i++)

        {
            if (isSafe(i, adj, visited))
            {
                result.push_back(i);
            }
        }

        sort(result.begin(), result.end());
        return result;
    }

private:
    bool isSafe(int node, vector<int> adj[], vector<int> &visited)
    {
        if (visited[node] == 1)
        {
            return false;
        }
        if (visited[node] == 2)
        {
            return true;
        }

        visited[node] = 1; // Mark the node as visiting

        for (int neighbor : adj[node])
        {
            if (!isSafe(neighbor, adj, visited))
            {
                return false;
            }
        }

        visited[node] = 2; // Mark the node as visited (safe)
        return true;
    }
};
