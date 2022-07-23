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


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../../input.txt","r", stdin);
        freopen("../../output.txt","w", stdout);
    #endif

    string s;
    cin>>s;

    unordered_map<char, int> vowels;
    vowels['a']++;
    vowels['e']++;
    vowels['i']++;
    vowels['o']++;
    vowels['u']++;
    vowels['A']++;
    vowels['E']++;
    vowels['I']++;
    vowels['O']++;
    vowels['U']++;
    vowels['Y']++;
    vowels['y']++;

    string ans;
    int n = s.size();
    for(int i=0;i<n;i++){
        if(vowels.find(s[i]) != vowels.end())continue;

        ans.push_back('.');
        char c = (s[i]>='A' and s[i]<='Z')?s[i]-'A'+'a':s[i];
        ans.push_back(c);
    }

    cout<<ans;
    return 0;
}