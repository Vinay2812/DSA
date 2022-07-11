#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../../input.txt","r", stdin);
        freopen("../../output.txt", "w", stdout);
#endif

    int n;cin>>n;
    int x = 0;

    for(int i=0;i<n;i++){
        string s;cin>>s;
        if(s == "X++" || s == "++X")x++;
        else x--;
    }
    cout<<x;
    return 0;
}