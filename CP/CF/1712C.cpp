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
template <class T> void input(vector<T> nums[], int n){for(int i=0;i<n;i++)input(nums[i]);}
template <class T> void input(vector<vector<T>>& nums){int n = nums.size(), m = nums[0].size();for(int i=0;i<n;i++)for(int j=0;j<m;j++)input(nums[i][j]);}
template <class T1, class T2> void input(vector<pair<T1, T2>>& v){int n = v.size();for(int i=0;i<n;i++){T1 x;T2 y;input(x);input(y);v[i] = {x, y};}}

#ifndef ONLINE_JUDGE
    #define dbg(x)  cerr<<#x<<" = ";print(x);cerr<<endl;
    void print(){cerr<<endl;}
    template <class T> void print(T v){cerr<<v;}
    template <class T> void print(vector<T> v){cerr<<"[ ";for(auto it : v){print(it);cerr<<" ";}cerr<<"]";}
    template <class T1, class T2> void print(pair<T1, T2> v){cerr<<"[ ";print(v.ff);cerr<<" -> ";print(v.ss);cerr<<" ]";}
    template <class T> void print(vector<vector<T>> v){cerr<<"["<<endl;for(auto it : v){cerr<<"  ";print(it);cerr<<endl;}cerr<<"]";}
    template <class T1, class T2> void print(vector<pair<T1, T2>> v){cerr<<"["<<endl;for(auto it : v){cerr<<"  ";print(it);cerr<<endl;}cerr<<"]";}
    template <class T1, class T2> void print(unordered_map<T1, T2> mp){cerr<<endl;for(auto it : mp){print(it.ff);cerr<<" -> ";print(it.ss);cerr<<endl;}}
    template <class T1, class T2> void print(map<T1, T2> mp){cerr<<endl;for(auto it : mp){print(it.ff);cerr<<" -> ";print(it.ss);cerr<<endl;}}
    template <class T> void print(unordered_set<T> s){cerr<<"[ ";for(auto it : s){print(it);cerr<<" ";}cerr<<"]";}
    template <class T> void print(set<T> s){cerr<<"[ "<<endl;for(auto it : s){print(it);cerr<<endl;}cerr<<"]";}
    bool compare(){FILE *fp1 = fopen("D:/Desktop/DSA/my.txt", "r");FILE *fp2 = fopen("D:/Desktop/DSA/output.txt", "r");char ch1 = getc(fp1);char ch2 = getc(fp2);while (ch1 != EOF && ch2 != EOF){if (ch1 != ch2)return false;ch1 = getc(fp1);ch2 = getc(fp2);}fclose(fp1);fclose(fp2);return ch1 == EOF && ch2 == EOF;}
#else
    #define dbg(x) ;
#endif

class Solution{
public:
    void solve(){
        int n;input(n);
        vector<int> nums(n);input(nums);
        unordered_set<int> remove, unique;
        bool r = false;
        int i = n-2;
        for(i=n-2;i>=0;i--){
            if(nums[i] > nums[i+1]){
                r = true;
            }
            if(r)remove.insert(nums[i]);
        }
        dbg(remove);
        for(i=n-1;i>=0;i--){
            if(remove.count(nums[i]) > 0){
                while(i >= 0)unique.insert(nums[i--]);
            }
            
        }
        dbg(unique);
        cout<<unique.size();
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

    ll T=1;
    input(T);
    Solution obj;
    for(int i=1;i<=T;i++){
        dbg(i);
        obj.solve();
        dbg();
        cout<<endl;
    }
    dbg(compare());
    return 0;
}