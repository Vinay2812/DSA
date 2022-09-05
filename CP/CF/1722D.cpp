#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define first ff
#define second ss
#define sum_n(res,a) res=0; for(ll x:a) res+=x
#define setbits(n) __builtin_popcountll(n)
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #define dbg(x) cerr<<#x<<" = "<<endl;print(x);cerr<<endl;
    template <class T> void print(T v){cerr<<v;}
    bool compare(){FILE *fp1 = fopen("D:/Desktop/DSA/my.txt", "r");FILE *fp2 = fopen("D:/Desktop/DSA/output.txt", "r");char ch1 = getc(fp1);char ch2 = getc(fp2);while (ch1 != EOF && ch2 != EOF){if (ch1 != ch2)return false;ch1 = getc(fp1);ch2 = getc(fp2);}fclose(fp1);fclose(fp2);return ch1 == EOF && ch2 == EOF;}
#else
    #define dbg(x) ;
#endif

void solve(){
    int k;cin>>k;
    string s;cin>>s;
    int n = s.size();
    ll sum = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    for(int i = 0; i < n; i++){
        if(s[i] == 'L'){
            pq.push({i, i});
            sum += i;
        }
        else{
            pq.push({n-1-i, i});
            sum += (n-1-i);
        }
    }

    while(!pq.empty() and k--){
        int i = pq.top().ss;
        int val = pq.top().ff;
        pq.pop();

        if(s[i] == 'L' and val < (n-i-1)){
            sum -= i;
            sum += (n-1-i);
        }
        else if(s[i] == 'R' and val < i){
            sum -= (n-1-i);
            sum += i;
        }
        
        cout<<sum<<" ";
    }
}

int main()
{
    fast_io;
    #ifndef ONLINE_JUDGE
        freopen("D:/Desktop/DSA/input.txt","r", stdin);
        freopen("D:/Desktop/DSA/output.txt","w", stdout);
        freopen("D:/Desktop/DSA/debug.txt","w", stderr);
    #endif

    ll T=1;
    cin>>T;
    for(int i=1;i<=T;i++){
        solve();
        cout<<endl;
    }
    dbg(compare());
    return 0;
}