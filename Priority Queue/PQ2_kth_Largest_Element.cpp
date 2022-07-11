#include<bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int> >pq;

    for(int it : nums){
        pq.push(it);
        if(pq.size() == k+1){
            pq.pop();
        }
    }
    return pq.top();
}

int main()
{
    return 0;
}