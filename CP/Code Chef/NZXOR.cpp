#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define pii pair<ll, ll>
#define first ff
#define second ss
#define setbits(n) __builtin_popcountll(n)
#define rightmost(n)  63 - __builtin_clzll(n)
#define leftmost(n)  __builtin_ctzll(n)
#define lz(n)  __builtin_clzll(n)
#define tz(n)  __builtin_ctzll(n)
#define sumof(v, x) accumulate(v.begin(), v.end(), x)
#define minof(v) *min_element(v.begin(), v.end())
#define maxof(v) *max_element(v.begin(), v.end())
#define substring(s, st, e) s.substr(st, (e-st+1))
#define mod 1000000007
#define add(a, b, mod) ((a) + (b))%(mod)
#define multiply(a, b, mod) (1ll*(a) * (b))%(mod)
#define loop(i, s, e, inc) for(int (i)=(s);(i) < (e); (i) += (inc))
#define pb(x) push_back(x)
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#include "bits/stdc++.h"
using namespace std;

template <class T> istream& operator>>(istream& in, vector<T>& v){for(T &x : v){in>>x;}return in;}
template <class T> istream& operator>>(istream& in, vector<vector<T>>& v){for(auto &x : v){for(T &y : x)in>>y;}return in;}
template <class T1, class T2> istream& operator>>(istream& in, vector<pair<T1, T2>>& v){for(auto& P : v){in>>P.ff;in>>P.ss;}return in;}

template <class T> ostream& operator<<(ostream& out, vector<T>& v){for(T &x : v){out<<x<<" ";}return out;}
template <class T> ostream& operator<<(ostream& out, vector<vector<T>>& v){for(auto &x : v){out<<x<<endl;}return out;}

#ifndef ONLINE_JUDGE
    #define dbg(x) cerr<<#x<<" = ";print(x);cerr<<endl;
    void print();
    template <class T> void print(T v){cerr<<v;}
    template <class T> void print(vector<T> v){cerr<<"[ ";for(auto it : v){print(it);cerr<<" ";}cerr<<"]";}
    template <class T1, class T2> void print(pair<T1, T2> v){cerr<<"[ ";print(v.ff);cerr<<" -> ";print(v.ss);cerr<<" ]";}
    template <class T> void print(vector<vector<T>> v){cerr<<"["<<endl;for(auto it : v){cerr<<"  ";print(it);cerr<<endl;}cerr<<"]";}
    template <class T1, class T2> void print(vector<pair<T1, T2>> v){cerr<<"["<<endl;for(auto it : v){cerr<<"  ";print(it);cerr<<endl;}cerr<<"]";}
    template <class T1, class T2> void print(unordered_map<T1, T2> mp){for(auto it : mp){print(it.ff);cerr<<" -> ";print(it.ss);cerr<<endl;}}
    template <class T1, class T2> void print(map<T1, T2> mp){for(auto it : mp){print(it.ff);cerr<<" -> ";print(it.ss);cerr<<endl;}}
    template <class T> void print(unordered_set<T> s){cerr<<"[";for(auto it : s){print(it);cerr<<" ";}cerr<<"]";}
    template <class T> void print(set<T> s){cerr<<"["<<endl;for(auto it : s){print(it);cerr<<endl;}cerr<<"]";}
    bool compare(){FILE *fp1 = fopen("D:/Desktop/DSA/IOD/my.txt", "r");FILE *fp2 = fopen("D:/Desktop/DSA/IOD/output.txt", "r");char ch1 = getc(fp1);char ch2 = getc(fp2);while (ch1 != EOF && ch2 != EOF){if (ch1 != ch2)return false;ch1 = getc(fp1);ch2 = getc(fp2);}fclose(fp1);fclose(fp2);return ch1 == EOF && ch2 == EOF;}
#else
    #define dbg(x) ;
#endif	
class Solution{
public:
    void solve(){
        int n;cin>>n;vi a(n);cin>>a;
        int cnt = 0;
        unordered_set<int> prefix;
        prefix.insert(0);
        int curr = 0;
        for(int x : a){
            curr ^= x;
            if(prefix.count(curr)){
                cnt++;
                prefix.clear();
                curr = 0;
            }
            prefix.insert(curr);
        }
        cout<<cnt;

    }
};

int main()
{
    clock_t start = clock();
    fast_io;
    #ifndef ONLINE_JUDGE
        freopen("D:/Desktop/DSA/IOD/input.txt","r", stdin);
        freopen("D:/Desktop/DSA/IOD/output.txt","w", stdout);
        freopen("D:/Desktop/DSA/IOD/debug.txt","w", stderr);
    #endif

    Solution obj;
    ll T=1;
    cin>>T;
    for(int i=1;i<=T;i++){
        obj.solve();
        cout<<endl;
    }
    dbg(compare());
    string time = (to_string((double)(clock()-start)/CLOCKS_PER_SEC) + "s");
    dbg(time);
    return 0;
}