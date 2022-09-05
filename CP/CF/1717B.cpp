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

class Solution{
public:
    void solve(){
        int n, k, r, c;
        cin>>n>>k>>r>>c;
        r--;c--;
        vector<vector<int>> ans(n, vector<int>(n, 0));
        for(int i=0;i<n;i+=k){
            for(int j=0;j<n;j+=k){
                vector<int> row(k+1, 0), col(k+1, 0);
                if(r >= i and r < i+k and c >= j and c < j+k){
                    row[r%k] = 1;col[c%k] = 1; 
                }

                for(int x = i; x < i+k; x++){
                    for(int y = j; y < j+k; y++){
                        if(x == r and y == c)ans[x][y] = 1;
                        else if(row[x%k] || col[y%k])continue;
                        else{
                            ans[x][y] = 1;
                            row[x%k] = 1;
                            col[y%k] = 1;
                        }
                    }
                    
                }
            }
        }

        for(auto x : ans){
            for(auto y: x){
                if(y == 1)cout<<"X";
                else cout<<".";
            }
            cout<<endl;
        }
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
        // cout<<endl;
    }
    return 0;
}