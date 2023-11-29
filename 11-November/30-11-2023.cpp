/*

Author : Shashvat Tiwari
Date : 30/11/2023
Problem : Shortest Path from 1 to n
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/shortest-path-from-1-to-n0156/1
Video Solution : NA

*/

class Solution
{
public:
    int minimumStep(int n)
    {
        int steps = 0;
        while (n > 1)
        {
            if (n % 3 == 0)
            {
                n /= 3;
            }
            else
            {
                n--;
            }
            steps++;
        }
        return steps;
    }
};