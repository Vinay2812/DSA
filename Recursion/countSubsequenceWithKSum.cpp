#include <bits/stdc++.h>
using namespace std;

int f(int i, vector<int> arr, int sum)
{
    if (sum == 0)
        return 1;
    if (i == 0)
    {
        return arr[0] == sum;
    }

    int notTake = f(i - 1, arr, sum);
    int take = 0;
    if (arr[i] <= sum)
        take = f(i - 1, arr, sum - arr[i]);

    return take + notTake;
}
int main()
{
    vector<int> arr = {1, 2, 1, 1, 2};
    int sum = 3;

    cout << f(4, arr, sum);
    return 0;
}