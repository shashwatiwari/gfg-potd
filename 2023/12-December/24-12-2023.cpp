/*

Author : Shashvat Tiwari
Date : 24/12/2023
Problem : Buy Maximum Stocks if i stocks can be bought on i-th day
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/buy-maximum-stocks-if-i-stocks-can-be-bought-on-i-th-day/1
Video Solution : NA

---------------------------------------------------------------------------------------------------


Intuition:
- The approach begins by organizing the prices alongside their occurrence days,
enabling the tracking of the buying capacity according to the budget k.
- Sorting the prices simplifies the process, allowing us to start with the cheapest
stocks first and gradually moving to higher-priced stocks.
- The loop iterates through each price, ensuring the maximum possible number of stocks
 are bought at each price point while adhering to the budget constraints.
- The goal is to maximize the number of stocks bought within the given budget, considering
 both the individual stock price and the day-specific purchasing limits.

*/

class Solution
{
public:
    int buyMaximumProducts(int n, int k, int price[])
    {
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({price[i], i + 1});
        }
        int ans = 0;
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++)
        {
            int a = v[i].first;
            int b = v[i].second;
            if (k >= a and (k / a) >= b)
            {
                ans += b;
                k -= (b * a);
            }
            else
            {
                ans += (k / a);
                break;
            }
        }
        return ans;
    }
};