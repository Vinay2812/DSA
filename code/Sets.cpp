#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int>arr1={1,2,3,4,5,6};
    vector<int>arr2={1,2,5,6,7,7,7,7,7};

    unordered_set<int>st;

    for (int i = 0; i < arr1.size(); i++)
    {
        st.insert(arr1[i]);
    }

    

    for (int i = 0; i < arr2.size(); i++)
    {
        st.insert(arr2[i]);
    }
    cout << st.count(7);

    for(auto x : st)
    cout<<x<<" ";

    return 0;
}