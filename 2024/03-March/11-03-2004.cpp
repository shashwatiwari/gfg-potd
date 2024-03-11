/*

Author : Shashvat Tiwari
Date : 11/03/2024
Problem : Count Pairs sum in matrices
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/count-pairs-sum-in-matrices4332/1
Video Solution : NA

-------------------------------------------------------------------------------------


1. The code initializes the pointers r1, c1, r2, and c2 and a count variable to 0.

2. It then enters a while loop that continues until r1 is less than n and r2 is greater than or equal to 0.

3. Inside the loop, it calculates the sum of elements at the current positions and checks if it equals x.
If it does, it increments count and adjusts the pointers c1 and c2.

4. If the sum is less than x, it increments c1 to move to a larger element in mat1.

5. If the sum is greater than x, it decrements c2 to move to a smaller element in mat2.

6. When c1 reaches the end of a row in mat1, increment r1 and reset c1 to 0 to move to the next row.

7. When c2 reaches the beginning of a row in mat2, decrement r2 and reset c2 to n-1 to move to the previous row.

8. Finally, the code returns the 'count' of pairs found whose sum equals x.

*/

class Solution
{
public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
    {
        int r1 = 0, c1 = 0, r2 = n - 1, c2 = n - 1;
        int count = 0;

        while (r1 < n && r2 >= 0)
        {
            int sum = mat1[r1][c1] + mat2[r2][c2];
            if (sum == x)
            {
                ++count;
                ++c1;
                --c2;
            }
            else if (sum < x)
                ++c1;
            else
                --c2;
            if (c1 == n)
            {
                r1++;
                c1 = 0;
            }
            if (c2 == -1)
            {
                r2--;
                c2 = n - 1;
            }
        }
        return count;
    }
};