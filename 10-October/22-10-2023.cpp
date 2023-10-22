/*

Author : Shashvat Tiwari
Date : 22/10/2023
Problem : Number of paths
Difficulty : Medium
Problem Link :https : https://practice.geeksforgeeks.org/problems/number-of-paths0926/1
Video Solution : NA

*/

class Solution
{
public:
    long long numberOfPaths(int M, int N)
    {
        const int MOD = 1000000007;

        // Calculate (M + N - 2) choose (M - 1) using modular exponentiation.
        return binomialMod(M + N - 2, min(M - 1, N - 1), MOD);
    }

private:
    long long binomialMod(int n, int k, int mod)
    {
        if (k < 0 || k > n)
            return 0;
        if (k > n - k)
            k = n - k;

        long long result = 1;
        for (int i = 0; i < k; i++)
        {
            result = (result * (n - i)) % mod;
            result = (result * modInverse(i + 1, mod)) % mod;
        }
        return result;
    }

    long long modInverse(int a, int mod)
    {
        long long result = 1;
        long long base = a;
        int exponent = mod - 2;
        while (exponent > 0)
        {
            if (exponent % 2 == 1)
            {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exponent /= 2;
        }
        return result;
    }
};
