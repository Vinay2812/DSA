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

bool bad(string s, int k, string key){
    int cnt_bad = 0;
    for(char c : s){
        if(key[c-'a'] == '0')cnt_bad++;
        if(cnt_bad > k)return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../../../input.txt","r", stdin);
        freopen("../../../output.txt","w", stdout);
    #endif

    string s;getline(cin, s);
    string key;getline(cin, key);
    string l;getline(cin, l);
    int k = stoi(l);

    long long cnt_bad = 0;
    unordered_map<string, int> mp;
    int n = s.size();
    long long cnt = 0;

    for(int i=0;i<n;i++){
        string sub;
        for(int j=i;j<n;j++){
            sub.push_back(s[j]);
            mp[sub]++;
        }
    }

    for(auto it : mp){
        if(!bad(it.first, k, key)){
            cnt++;
        }
    }

    cout<<cnt<<endl;
    return 0;
}