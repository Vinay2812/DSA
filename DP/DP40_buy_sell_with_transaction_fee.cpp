/*
link-> https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

*/
#include<bits/stdc++.h>
using namespace std;
int f(int i, int buy, int n, vector<int> &prices, vector<vector<int>> &dp, int fee)
{
    if (i == n - 1)
    {
        if (buy == 1)
            return 0;
        else
            return prices[n - 1] - fee;
    }
    if (dp[i][buy] != -1)
        return dp[i][buy];
    // buy
    if (buy == 1)
    {
        int b = -prices[i] + f(i + 1, 0, n, prices, dp, fee);
        int nb = 0 + f(i + 1, 1, n, prices, dp, fee);

        return dp[i][buy] = max(max(b, nb), 0);
    }
    else
    {
        // sell
        int s = +prices[i] + f(i + 1, 1, n, prices, dp, fee) - fee;
        int ns = 0 + f(i + 1, 0, n, prices, dp, fee);

        return dp[i][buy] = max(s, ns);
    }
}

int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));

    return f(0, 1, n, prices, dp, fee);
}

int main()
{
    int n;
    cin >> n;
    int fee;
    cin>>fee;

    vector<int> prices(n);

    for (int i = 0; i < n; i++)
        cin >> prices[i];

    cout << maxProfit(prices, fee);
    return 0;
}