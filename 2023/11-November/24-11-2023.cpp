/*

Author : Shashvat Tiwari
Date : 24/11/2023
Problem : Nth Row of Pascal Triangle
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/pascal-triangle0652/1
Video Solution : NA

### Intuition:
Pascal's Triangle is a triangular array of binomial coefficients. Each number
in the triangle is the sum of the two directly above it in the previous row.
The first and last elements in each row are always 1.

### Approach:

1. **Initialization:**
   - Initialize a 2D vector `v` to store the Pascal's Triangle rows.
   - Start with `v[0]` as the first row containing the value 1.

2. **Generating Rows:**
   - Iterate from `i = 1` to `n` (the desired row number).
   - For each row `i`:
     - Push 1 as the first element of the row (`v[i].push_back(1)`).
     - Calculate the values between the first and last elements:
       - Iterate from `j = 1` to `i - 1` (excluding the first and last elements).
       - Calculate each element as the sum of the elements directly above it in
       the previous row: `v[i - 1][j - 1] + v[i - 1][j]`.
       - Push this calculated value to the current row.

3. **Adding Last Element:**
   - After the inner loop for each row, push 1 as the last element of the row (`v[i].push_back(1)`).

4. **Return Result:**
   - Return the generated row `v[n]` as the nth row of Pascal's Triangle.

### Key Points:
- The loop generates each row by calculating elements based on the previous row's values.
- The first and last elements of each row are always 1.
- The modulo operation is applied during the calculation of elements to
 prevent integer overflow (`% mod`).

This approach ensures the accurate generation of the nth row of Pascal's Triangle
 by following the pattern and properties of Pascal's Triangle.

 */

class Solution
{
public:
    vector<long long> nthRowOfPascalTriangle(int n)
    {
        long long mod = 1000000007;
        vector<vector<long long>> v(n + 1);
        v[0].push_back(1);
        for (int i = 1; i <= n; i++)
        {
            v[i].push_back(1);
            for (int j = 1; j < i; j++)
            {
                long long val = (v[i - 1][j - 1] + v[i - 1][j]) % mod;
                v[i].push_back(val);
            }
            v[i].push_back(1);
        }
        return v[n - 1];
    }
};