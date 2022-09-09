#define ll long long
#define vi vector<ll>
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
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#include "bits/stdc++.h"
using namespace std;

template <class T> void in(T& n){cin>>n;}
template <class T> void in(vector<T>& nums){for(T &x : nums)in(x);}
template <class T> void in(vector<T> nums[], int n, int m){for(int i=0;i<n;i++){vector<T> t(m);in(t);nums[i] = t;}}
template <class T> void in(vector<vector<T>>& nums){int n = nums.size(), m = nums[0].size();for(int i=0;i<n;i++)for(int j=0;j<m;j++)in(nums[i][j]);}
template <class T1, class T2> void in(vector<pair<T1, T2>>& v){int n = v.size();for(int i=0;i<n;i++){T1 x;T2 y;in(x);in(y);v[i] = {x, y};}}

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
    bool compare(){FILE *fp1 = fopen("D:/Desktop/DSA/IOD/my.txt", "r");FILE *fp2 = fopen("D:/Desktop/DSA/IOD/output.txt", "r");char ch1 = getc(fp1);char ch2 = getc(fp2);while (ch1 != EOF && ch2 != EOF){if (ch1 != ch2)return false;ch1 = getc(fp1);ch2 = getc(fp2);}fclose(fp1);fclose(fp2);return ch1 == EOF && ch2 == EOF;}
#else
    #define dbg(x) ;
#endif	
class Solution{
public:
    void solve(){
        int n;cin>>n;
        vi a(n);in(a);

        for(int i=0;i<n;i++){
            ll x;cin>>x;
            a[i] -= x;
        }
        bool possible = true;
        int i = 0;
        dbg(a);
        while(i<n){
            while(i<n and a[i] == 0)i++;
            if(i == n)break;
            int j = i+1;
            while(j<n and a[j] == 0)j++;
            int t_idx = i+j+1;

            if(t_idx >= n || a[t_idx] == 0){
                possible = false;
                break;
            }

            if(a[t_idx] > 0){
                if(a[i] > 0 and a[j] > 0){
                    possible = false;
                    break;
                }
                else{
                    ll m;
                    if(a[i] < 0 and a[j] < 0){
                        m = min(min(-a[i], -a[j]), a[t_idx]);
                    }
                    else if(a[i] > 0){
                        m = min(-a[j], a[t_idx]);
                    }
                    else{
                        m = min(-a[i], a[t_idx]);
                    }
                    a[i] += m;
                    a[j] += m;
                    a[t_idx] -= m;
                } 
            }
            else{
                if(a[i] > 0 and a[j] > 0){
                    possible = false;
                    break;
                }
                else{
                    ll m;
                    if(a[i] < 0 and a[j] < 0){
                        m = -max(a[i], a[j]);
                    }
                    else if(a[i] < 0){
                        m = -a[i];
                    }
                    else{
                        m = -a[j];
                    }

                    a[i] += m;
                    a[j] += m;
                    a[t_idx] -=m;
                }
            }     
            
            dbg(a); 
            
        }

        if(possible)cout<<"YES";
        else cout<<"NO";
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
        dbg(i);
        obj.solve();
        cout<<endl;
    }
    dbg(compare());
    string time = (to_string((double)(clock()-start)/CLOCKS_PER_SEC) + "s");
    dbg(time);
    return 0;
}