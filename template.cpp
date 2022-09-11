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
#define nl '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#include "bits/stdc++.h"
using namespace std;

template<typename T>
class sgtree{
private:
    vector<T> seg;
    vector<T> nums;
    int n;
public:
    sgtree(vector<T>& nums){
        this->n = nums.size();
        this->nums = nums;
        seg = vector<T>(4*n+5);
        build(0, 0, n-1);
    }

    void build(int idx, int l, int r){
        if(l == r){
            seg[idx] = nums[l];
            return;
        }

        int mid = l + (r-l)/2;
        int left = 2*idx+1;
        int right = 2*idx+2;

        build(left, l, mid);
        build(right, mid+1, r);

        seg[idx] = max(seg[left], seg[right]);
    }

    void update(int idx, int l, int r, int i, T val){
        if(l == r){
            seg[idx] = val;
            nums[i] = val;
            return;
        }

        int mid = l + (r-l)/2;
        int left = 2*idx+1;
        int right = 2*idx+2;

        if(i <= mid)update(left, l, mid, i, val);
        else update(left, mid+1, r, i, val);

        seg[idx] = max(seg[left], seg[right]);
    }

    T find(int idx, int l, int r, int ql, int qr){
        if(r < ql || l > qr)return INT_MIN;
        if(l >= ql and r <= qr)return seg[idx];

        int mid = l + (r-l)/2;
        int left = 2*idx+1;
        int right = 2*idx+2;

        T left_ans = find(left, l, mid, ql, qr);
        T right_ans = find(right, mid+1, r, ql, qr);

        return max(left_ans, right_ans);
    }
};

template<typename T>
class dsu{
    vector<int> rank;
    vector<T> parent;
public:
    dsu(int n){
        rank = vector<int> (n);
        parent = vector<T> (n);
        loop(i, 0, n, 1){
            rank[i] = 0;
            parent[i] = i;
        }
    }

    T findParent(T child){
        if(parent[child] == child)return child;
        return parent[child] = findParent(parent[child]);
    }

    void makeUnion(T a, T b){
        a = findParent(a);
        b = findParent(b);

        if(rank[a] == rank[b]){
            rank[a]++;
            // parent[b] = a;
        }
        if(rank[a]< rank[b])swap(a, b);
        parent[b] = a;
        /*else if(rank[a]< rank[b]){
            parent[a] = b;
        }
        else{
            parent[b] = a;
        }*/
    }

    bool isConnected(T a, T b){
        return findParent(a) == findParent(b);
    }
}; 

template<class T1, class T2>
vector<pair<T1, T2>> vectorPair(vector<T1>& a, vector<T2>& b){
    int n = a.size();
    vector<pair<T1, T2>> v;
    for(int i=0;i<n;i++)v.push_back({a[i], b[i]});
    return v;
}

template <class T> istream& operator>>(istream& in, vector<T>& v){for(T &x : v){in>>x;}return in;}
template <class T> istream& operator>>(istream& in, vector<vector<T>>& v){for(auto &x : v){for(T &y : x)in>>y;}return in;}
template <class T1, class T2> istream& operator>>(istream& in, vector<pair<T1, T2>>& v){for(auto& P : v){in>>P.ff;in>>P.ss;}return in;}

template <class T> ostream& operator<<(ostream& out, vector<T>& v){for(T &x : v){out<<x<<" ";}return out;}
template <class T> ostream& operator<<(ostream& out, vector<vector<T>>& v){for(auto &x : v){out<<x<<nl;}return out;}

#ifndef ONLINE_JUDGE
    #define dbg(x) cerr<<#x<<" = ";print(x);cerr<<nl;
    void print();
    template <class T> void print(T v){cerr<<v;}
    template <class T> void print(vector<T> v){cerr<<"[ "<<v<<"]";}
    template <class T1, class T2> void print(pair<T1, T2> v){cerr<<"[ ";print(v.ff);cerr<<" -> ";print(v.ss);cerr<<" ]";}
    template <class T> void print(vector<vector<T>> v){cerr<<"["<<nl<<v<<"]";}
    template <class T1, class T2> void print(vector<pair<T1, T2>> v){cerr<<"["<<nl;for(auto it : v){cerr<<"  ";print(it);cerr<<nl;}cerr<<"]";}
    template <class T1, class T2> void print(unordered_map<T1, T2> mp){for(auto it : mp){print(it.ff);cerr<<" -> ";print(it.ss);cerr<<nl;}}
    template <class T1, class T2> void print(map<T1, T2> mp){for(auto it : mp){print(it.ff);cerr<<" -> ";print(it.ss);cerr<<nl;}}
    template <class T> void print(unordered_set<T> s){cerr<<"[";for(auto it : s){print(it);cerr<<" ";}cerr<<"]";}
    template <class T> void print(set<T> s){cerr<<"["<<nl;for(auto it : s){print(it);cerr<<nl;}cerr<<"]";}
    bool compare(){FILE *fp1 = fopen("D:/Desktop/DSA/IOD/my.txt", "r");FILE *fp2 = fopen("D:/Desktop/DSA/IOD/output.txt", "r");char ch1 = getc(fp1);char ch2 = getc(fp2);while (ch1 != EOF && ch2 != EOF){if (ch1 != ch2)return false;ch1 = getc(fp1);ch2 = getc(fp2);}fclose(fp1);fclose(fp2);return ch1 == EOF && ch2 == EOF;}
#else
    #define dbg(x) ;
#endif	
class Solution{
public:
    void solve(){

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
    //cin>>T;
    for(int i=1;i<=T;i++){
        obj.solve();
        cout<<nl;
    }
    dbg(compare());
    string time = (to_string((double)(clock()-start)/CLOCKS_PER_SEC) + "s");
    dbg(time);
    return 0;
}