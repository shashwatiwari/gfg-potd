/*

Author : Shashvat Tiwari
Date : 27/11/2023
Problem : Detect Cycle Using DSU
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/detect-cycle-using-dsu/1
Video Solution : NA

------------------------------------------------------------------------------------

Intuition:

 -  The find_set() function utilizes path compression to find the representative
    (root) of the set that an element belongs to. It recursively traverses
    the parent pointers until it finds the root.

 -  union_sets() function merges two sets based on their representatives
    (roots) by rank optimization to maintain balance and reduce the tree depth.

 -  The detectCycle() function initializes disjoint sets for each vertex.
    It iterates through each edge in the graph, and for each edge,
    it checks if the two vertices are in the same set. If they are, it means there's a cycle.

 -  To avoid processing duplicate edges (since the graph is undirected),
    an unordered set s of pairs of vertices (u, v) is used to keep track of processed edges.

Approach:

    Initialize parent array for each vertex indicating its own set and rank array to
    maintain the height of each set (initialized as 1).

    Iterate through each vertex and its adjacent vertices in the adjacency list.

    Check if the edge (u, v) has been processed before by checking if
    {u, v} or {v, u} exists in the set s.

    If the edge hasn't been processed, find the representatives of sets
    for vertices u and v using find_set() and check if they are the same.
    If they are, a cycle exists, return 1.

    Otherwise, merge the sets using union_sets().

--------------------------------------------------------------------------------------------  */

class Solution
{
public:
    int find_set(int v, vector<int> &parent)
    {
        if (v != parent[v])
        {
            v = find_set(parent[v], parent);
        }
        return v;
    }

    void union_sets(int x, int y, vector<int> &parent, vector<int> &rank)
    {
        x = find_set(x, parent);
        y = find_set(y, parent);
        if (rank[x] < rank[y])
        {
            swap(x, y);
        }
        parent[y] = x;
        rank[x] += rank[y];
    }

    int detectCycle(int V, vector<int> adj[])
    {
        vector<int> parent(V);
        vector<int> rank(V, 1);
        unordered_set<pair<int, int>, PairHash> s;

        for (int i = 0; i < V; i++)
        {
            parent[i] = i;
        }

        for (int u = 0; u < V; u++)
        {
            for (int j = 0; j < adj[u].size(); j++)
            {
                int v = adj[u][j];
                if (s.count({u, v}) || s.count({v, u}))
                {
                    continue;
                }
                s.insert({u, v});
                int x = find_set(u, parent);
                int y = find_set(v, parent);
                if (x == y)
                {
                    return 1;
                }
                union_sets(x, y, parent, rank);
            }
        }

        return 0;
    }

private:
    struct PairHash
    {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2> &p) const
        {
            auto h1 = hash<T1>{}(p.first);
            auto h2 = hash<T2>{}(p.second);
            return h1 ^ h2;
        }
    };
};

/*----------------------------------------------------------------------------------------

Code Explanation:

 -  find_set() and union_sets() implement standard disjoint set operations (path
    compression and union by rank) for finding sets and merging sets.

 -  detectCycle() iterates through the adjacency list, processes each edge,
    and checks for a cycle using disjoint set operations.
    It returns 1 if a cycle is found, 0 otherwise.

 -  The code keeps track of processed edges in the set s to avoid duplicate
    processing of edges and efficiently detects cycles in the undirected graph using DSU.

*/
