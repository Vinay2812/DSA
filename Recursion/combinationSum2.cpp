#include <bits/stdc++.h>
using namespace std;
// 2, 2, 1, 1
void f(int i, int target, vector<pair<int, int>> arr, vector<int> path, vector<vector<int>> &ans)
{
    if (target == 0)
    {
        ans.push_back(path);
        return;
    }

    if (i == 0)
    {
        // take
        if (target % arr[0].first == 0)
        {
            int req = target / arr[0].first;
            if (arr[0].second >= req)
            {
                while (req != 0)
                {
                    path.push_back(arr[0].first);
                    req--;
                }
                ans.push_back(path);
            }
        }
        return;
    }

    // not take
    f(i - 1, target, arr, path, ans);

    // take
    if (arr[i].first <= target)
    {
        path.push_back(arr[i].first);

        if (arr[i].second > 0)
        {
            arr[i].second--;
            f(i, target - arr[i].first, arr, path, ans);
            arr[i].second++;
        }

        path.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> arr, int target)
{
    unordered_map<int, int> mp;

    for (int x : arr)
        mp[x]++;

    vector<pair<int, int>> arr1;

    for (auto it : mp)
        arr1.push_back(it);

    int n = arr1.size();

    sort(arr1.begin(), arr1.end(), greater<pair<int, int>>());
    vector<vector<int>> ans;

    f(n - 1, target, arr1, {}, ans);

    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 1, 1};
    int target = 3;

    vector<vector<int>> ans = combinationSum2(arr, target);

    for (auto it : ans)
    {
        for (int x : it)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}