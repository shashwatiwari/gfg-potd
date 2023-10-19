/*

Author : Shashvat Tiwari
Date : 19/10/2023
Problem : Level of Nodes
Difficulty : Medium
Problem Link :https : https://practice.geeksforgeeks.org/problems/level-of-nodes-1587115620/1
Video Solution : NA

*/

int nodeLevel(int V, vector<int> adj[], int X)
{
    vector<bool> visited(V, false);
    vector<int> level(V, -1);

    // Starting from node 0
    int startNode = 0;
    level[startNode] = 0;
    visited[startNode] = true;

    queue<int> q;
    q.push(startNode);

    while (!q.empty())
    {
        int currentNode = q.front();
        q.pop();

        for (int neighbor : adj[currentNode])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                level[neighbor] = level[currentNode] + 1;
                q.push(neighbor);
            }
        }
    }

    if (level[X] == -1)
    {
        return -1; // Node X is not reachable from node 0
    }
    else
    {
        return level[X];
    }
}
