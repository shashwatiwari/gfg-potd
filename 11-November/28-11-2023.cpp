/*

Author : Shashvat Tiwari
Date : 28/11/2023
Problem : Sum of Dependencies in a graph
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/sum-of-dependencies-in-a-graph5311/1
Video Solution : NA

*/

class Solution
{
public:
    int sumOfDependencies(vector<int> adj[], int V)
    {
        int sum = 0;
        for (int i = 0; i < V; ++i)
        {
            sum += adj[i].size();
        }
        return sum;
    }
};