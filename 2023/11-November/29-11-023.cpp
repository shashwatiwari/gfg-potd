/*

Author : Shashvat Tiwari
Date : 29/11/2023
Problem : Euler Ciruit and Path
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/euler-circuit-and-path/1
Video Solution : NA

----------------------------------------------------------------------------------

Approach and Intuition:

The problem involves determining whether the given undirected acyclic
graph contains an Eulerian circuit, an Eulerian path, or neither.
To solve this problem efficiently, we can use the following approach:


Eulerian Circuit and Eulerian Path Conditions:

- An undirected graph has an Eulerian circuit if all its vertices have
even degrees (i.e., the number of edges incident on each vertex is even).

- An undirected graph has an Eulerian path if it has exactly two vertices
with odd degrees and all other vertices have even degrees.

- If there are more than two vertices with odd degrees or any vertex
with an odd degree is absent, the graph does not contain an Eulerian path or circuit.


Algorithm Steps:

- Calculate the degree of each vertex in the graph.
- Count the number of vertices with odd degrees.
- Based on the count of vertices with odd degrees, determine
whether the graph has an Eulerian circuit, an Eulerian path, or neither.


Code Explanation:

DFS Function (dfs):
- Performs Depth-First Search traversal to mark visited nodes in the graph.
isEulerCircuit Function:

- Takes the number of vertices (V) and the adjacency list (adj) as input.

- Initializes a visited array to mark visited nodes and oddDegreeCount
to count vertices with odd degrees.

- Calculates the degree of each vertex by checking the size of its adjacency list.

- Increments oddDegreeCount for each vertex with an odd degree.

- Based on the count of odd-degree vertices, returns:
2 if there are no vertices with odd degrees (Eulerian Circuit)
1 if there are exactly two vertices with odd degrees (Eulerian Path)
0 if the conditions for Eulerian circuit or path are not met.

-----------------------------------------------------------------------
*/

class Solution
{
public:
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited)
    {
        visited[node] = true;
        for (int i = 0; i < adj[node].size(); ++i)
        {
            int next = adj[node][i];
            if (!visited[next])
            {
                dfs(next, adj, visited);
            }
        }
    }

    int isEulerCircuit(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        int oddDegreeCount = 0;

        for (int i = 0; i < V; ++i)
        {
            if (adj[i].size() % 2 != 0)
            {
                oddDegreeCount++;
            }
        }

        if (oddDegreeCount == 0)
        {
            return 2;
        }
        else if (oddDegreeCount == 2)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};