/*

Author : Shashvat Tiwari
Date : 09/03/2024
Problem : Find the Nth Character
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/find-the-n-th-character5925/1
Video Solution : NA

-------------------------------------------------------------------------------------

Code Explanation :-

1. First we increment the n by 1 for 1 based indexing.
2. Now we know that each character of string s must be flipped r times suppose s[i] == '1'
flip for 0th time = 1
flip for 1st time = 10
flip for 2nd time = 1001
flip for 3rd time = 10010110

Similarly if s[i] == '0'
flip for 0th time = 0
flip for 1st time = 01
flip for 2nd time = 0110
flip for 3rd time = 01101001

so we can observe that each time the length get doubled of previous one and string becomes " previous_string + reverse(previous_string) " or "previous_string + flipped(previous_string)".
now let we have flipped the ith character for rth times so length of current(ith) character becomes len = 2^r now if n <= len, it means
that we can the get the nth character in this length of current character.
now if n <= len/2 it means n is in the first half length of current string(s[i]) and we know tha first half length is similar to previous string
so we can get the nth bit in previous string so we decreased the len by len/2.

but if n > len/2 it means that we are getting nth bit in last half length of string and last half of string is nothing but flipped(previous_string)
means we can get n in the same position of previous bit but we have to flipped that bit so n becomes n = n - len/2.

We continue the process untill the n becomes equal to one because then we reach at the current character s[i] and now we check if flip == 1 it means we
have to bit flip the s[i] then return it if flip == 0 then simply return the s[i];

*/

class Solution
{
public:
    char nthCharacter(string s, int r, int n)
    {
        n++;
        for (int i = 0; i < s.size(); i++)
        {
            if (n <= pow(2, r))
            {
                int len = pow(2, r);
                int flip = 0;
                while (n > 1)
                {
                    len = len / 2;
                    if (n > len)
                    {
                        flip ^= 1;
                        n = n - len;
                    }
                }
                if (flip)
                {
                    int c = s[i] - '0';
                    c ^= 1;
                    return c + '0';
                }
                return s[i];
            }
            n = n - pow(2, r);
        }
        return '0';
    }
};