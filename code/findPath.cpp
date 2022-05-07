#include<iostream>
using namespace std;

int numOfPaths(int n,int m){
    if(n<0 || m<0)return -1;
    if(n==0 && m==0)return 1;

    int sum=0;
    int l=numOfPaths(n-1,m);
    if(l!=-1)sum+=l;
    int r=numOfPaths(n,m-1);
    if(r!=-1)sum+=r;

    return sum;
}
int main(){
    int n,m;
    cin>>n>>m;
    cout<<numOfPaths(n,m);
    return 0;
}