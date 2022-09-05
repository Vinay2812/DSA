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

template <class T> void input(T& n){cin>>n;}
template <class T> void input(vector<T>& nums){for(T &x : nums)input(x);}
template <class T> void input(vector<T> nums[], int n, int m){for(int i=0;i<n;i++){vector<T> t(m);input(t);nums[i] = t;}}
template <class T> void input(vector<vector<T>>& nums){int n = nums.size(), m = nums[0].size();for(int i=0;i<n;i++)for(int j=0;j<m;j++)input(nums[i][j]);}
template <class T1, class T2> void input(vector<pair<T1, T2>>& v){int n = v.size();for(int i=0;i<n;i++){T1 x;T2 y;input(x);input(y);v[i] = {x, y};}}

#ifndef ONLINE_JUDGE
    #define dbg(x) cerr<<#x<<" = ";print(x);cerr<<endl;
    template <class T> void print(T v){cerr<<v;}
    template <class T> void print(vector<T> v){cerr<<"[ ";for(auto it : v){print(it);cerr<<" ";}cerr<<"]";}
    template <class T1, class T2> void print(pair<T1, T2> v){cerr<<"[ ";print(v.ff);cerr<<" -> ";print(v.ss);cerr<<" ]";}
    template <class T> void print(vector<vector<T>> v){cerr<<"["<<endl;for(auto it : v){cerr<<"  ";print(it);cerr<<endl;}cerr<<"]";}
    template <class T1, class T2> void print(vector<pair<T1, T2>> v){cerr<<"["<<endl;for(auto it : v){cerr<<"  ";print(it);cerr<<endl;}cerr<<"]";}
    template <class T1, class T2> void print(unordered_map<T1, T2> mp){for(auto it : mp){print(it.ff);cerr<<" -> ";print(it.ss);cerr<<endl;}}
    template <class T1, class T2> void print(map<T1, T2> mp){for(auto it : mp){print(it.ff);cerr<<" -> ";print(it.ss);cerr<<endl;}}
    template <class T> void print(unordered_set<T> s){cerr<<"[";for(auto it : s){print(it);cerr<<" ";}cerr<<"]";}
    template <class T> void print(set<T> s){cerr<<"["<<endl;for(auto it : s){print(it);cerr<<endl;}cerr<<"]";}
    bool compare(){FILE *fp1 = fopen("D:/Desktop/DSA/my.txt", "r");FILE *fp2 = fopen("D:/Desktop/DSA/output.txt", "r");char ch1 = getc(fp1);char ch2 = getc(fp2);while (ch1 != EOF && ch2 != EOF){if (ch1 != ch2)return false;ch1 = getc(fp1);ch2 = getc(fp2);}fclose(fp1);fclose(fp2);return ch1 == EOF && ch2 == EOF;}
#else
    #define dbg(x) ;
#endif

class Solution{
private:
    ll gcd(ll a, ll b){
        if(b == 0)return a;
        return gcd(b, a%b);
    }
public:
    void solve(){
        ll n;input(n);
        ll cnt = 0;
        for(int k=1;k<=3;k++){
            for(ll i = 1;i<=n;i++){
                for(ll j = 1;j<=n;j++){
                    double g = (double)__gcd(i, j);
                    // dbg(g);
                    if(((i*j )/(g*g))> (double)k)break;
                    dbg(i);
                    dbg(j);
                    cnt++;
                }
            }
        }
        dbg(cnt);
        cout<<(cnt);
    }
};

int main()
{
    fast_io;
    #ifndef ONLINE_JUDGE
        freopen("D:/Desktop/DSA/input.txt","r", stdin);
        freopen("D:/Desktop/DSA/output.txt","w", stdout);
        freopen("D:/Desktop/DSA/debug.txt","w", stderr);
    #endif

    Solution obj;
    ll T=1;
    cin>>T;
    for(int i=1;i<=T;i++){
        obj.solve();
        cout<<endl;
        
    }
    dbg(compare());
    return 0;
}