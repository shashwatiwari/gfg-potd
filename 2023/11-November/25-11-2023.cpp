/*

Author : Shashvat Tiwari
Date : 25/11/2023
Problem : Shuffle Integers
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/shuffle-integers2401/1
Video Solution : NA

------------------------------------------------------------------------------------

Explanation of the shuffle operation:

- The loop runs from i = 0 to i < n/2.

- For each iteration, it rotates the elements starting
from arr[2 * i + 1] up to arr[n/2 + i], inclusive.

- This rotation effectively shuffles the elements in place,
following the specified pattern where a elements are interleaved with b elements.

-------------------------------------------------------------------------------------  */

class Solution
{
public:
    void shuffleArray(int arr[], int n)
    {
        for (int i = 0; i < n / 2; i++)
            rotate(arr + 2 * i + 1, arr + n / 2 + i, arr + n / 2 + i + 1);
    }
};

/*
Let's break down what's happening inside the shuffleArray function:

rotate is a standard library function in C++ that rotates the elements
in the range [first, last) in a specified manner.

Here's the breakdown of the parameters in the rotate function:

- arr + 2 * i + 1: Points to the position of the first element
in the range to be rotated.
- arr + n/2 + i: Points to the element next to the last element
 of the first half of the array.
- arr + n/2 + i + 1: Points to the end position (one past the last element)
 of the range to be rotated.


*/
