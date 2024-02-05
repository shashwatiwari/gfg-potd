/*

Author : Shashvat Tiwari
Date : 17/10/2023
Problem : Transitive closure of a Graph
Difficulty : Medium
Problem Link :https : https://practice.geeksforgeeks.org/problems/transitive-closure-of-a-graph0930/1
Video Solution : NA

*/

class Solution
{
public:
    vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph)
    {
        for (int k = 0; k < N; k++)
        {
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if ((graph[i][k] && graph[k][j]) or i == j)
                        graph[i][j] = 1;
                }
            }
        }
        return graph;
    }
};