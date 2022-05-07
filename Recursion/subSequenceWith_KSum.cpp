#include <bits/stdc++.h>
using namespace std;

void f(int i, vector<int> arr, vector<int> path, int sum, vector<vector<int>> &ans)
{
    if (sum == 0)
    {
        ans.push_back(path);
        return;
    }

    if (i == 0)
    {
        if (sum % arr[0] == 0)
        {
            int n = sum / arr[0];
            while (n--)
            {
                path.push_back(arr[0]);
            }
            ans.push_back(path);
        }
        return;
    }

    // not take
    f(i - 1, arr, path, sum, ans);
    // take
    path.push_back(arr[i]);
    if (arr[i] <= sum)
        f(i, arr, path, sum - arr[i], ans);
    path.pop_back();
}
int main()
{
    vector<int> arr = {1, 3, 2};
    sort(arr.begin(), arr.end(), greater<int>());
    int sum = 5;
    vector<vector<int>> ans;
    f(2, arr, {}, sum, ans);

    reverse(ans.begin(), ans.end());

    for (auto i : ans)
    {
        for (int x : i)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}