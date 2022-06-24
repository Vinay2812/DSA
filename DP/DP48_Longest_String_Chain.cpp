#include<bits/stdc++.h>
using namespace std;

bool cmp(string a, string b){
    return a.size() < b.size();
}

bool compare(string a, string b){
    int n = a.size(), m = b.size();
    if(n != m+1)return false;

    int i=0, j=0, cnt=0;

    while(i < n){
        if(a[i] == b[j]){
            i++;
            j++;
        }
        else{
            cnt++;
            i++;
            if(cnt == 2)return false;
        }
    }

    return j == m;
}
int longestStrChain(vector<string>& words) {
    int n = words.size();
    sort(words.begin(), words.end(), cmp); 
    vector<int> lis(n, 1);
    int maxi = 1;

    for(int i=1;i<n;i++){
        for(int pi=0;pi<i;pi++){
            if(compare(words[i] , words[pi])){
                lis[i] = max(lis[i], lis[pi]+1);
            }
        }
        maxi = max(maxi, lis[i]);
    } 

    return maxi;

}

int main()
{
    int n;cin>>n;
    vector<string> words(n);

    for(int i=0;i<n;i++){
        cin>>words[i];
    } 

    cout<<longestStrChain(words);  
    return 0;
}