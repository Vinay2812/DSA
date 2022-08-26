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
#define sum_n(res,a) res=0; for(ll x:a) res+=x;
#define dbg(x) cout<<#x<<" = "<<x<<endl;

#include<bits/stdc++.h>
using namespace std;

fstream my;
fstream correct;

bool compare(){
    string my_ans = "";
    string correct_ans = "";

    my.open("my.txt", ios::in);
    string temp ="";
    while(getline(my, temp)){
        my_ans += (temp+"\n");
    }
    my.close();

    correct.open("correct.txt", ios::in);
    temp = "";
    while(getline(correct, temp)){
        correct_ans += (temp+"\n");
    }
    correct.close();
    return correct_ans == my_ans;
}

int f(int s,int e,vector<int>&arr){
    int curr=0,maxi=-1e9;
    for(int i=s;i<e;i++){
        curr+=arr[i];
        maxi=max(maxi,curr);
        if(curr<0) curr=0;
    }
    return maxi;
}

int solve1(vector<int>&arr,int n,int k){
    int ans=-1e9;
    int left=0,right=0;
    for(int i=0;i<n;i++){
        if(i+k+1>=n) break;
        left=f(0,i+1,arr);
        // left=max(arr[i],left+arr[i]);
        right=f(i+k+1,n,arr);
        ans=max(ans,left+right);
    }
    return ans;
}

int solve2(vector<int>&arr,int n,int k){
    int ans=-1e9;
    int left=0,right=0;

    vector<int> prefix(n, 0), suffix(n, 0);
    prefix[0] = arr[0];
    int curr = 0, maxi = arr[0];
    if(arr[0] < 0)curr = 0;
    else curr = arr[0];

    for(int i=1;i<n;i++){
        curr += arr[i];
        maxi = max(maxi, curr);
        prefix[i] = maxi;

        curr = (curr<0)?0:curr;
    }

    curr = (arr[n-1] < 0)?0:arr[n-1];
    suffix[n-1] = arr[n-1];
    maxi = arr[n-1];
    for(int i=n-2;i>=0;i--){
        curr += arr[i];
        maxi = max(maxi, curr);
        suffix[i] = maxi;

        curr = (curr < 0) ? 0 : curr;
    }

    for(int i=0;i<n;i++){
        if(i+k+1>=n) break;
        // left=f(0,i+1,arr);
        left=prefix[i];
        right = suffix[i+k+1];
        ans=max(ans,left+right);
    }
    return ans;
}
void myAns(int N, int K, vector<int>& nums){
    my.open("my.txt", ios::out);
    my<<solve2(nums, N, K);
    my.close();
}


void correctAns(int N, int K, vector<int>& nums){
    correct.open("correct.txt", ios::out);
    correct<<solve1(nums, N, K);
    correct.close();
}
int debug(){
    // Generate random test cases
    int N = rand()%8+1;
    int K = rand()%5+1;
    vector<int> nums(N);

    for(auto &it : nums)it = rand()%10 + 1;
    //if returns single variable
    myAns(N, K, nums);
    correctAns(N, K, nums);

    if(compare() == false){
        my.open("my.txt", ios::app);

        my<<"#test-case\n";
        my<<N<<" "<<K<<endl;
        for(auto it : nums)my<<it<<" ";

        my.close();
        return 1;
    }
    return 0;
}

int main()
{
    srand(time(NULL));//to get every time different output
    ll n = 10000;
    while(n--)
        if(debug())break;

    return 0;
}












































































