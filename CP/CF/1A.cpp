#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #define dbg(x) cerr<<#x<<" = "<<endl;print(x);cerr<<endl;
    template <class T> void print(T v){cerr<<v;}
    template <class T> void print(vector<T> v){cerr<<"[ ";for(auto it : v){print(it);cerr<<" ";}cerr<<"]"<<endl;}
    template <class T1, class T2> void print(pair<T1, T2> v){cerr<<"[ ";print(v.ff);cerr<<" -> ";print(v.ss);cerr<<" ]"<<endl;}
    template <class T> void print(vector<vector<T>> v){cerr<<"["<<endl;for(auto it : v){cerr<<"  ";print(it);cerr<<endl;}cerr<<"]"<<endl;}
    template <class T1, class T2> void print(vector<pair<T1, T2>> v){cerr<<"["<<endl;for(auto it : v){cerr<<"  ";print(it);cerr<<endl;}cerr<<"]"<<endl;}
    template <class T1, class T2> void print(unordered_map<T1, T2> mp){for(auto it : mp){print(it.ff);cerr<<" -> ";print(it.ss);cerr<<endl;}}
    template <class T1, class T2> void print(map<T1, T2> mp){for(auto it : mp){print(it.ff);cerr<<" -> ";print(it.ss);cerr<<endl;}}
    template <class T> void print(unordered_set<T> s){cerr<<"[";for(auto it : s){print(it);cerr<<" ";}cerr<<"]"<<endl;}
    template <class T> void print(set<T> s){cerr<<"["<<endl;for(auto it : s){print(it);cerr<<endl;}cerr<<"]"<<endl;}
    bool compare(){FILE *fp1 = fopen("D:/Desktop/DSA/my.txt", "r");FILE *fp2 = fopen("D:/Desktop/DSA/output.txt", "r");char ch1 = getc(fp1);char ch2 = getc(fp2);while (ch1 != EOF && ch2 != EOF){if (ch1 != ch2)return false;ch1 = getc(fp1);ch2 = getc(fp2);}fclose(fp1);fclose(fp2);return (ch1 == EOF && ch2 == EOF);}
#else
    #define dbg(x) ;
#endif

int main(){
    fast_io;
    #ifndef ONLINE_JUDGE
        freopen("D:/Desktop/DSA/input.txt","r", stdin);
        freopen("D:/Desktop/DSA/output.txt","w", stdout);
        freopen("D:/Desktop/DSA/debug.txt","w", stderr);
    #endif
    double n, m, a;
    cin>>n>>m>>a;

    ll rc = ceil(n/a) * ceil(m/a);
    cout<<rc<<endl;

    dbg(compare());
    return 0;
}