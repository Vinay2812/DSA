#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;cin>>s;

    vector<int> freq(26, 0);

    for(char c : s){
        freq[c-'A']++;
    }
    int one = 0;
    char single = '#';
    for(int i=0;i<26; i++){
        int f = freq[i];
        if(f %2 == 1){
            single =  i + 'A';
            one++;
        }

        if(one > 1){
            cout<<"NO SOLUTION"<<endl;
            return;
        }
    }
    string r1;
    for(int i=0;i<26;i++){
        int n = freq[i]/2;
        while(n--){
            r1.push_back(i+'A');
        }
    }
    string r2 = r1;
    reverse(r2.begin(), r2.end());
    if(single != '#')r1.push_back(single);

    cout<<r1 + r2<<endl;
}

int main(){
    fast_io;
    #ifndef ONLINE_JUDGE
        freopen("D:/Desktop/DSA/input.txt","r", stdin);
        freopen("D:/Desktop/DSA/output.txt","w", stdout);
    #endif
    solve();
    return 0;
}