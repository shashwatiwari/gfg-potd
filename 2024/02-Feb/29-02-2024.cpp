/*

Author : Shashvat Tiwari
Date : 29/02/2024
Problem : Sum of Bit Differences
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/sum-of-bit-differences2937/1
Video Solution : NA


--------------------------------------------------------------------------------------------


The logic behind this approach is to count the number of set bits and clear bits at each position for all elements in the
array, and then calculate the sum of bit differences directly without explicitly comparing each pair.

For each bit position i from 0 to 31 (assuming integers are represented using 32 bits):
- Count the number of elements in the array that have the bit at position i set.

- Calculate the number of elements that have the bit at position i clear (i.e., unset).

For a given bit position i, there are two possibilities:

- If the bit at position i is set (1) in an element, there are count such elements in the array.
- If the bit at position i is clear (0) in an element, there are n - count such elements in the array.

For each pair of elements, if the bit at position i is different between the two elements, one element
will contribute to the count of set bits and the other will contribute to the count of clear bits at
 position i. Therefore, the total number of bit differences at position i for all pairs of elements is count * (n - count).

Since each pair contributes twice to the total bit difference (once for each ordering of the pair),
 we multiply count * (n - count) by 2 to get the total sum of bit differences at position i.

- The sum of bit differences at position i is then count * (n - count) * 2, where count is the number of elements
 with the bit set and (n - count) is the number of elements with the bit clear. The factor of 2 accounts
  for the fact that for each pair (x, y), we are counting both (x, y) and (y, x).

- Sum up the bit differences for all bit positions from 0 to 31 to get the total sum of bit differences for all pairs of elements in the array.

*/

class Solution
{
public:
    long long sumBitDifferences(int arr[], int n)
    {
        long long sum = 0;

        for (int i = 0; i < 32; ++i)
        {
            long long count = 0;
            for (int j = 0; j < n; ++j)
            {
                if (arr[j] & (1 << i))
                {
                    count++;
                }
            }
            sum += count * (n - count) * 2;
        }

        return sum;
    }
};