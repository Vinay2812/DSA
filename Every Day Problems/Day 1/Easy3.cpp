#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vvl vector<vector<long long>>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<long long, long long>>
#define first ff
#define second ss
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums){
    int n = nums.size();
    vector<int> nge(n, -1);

    stack<int> st;

    for(int i=0;i<n;i++){
        while(!st.empty() and nums[i] > nums[st.top()]){
            nge[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }
    return nge;

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../../input.txt","r", stdin);
        freopen("../../output.txt","w", stdout);
    #endif

    ll n;cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];

    auto ans = nextGreaterElement(nums);

    for(auto it : ans)cout<<it<<" ";

    return 0;
}