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

void NSE(vector<int>& nums, vector<int>& nse){
    int n = nums.size();

    stack<int> st;

    for(int i=0;i<n;i++){
        while(!st.empty() and nums[i] < nums[st.top()]){
            nse[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
}

void PSE(vector<int>& nums, vector<int>& pse){
    int n = nums.size();

    stack<int> st;

    for(int i=n-1;i>=0;i--){
        while(!st.empty() and nums[i] < nums[st.top()]){
            pse[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
}
int largestRectangleArea(vector<int> &h){
    int n = h.size();
    int maxi = -1e9;
    vector<int> nse(n, n);
    vector<int> pse(n, -1);

    NSE(h, nse);
    PSE(h, pse);

    for(int i=0;i<n;i++){
        int l = pse[i];
        int r = nse[i];

        int area = (r-l-1)* h[i];
        maxi = max(area, maxi);
    }
    return maxi;

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

    cout<<largestRectangleArea(nums);
    return 0;
}