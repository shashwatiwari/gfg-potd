/*

Author : Shashvat Tiwari
Date : 05/03/2024
Problem : Maximum Index
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/maximum-index-1587115620/1
Video Solution : NA

-------------------------------------------------------------------------------------

The intuition behind the approach is to transform the input array into an array of pairs, where each pair consists
of the element value and its index in the original array. This transformation allows us to sort the array based on
the element values while keeping track of their original indices. By sorting the array, we can efficiently find
the maximum difference between indices where the value at the first index is less than the value at the second index.

Here's a step-by-step explanation of the intuition:

1. Transform the input array into an array of pairs, where each pair contains the element value and its index in
the original array. This transformation allows us to keep track of the original indices while sorting based on the element values.

2. Sort the array of pairs based on the element values. This step ensures that we can easily find the maximum index
to the right of an element where the value is greater, which is crucial for calculating the maximum difference between indices satisfying the given condition.

3. Initialize variables maxDiff to 0 and maxIndex to the index of the last element in the sorted array. These variables
will help us keep track of the maximum difference and the maximum index to the right of an element where the value is greater.

4. Iterate over the sorted array from right to left. For each element, update maxIndex to the maximum of its current
value and the index of the element to its right in the sorted array. Calculate the difference between maxIndex and the
index of the current element, and update maxDiff if this difference is greater than the current maxDiff.

5. After iterating over all elements, maxDiff will contain the maximum difference between indices satisfying the given condition.

6. Return maxDiff as the final result.

------------DRY RUN--------------

1. Original Array: {34, 8, 10, 3, 2, 80, 30, 33, 1}

2. Indexed Array: {(34, 0), (8, 1), (10, 2), (3, 3), (2, 4), (80, 5), (30, 6), (33, 7), (1, 8)}

We pair each element with its index in the original array.
3. Sorted Indexed Array: {(1, 8), (2, 4), (3, 3), (8, 1), (10, 2), (30, 6), (33, 7), (34, 0), (80, 5)}

We sort the indexed array based on the element values.
Initialize maxDiff = 0, maxIndex = 5 (index of last element in sorted indexed array).
Iterate from right to left over the sorted indexed array:
For element (34, 0): Update maxIndex = max(5, 5) = 5, maxDiff = 5 - 0 = (5).
For element (33, 7): Update maxIndex = max(5, 0) = 5, maxDiff = max(5, 5 - 7) = 5.
For element (30, 6): Update maxIndex = max(5, 7) = 7, maxDiff = max(5, 7 - 6) = 5.
For element (10, 2): Update maxIndex = max(7, 6) = 7, maxDiff = max(5, 7 - 2) = 5.
For element (8, 1): Update maxIndex = max(7, 2) = 7, maxDiff = max(5, 7-1) = 6.
For element (3, 3): Update maxIndex = max(7, 1) = 7, maxDiff = max(6, 7-3) = 6.
For element (2, 4): Update maxIndex = max(7, 3) = 7, maxDiff = max(6, 7-4) = 6.
For element (1, 8): Update maxIndex = max(7, 4) = 7, maxDiff = max(6, 7-8) = 6.

Return maxDiff = 6, which is the maximum difference in indices (7-1) satisfying the condition a[i] < a[j] and i < j.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxIndexDiff(const vector<int> &arr)
{
    int n = arr.size();
    vector<pair<int, int>> indexedArr(n);

    for (int i = 0; i < n; ++i)
    {
        indexedArr[i] = make_pair(arr[i], i);
    }

    sort(indexedArr.begin(), indexedArr.end());

    int maxDiff = 0;
    int maxIndex = indexedArr[n - 1].second;

    for (int i = n - 2; i >= 0; --i)
    {
        maxIndex = max(maxIndex, indexedArr[i + 1].second);
        maxDiff = max(maxDiff, maxIndex - indexedArr[i].second);
    }

    return maxDiff;
}

int main()
{
    vector<int> arr = {34, 8, 10, 3, 2, 80, 30, 33, 1};
    cout << maxIndexDiff(arr) << endl;
    return 0;
}
