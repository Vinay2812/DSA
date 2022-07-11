#include<bits/stdc++.h>
using namespace std;

// Condition Reverse of sorting for priority queue
struct cmp{
    bool operator()(pair<int, int>a, pair<int, int>b){
        int a_cnt = a.second;
        int b_cnt = b.second;
        
        return a_cnt > b_cnt;
    }
};

// sort
bool static comp(pair<int, int> a, pair<int, int> b){
    int a_cnt = a.second;
    int b_cnt = b.second;
    
    if(a_cnt == b_cnt){
         return a.first < b.first;
    }
    
    return a_cnt > b_cnt;
}

vector<int> topKFrequent(vector<int>& nums, int k) {
        
    unordered_map<int, int> mpp;
    for(int it : nums){
        mpp[it]++;
    }
    
    // for(auto it : mp){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }
    
    
    //O(nlogn)
    // vector<pair<int, int>> store;
    
    // for(auto it : mp){
    //     store.push_back(it);
    // }
    
    // sort(store.begin(), store.end(), comp);
    
    // vector<int> ans;
    
    // for(int i=0;i<k;i++){
    //     ans.push_back(store[i].first);
    // }
    
    // return ans;
    
    
    // O(KlogK)
    // priority_queue<pair<int, int>> pq;//max pq
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    vector<int> ans;
    
    
    for(auto it : mpp){
        pq.push(it);
        
        if(pq.size() == k+1){
            pq.pop();
        }
    }
    
    
    while(!pq.empty()){
        ans.push_back(pq.top().first);
        pq.pop();
    }
    
    return ans;
}
int main()
{
    int n, k;
    cin>>n>>k;

    vector<int> arr(n);

    for(int i=0;i<n;i++)cin>>arr[i];

    auto ans = topKFrequent(arr, k);

    for(auto it : ans)cout<<it<<" ";
    
    return 0;
}