#include <bits/stdc++.h>
using namespace std;

int f(int i, int buy, int trans, int n, vector<int> &prices, vector<vector<vector<int>>> &dp)
{
    if (trans == 0)
    {
        return 0;
    }
    if (i == n-1)
    {
        if (buy == 1)
            return 0;
        else
            return prices[n - 1];
    }
    if (dp[i][buy][trans] != -1)
        return dp[i][buy][trans];
    // buy
    if (buy == 1)
    {
        int b = -prices[i] + f(i + 1, 0, trans, n, prices, dp);
        int nb = 0 + f(i + 1, 1, trans, n, prices, dp);

        return dp[i][buy][trans] = max(max(b, nb), 0);
    }
    else
    {
        // sell
        int s = +prices[i] + f(i + 1, 1, trans - 1, n, prices, dp);
        int ns = 0 + f(i + 1, 0, trans, n, prices, dp);

        return dp[i][buy][trans] = max(s, ns);
    }
}
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int k = 2;

    // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
    // return f(0, 1, k, n, prices, dp);

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, 0)));

    vector<vector<int>>next(2, vector<int>(k + 1, 0)), curr(2, vector<int>(k+1, 0));

    for (int buy = 0; buy <= 1; buy++)
    {
        for (int trans = 1; trans <= 2; trans++)
        {
            if (buy == 1){
                // dp[n-1][buy][trans] = 0;
                next[buy][trans] = 0;
            }
            else{
                next[buy][trans] = prices[n - 1];
                // dp[n - 1][buy][trans] = prices[n - 1];
            }
        }
    }

    // for(int i=0;i<n;i++){
    //     for(int buy=0;buy<=1;buy++){
    //         dp[i][buy][0] = 0;
    //     }
    // }

    for (int buy = 0; buy <= 1; buy++)
    {
        next[buy][0] = curr[buy][0] = 0;
    }


    for(int i=n-2;i>=0;i--){
        for(int buy=0;buy<=1;buy++){
            for(int trans=k;trans>=1;trans--){
                if (buy == 1)
                {
                    int b = -prices[i] + dp[i+1][0][trans];
                    int nb = 0 + dp[i + 1][1][trans];

                    dp[i][buy][trans] = max(max(b, nb), 0);
                }
                else
                {
                    // sell
                    int s = +prices[i] + dp[i + 1][1][trans-1];
                    int ns = 0 + dp[i + 1][0][trans];

                    dp[i][buy][trans] = max(s, ns);
                }
            }
        }
    }

    return dp[0][1][k];
}

int main()
{
    int n;
    cin >> n;

    vector<int> prices(n);

    for (int i = 0; i < n; i++)
        cin >> prices[i];

    cout << maxProfit(prices);
    return 0;
}