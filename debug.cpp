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

void myAns(vector<int>& nums){
    my.open("my.txt", ios::out);
    ll mini = 1e18, maxi = -1e18, min_idx = -1, max_idx = -1, n = nums.size();

    for(int i=0;i<n;i++){
        if(nums[i] > maxi){
            maxi = nums[i];
            max_idx = i;
        }

        if(nums[i] <= mini){
            mini = nums[i];
            min_idx = i; 
        }
    }
    ll ans = 0;
    ans = max_idx + n - 1 - min_idx;
    my<< ans <<endl;
    my.close();
}

void correctAns(vector<int>& nums){
    correct.open("correct.txt", ios::out);
    ll mini = 1e18, maxi = -1e18, min_idx = -1, max_idx = -1, n = nums.size();

    for(int i=0;i<n;i++){
        if(nums[i] > maxi){
            maxi = nums[i];
            max_idx = i;
        }

        if(nums[i] <= mini){
            mini = nums[i];
            min_idx = i; 
        }
    }
    ll ans = 0;
    if(min_idx < max_idx){
        ans = max_idx + n - 1 - min_idx - 1;
    }
    else{
        ans = max_idx + n - 1 - min_idx;
    }

    correct<<ans<<endl;
    correct.close();
}
int debug(){
    // Generate random test cases
    ll n = rand()%10+5;//gets random size from 1 to 10
    vi nums(n);
    for(int i=0;i<n;i++){
        nums[i] = rand()%20 + 1;// gets random no. from 1 to 20
    }
    //if returns single variable
    myAns(nums);
    correctAns(nums);

    if(compare() == false){
        my.open("my.txt", ios::app);

        my<<"#test-case\n";
        my<<n<<endl;
        for(auto it : nums)my<<it<<" ";

        my.close();
        return 1;
    }
    return 0;
}

int main()
{
    srand(time(NULL));//to get every time different output
    ll n = 1000;
    while(n--)
        if(debug())break;

    return 0;
}












































































