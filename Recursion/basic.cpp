#include <bits/stdc++.h>
using namespace std;

// 1 2 3 4
// void f(int n)
// {
//     if (n == 1)
//     {
//         cout << 1 << " ";
//         return;
//     }

//     f(n - 1);
//     cout << n << " ";
// }

// void f(int i, int n)
// {
//     if (i == n)
//     {
//         cout << n << " ";
//         return;
//     }
//     cout << i << " ";
//     f(i + 1, n);
// }

void f(int n)
{
    if (n == 1)
    {
        cout << n << " ";
        return;
    }

    cout << n << " ";
    f(n - 1);
}

void f(int i, int n)
{
    if (i == n)
    {
        cout << n << " ";
        return;
    }
    f(i + 1, n);
    cout << i << " ";
}

int main()
{
    f(1, 4);
    return 0;
}