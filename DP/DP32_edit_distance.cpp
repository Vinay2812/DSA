/*
link-> https://leetcode.com/problems/edit-distance/

ip->
intention
execution

op->
5

Recursion-> tc->O(3^(n*m)) sc->O(n+m)
Memoization-> tc->O(n*m) sc->O(n+m) + O(n*m)
Tabulation-> tc->O(n*m) sc-> O(n*m)
Space optimization-> tc->O(n*m) sc->O(2*m)
*/
#include<bits/stdc++.h>
using namespace std;

int f(int i, int j, string a, string b){
    if(j == 0){
        return i;
    }
    if(i == 0){
        return j;
    }
    //match
    if(a[i-1] == b[j-1]){
        return 0 + f(i-1, j-1, a, b);
    }
    else{
    //not match
        int insert = 1 + f(i, j-1, a, b);
        int del = 1 + f(i-1, j, a, b);
        int replace = 1 + f(i-1, j-1, a, b);

        return min(insert, min(del, replace));
    }
}

int minDistance(string a, string b){
    int n = a.size(), m=b.size();
    // return f(n, m, a, b);

    vector<int> prev(m+1, 0), curr(m+1, 0);

    for(int j=0;j<=m;j++)prev[j] = j;
    prev[0] = 0;

    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(j == 0){
                curr[j] = i;
            }
            else if (a[i - 1] == b[j - 1])
            {
                curr[j] =  0 + prev[j-1];
            }
            else
            {
                // not match
                int insert = 1 + curr[j-1];
                int del = 1 + prev[j];
                int replace = 1 + prev[j-1];

                curr[j] = min(insert, min(del, replace));
            }
        }
        prev = curr;
    }
    return prev[m];
}

int main()
{
    string a, b;
    cin>>a>>b;

    cout<<minDistance(a, b);
    return 0;
}