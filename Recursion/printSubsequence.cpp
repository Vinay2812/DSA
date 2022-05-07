#include <bits/stdc++.h>
using namespace std;

void f(int i, string s, string curr)
{
    if (i == 0)
    {
        // not take
        cout << curr << endl;
        // take
        cout << (s[i] + curr) << endl;
        return;
    }

    // not take
    f(i - 1, s, curr);
    // take
    f(i - 1, s, (s[i] + curr));
}

void f(int i, int n, vector<int> arr, vector<int> curr)
{
    if (i == n - 1)
    {
        // not take
        for (int x : curr)
            cout << x << " ";
        cout << endl;
        // take
        curr.push_back(arr[i]);
        for (int x : curr)
            cout << x << " ";
        cout << endl;
        return;
    }

    // take
    curr.push_back(arr[i]);
    f(i + 1, n, arr, curr);
    curr.pop_back();
    // not take
    f(i + 1, n, arr, curr);
}
int main()
{
    // f(2, "abc", "");
    vector<int> arr = {1, 2, 3};
    f(0, 3, arr, {});
    return 0;
}