#include <bits/stdc++.h>
using namespace std;
void f(int i, vector<int> arr, int sum, vector<int> &ans)
{
    if (i == 0)
    {
        sum += arr[0];
        ans.push_back(sum);
        return;
    }
    // not take
    f(i - 1, arr, sum, ans);
    // take
    sum += arr[i];
    f(i - 1, arr, sum, ans);
    sum -= arr[i];
}
vector<int> subsetSum(vector<int> arr)
{
    vector<int> ans;
    // vector<int> dp(arr.size(), -1);
    ans.push_back(0);
    f(arr.size() - 1, arr, 0, ans);
    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 4, 6};
    vector<int> ans = subsetSum(arr);

    for (int i : ans)
        cout << i << " ";
    return 0;
}