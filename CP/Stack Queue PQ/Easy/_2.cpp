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

string build(stack<string> st){
    string ans = "/";

    while(!st.empty()){
        ans = "/"+st.top()+ans;
        st.pop();
    }

    return ans;
}

void update(string path, stack<string>& st){
    path.push_back('/');
    int n = path.size();
    stack<string> temp;

    if(path[0] == '/'){
        while(!st.empty())st.pop();
    }
    
    string sub="";
    for(int i=0;i<n;i++){
        if(path[i] == '/'){
            if(sub.size() > 0)temp.push(sub);
            sub = "";
        }
        else if(path[i] == '.'){
            i++;
            if(temp.empty())st.pop();
            else temp.pop();
        }
        else{
            sub.push_back(path[i]);
        }
    }

    stack<string> st1, temp1;

    if(!temp.empty()){
        while(!temp.empty()){
            temp1.push(temp.top());
            temp.pop();
        }
        while(!temp1.empty()){
            st.push(temp1.top());
            temp1.pop();
        }
    }

}

string substr(int st, string s){
    int n = s.size();
    string sub;
    for(int i=st;i<n;i++)sub.push_back(s[i]);

    return sub;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../../../input.txt","r", stdin);
        freopen("../../../output.txt","w", stdout);
    #endif

    string l;
    getline(cin, l);

    ll n = stoi(l);
    stack<string> st;
    while(n--){
        string query;
        getline(cin, query);

        if(query[0] == 'p'){
            cout<<build(st)<<endl;
        }
        else{
            string path = substr(3, query);
            update(path, st);
        }
    }
    
    return 0;
}