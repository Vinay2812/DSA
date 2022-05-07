#include<bits/stdc++.h>
using namespace std;

void insert(stack<int> &st,int ele)
{
    if(st.empty())
    {    
        st.push(ele);
        return;
    }

    int currTop = st.top();
    st.pop();
    insert(st,ele);
    st.push(currTop);
}
void reverseStack(stack<int>&st)
{
    if(st.empty())
        return;

    int x = st.top();
    st.pop();

    reverseStack(st);

    insert(st,x);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<int>st;
    vector<int>arr = {3,1,2,4,6};
    for(int x : arr)
        st.push(x);

    reverseStack(st);

    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}