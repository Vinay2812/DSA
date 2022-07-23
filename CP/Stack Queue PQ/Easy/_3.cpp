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
#define sum_n(res,a) res=0; for(ll x:a) res+=x;
#include<bits/stdc++.h>
using namespace std;

int getMax(string s){
    int n = s.size();
    int maxi = 0;
    stack<int> st;
    st.push(-1);
    for(int i=0;i<n;i++){
        if(s[i] == '(')st.push(i);
        else if(s[i] == ')' and st.top() != -1 and s[st.top()] == '('){
            st.pop();
            maxi = max((i - st.top()), maxi);
        }
        else st.push(i);
    }
    return maxi;
}

int getCount(string s, int maxi){
    int n = s.size();
    int cnt = 0;
    stack<int> st;
    st.push(-1);
    for(int i=0;i<n;i++){
        if(s[i] == '(')st.push(i);
        else if(s[i] == ')' and st.top() != -1 and s[st.top()] == '('){
            st.pop();
            cnt +=( maxi == (i - st.top()));
        }
        else st.push(i);
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../../../input.txt","r", stdin);
        freopen("../../../output.txt","w", stdout);
    #endif

    string s;getline(cin,s);
    int maxi = getMax(s);
    if(maxi == 0){
        cout<<"0 1"<<endl;
    }
    else{
        cout<<maxi<<" "<<getCount(s, maxi)<<endl;
    }
    return 0;
}