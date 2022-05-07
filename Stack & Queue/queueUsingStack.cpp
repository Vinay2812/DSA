#include <bits/stdc++.h>
using namespace std;

stack<int> st1;
stack<int> st2;

void push(int x)//O(1)
{
    st1.push(x);
}

int pop()//amortized O(1)
{
    if(st1.empty() && st2.empty())
        return -1;

    if(st2.empty())
    {
        while(!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
    }

    int ans = st2.top();
    st2.pop();
    return ans;
}

int front()
{
    if (st1.empty() && st2.empty())
        return -1;

    if (st2.empty())
    {
        while (!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
    }

    return st2.top();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    push(1);
    push(3);
    cout << front() << " ";
    push(4);
    cout << pop() << " ";
    push(5);
    push(6);
    cout << front() << " ";
    cout << pop() << " ";
    cout << pop() << " ";
    cout << front() << " ";

    return 0;
}