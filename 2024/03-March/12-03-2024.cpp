/*

Author : Shashvat Tiwari
Date : 12/03/2024
Problem : Generalised fibonacci numbers
Difficulty : Hard
Problem Link : https://www.geeksforgeeks.org/problems/generalised-fibonacci-numbers1820/1
Video Solution : NA

-------------------------------------------------------------------------------------

Matrix Multiplication Function:
vector<vector<ll>> multiply(vector<vector<ll>>& A, vector<vector<ll>>& B, ll m)

This function takes two square matrices A and B along with an integer m as input. It computes the matrix product
A * B and returns the result modulo m. The function uses three nested loops to iterate over the rows and columns
of the matrices and calculates the product element-wise, taking care to apply the modulo operation at each step to avoid overflow.

Generalized Fibonacci Function:

ll genFibNum(ll a, ll b, ll c, ll n, ll m)
This function computes the n-th term of the generalized Fibonacci sequence defined by the recurrence relation:

g(1) = 1, g(2) = 1
g(n) = a*g(n-1) + b*g(n-2) + c
The function uses a matrix exponentiation approach to efficiently calculate g(n).

1. First, it initializes a 3x3 matrix mat with values {{a, b, 1}, {1, 0, 0}, {0, 0, 1}}. This matrix represents
the coefficients of the recurrence relation in the form of a matrix.

2. It then initializes a 3x3 identity matrix res to keep track of the result of the matrix exponentiation.

3. It reduces n by 2 (since we know g(1) and g(2) are 1) and enters a while loop.

4. In each iteration of the loop, if the current bit of n is set, it multiplies res by mat and assigns the result back to res.

5. It then squares the matrix mat (equivalent to mat * mat) and updates mat with the squared result.

6. Finally, it right-shifts n by 1 to prepare for the next iteration of the loop.

7. After the loop completes, the function returns (res[0][0] + res[0][1] + c * res[0][2]) % m, which represents
the n-th term of the generalized Fibonacci sequence modulo m.

Overall Approach
The code uses matrix exponentiation to efficiently compute g(n) in O(log n) time complexity, making it suitable
for large values of n. By representing the coefficients of the recurrence relation as a matrix and using exponentiation
by squaring, the function avoids the need for recursion and repeated calculations, leading to a more efficient solution.

*/

#define ll long long
class Solution
{
public:
    vector<vector<ll>> multiply(vector<vector<ll>> &A, vector<vector<ll>> &B, ll m)
    {
        int size = A.size();
        vector<vector<ll>> result(size, vector<ll>(size, 0));
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                for (int k = 0; k < size; ++k)
                {
                    result[i][j] += A[i][k] * B[k][j];
                    result[i][j] %= m;
                }
            }
        }
        return result;
    }

    long long genFibNum(ll a, ll b, ll c, ll n, ll m)
    {
        if (n <= 2)
            return 1LL % m;
        vector<vector<ll>> mat = {{a, b, 1}, {1, 0, 0}, {0, 0, 1}};
        vector<vector<ll>> res = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
        n -= 2;
        while (n > 0)
        {
            if (n & 1)
                res = multiply(res, mat, m);
            mat = multiply(mat, mat, m);
            n >>= 1;
        }
        return (res[0][0] + res[0][1] + c * res[0][2]) % m;
    }
};