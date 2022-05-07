#include<bits/stdc++.h>
using namespace std;

vector<int> NGE(vector<int>arr)
{
    vector<int>ans(arr.size(),-1);
    stack<int>st;

    for(int i=0;i<arr.size();i++){
        while(!st.empty() && arr[i]>arr[st.top()])
        {
            ans[st.top()]=arr[i];
            st.pop();
        }

        st.push(i);
    }

    // while(!st.empty())
    // {
    //     ans[st.top()]=-1;
    //     st.pop();
    // }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int>arr = {7,2,4,6,8,1,11,4};

    auto ans = NGE(arr);

    for(int x:ans)
        cout<<x<<" ";

    return 0;
}