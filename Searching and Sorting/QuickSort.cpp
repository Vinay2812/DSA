#include<bits/stdc++.h>
using namespace std;

/*
if a[l]<=a[pivot]  l++

if a[h]>a[pivot]   h--;

if l<h       swap(a[l],a[h])

if l>h      swap(a[pivot],a[h])   =>pi=h
*/
int partition(vector<int>&arr,int start,int end)
{
    int l=start;
    int h=end;
    int pivot=l;
    while(l<=h)
    {
        while(arr[l]<=arr[pivot])
        l++;

        while(arr[h]>arr[pivot])
        h--;

        if(l<h)
        swap(arr[l],arr[h]);
    }

    swap(arr[pivot],arr[h]);

    return h;
}
// 5 6 7 1 2 3 4
void quickSort(vector<int>&arr,int start,int end)
{
    if(start<end)
    {
        int pi = partition(arr,start,end);
        quickSort(arr,start,pi-1);
        quickSort(arr,pi+1,end);
    }
}

int main()
{
    vector<int>arr={5,1,8,2,3,6};
    quickSort(arr,0,arr.size()-1);

    for(auto x : arr)
    {
        cout<<x<<" ";
    }

}