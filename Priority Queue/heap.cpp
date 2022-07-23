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

template<class T>
class heap{
private:
    vector<T> nums;
    int n;
public:
    heap(){
        n = 0;
    }

    void heapify(int idx){
        if(idx >= n)return;

        int left = 2*idx+1;
        int right = 2*idx+2;
        heapify(left);
        heapify(right);
        
        if(left < n){
            if(nums[left] > nums[idx])swap(nums[left], nums[idx]);
        }
        if(right < n){
            if(nums[right] > nums[idx])swap(nums[right], nums[idx]);
        }
    }
    bool empty(){
        return n == 0;
    }

    bool size(){
        return n;
    }

    T top(){
        return (n>0)?nums[0]:-1;
    }

    void insert(T val){
        nums.push_back(val);
        n++;
        heapify(0);
    }

    void pop(){
        swap(nums[0], nums[n-1]);
        nums.pop_back();
        n--;
        heapify(0);
    }

};

template<class T>
class heap_sort{
private:
    int n;
public:
    heap_sort(vector<T>& nums){
        this->n = nums.size();
        if(n>1){
            heapify(0, nums);
            sort(nums);
        }
    }

    bool empty(){
        return n == 0;
    }

    void pop(vector<int>& nums){
        //heapify
        swap(nums[0], nums[n-1]);
        n--;
        heapify(0, nums);
    }

    void heapify(int idx, vector<T>& nums){
        if(idx >= n)return;

        int left = 2*idx+1;
        int right = 2*idx+2;
        heapify(left, nums);
        heapify(right, nums);
        
        if(left < n){
            if(nums[left] > nums[idx])swap(nums[left], nums[idx]);
        }
        if(right < n){
            if(nums[right] > nums[idx])swap(nums[right], nums[idx]);
        }
    }

    void sort(vector<int>& nums){
        while(n>1){
            pop(nums);
        }
    }
};


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt","r", stdin);
        freopen("../output.txt","w", stdout);
    #endif

    ll n;cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];

    // heap<int> hp;
    // for(int i=0;i<n;i++){
    //     hp.insert(nums[i]);
    // }

    // while(!hp.empty()){
    //     cout<<hp.top()<<" ";
    //     hp.pop();
    // }

    heap_sort<int> hp(nums);

    for(auto it : nums)cout<<it<<" ";
    return 0;
}