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
int size = int(1e7);
vector<vector<bool>> dp;
string substr(int st, int e, string s){
    string ans;
    for(int i=st;i<=e;i++){
        ans.push_back(s[i]);
    }
    return ans;
}

string solve(){
    string s;cin>>s;
    int n = s.size();

    dp.resize(n, vector<bool>(n, 0));

    int maxi = 1;
    int r = 0, c = 0;

    for(int i=0;i<n;i++)dp[i][i] = true;
    for(int i=0;i<n-1;i++){
        dp[i][i+1] = s[i] == s[i+1];
        if(maxi!=2 and dp[i][i+1] == 1){
            r = i;
            c = i+1;
            maxi = 2;
        }
    }

    

    for(int i=n-3;i>=0;i--){
        for(int j=i+2;j<n;j++){
            if(s[i] == s[j] and dp[i+1][j-1]){
                dp[i][j] = 1;

                if(j-i+1 > maxi){
                    maxi = j-i+1;
                    r = i;
                    c = j;
                }
            }
        }
    }
    string front="";
    string suff =substr(c+1, n-1, s);

    unordered_map<string, int> mp;
    int l = min(r, n-c);

   for(int i=l;i<n;i++){
        suff.push_back(s[i]);
        mp[suff]++;
    }

    suff = "";
    for(int i=r-1;i>=0;i--){
        suff.push_back(s[i]);
        mp[suff]++;
        if(mp[suff] == 2)front = suff;
    }

    string ans = front + substr(r, c, s);
    reverse(front.begin(), front.end());
    ans += front;

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../../../input.txt","r", stdin);
        freopen("../../../output.txt","w", stdout);
    #endif

    ll t;
    cin>>t;

    while(t--){
        cout<<solve()<<endl;
    }
   
    return 0;
}