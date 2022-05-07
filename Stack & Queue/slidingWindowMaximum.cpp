#include<iostream>
#include<deque>
#include<vector>
using namespace std;

vector<int> maximumInK(vector<int> arr,int k)
{
    deque<int>dq;
    vector<int>ans;

    int n=arr.size();

    for(int i=0;i<k;i++)
    {
        while(!dq.empty() && arr[i]>arr[dq.back()])
            dq.pop_back();

        dq.push_back(i);
    }

    int s=0;
    ans.push_back(arr[dq.front()]);

    for(int i=k;i<n;i++)
    {
        if(s == dq.front()) //if dq.size() == k {case : 3 2 1 .. and incoming -1 and k = 3}
            dq.pop_front(); // since it has reaches size k ..we need to pop ...which will be front
        s++;

        while(!dq.empty() && arr[i]>arr[dq.back()])
            dq.pop_back();

        dq.push_back(i);

        ans.push_back(arr[dq.front()]);
    }  

    return ans;  

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int>arr = {2,3,-1,8,2,-3,7,-4,2,4};
    int k=3;
    auto ans = maximumInK(arr,k);

    for(int x : ans)
    {
        cout<<x<<" ";
    }
    return 0;
}