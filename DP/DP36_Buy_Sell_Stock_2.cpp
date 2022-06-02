#include<bits/stdc++.h>
using namespace std;

int f(int i, int buy, int n, vector<int> &prices, vector<vector<int>> &dp)
{
    if (i == n - 1)
    {
        if (buy == 1)
            return 0;
        else
            return prices[n - 1];
    }
    if (dp[i][buy] != -1)
        return dp[i][buy];
    // buy
    if (buy == 1)
    {
        int b = -prices[i] + f(i + 1, 0, n, prices, dp);
        int nb = 0 + f(i + 1, 1, n, prices, dp);

        return dp[i][buy] = max(max(b, nb), 0);
    }
    else
    {
        // sell
        int s = +prices[i] + f(i+1, 1, n, prices, dp);
        int ns = 0 + f(i + 1, 0, n, prices, dp);

        return dp[i][buy] = max(s, ns);
    }
}
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, 0));

    dp[n - 1][0] = prices[n - 1];
    dp[n - 1][1] = 0;

    vector<int> next(2, 0), curr(2, 0);
    next[0] = prices[n - 1];
    next[1] = 0;

    for (int i = n - 2; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            if (buy == 1)
            {
                // int b = -prices[i] + dp[i+1][0];
                // int nb = 0 + dp[i+1][1];

                int b = -prices[i] + next[0];
                int nb = 0 + next[1];

                // dp[i][buy] = max(max(b, nb), 0);
                curr[buy] = max(max(b, nb), 0);
            }
            else
            {
                // sell
                // int s = +prices[i] + dp[i+1][1];
                // int ns = 0 + dp[i+1][0];
                int s = +prices[i] + next[1];
                int ns = 0 + next[0];

                // dp[i][buy] = max(s, ns);
                curr[buy] = max(s, ns);
            }
        }
        next = curr;
    }
    return next[1];
}

int main()
{
    int n;
    cin >> n;

    vector<int> prices(n);

    for (int i = 0; i < n; i++)
        cin >> prices[i];

    cout<<maxProfit(prices);
    return 0;
}