#include<bits/stdc++.h>
using namespace std;


void merge(vector<int>&arr,int s,int mid,int e)
{
    int n1=mid-s +1;
    int n2=e -mid;

    int i=0;
    vector<int>arr1(n1);

    int j=0;
    vector<int>arr2(n2);

    int k=s;

    for(int i=0;i<n1;i++){
        arr1[i]=arr[s+i];
    }

    for(int j=0;j<n2;j++){
        arr2[j]=arr[mid+1+j];
    }

    while(i<n1 && j<n2)
    {
        if(arr2[j]<arr1[i])
        {
            arr[k]=arr2[j];
            k++;
            j++;
        }
        else{ //arr1[i]<arr2[j]
            arr[k]=arr1[i];
            k++;
            i++;
        }
    }

    while(i<n1)
    {
        arr[k]=arr1[i];
        k++;
        i++;
    }
    while(j<n2)
    {
        arr[k]=arr2[j];
        k++;
        j++;
    }
}
/*
arr1          arr2            arr
2 4 5 7      1 3 8 9 10       1 2 3 4 5 7 
        i        j                       k
*/
void mergeSort(vector<int>&arr ,int start,int end)
{
    if(start<end)
    {
        int mid=(start+end)/2;
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
}
int main()
{
    vector<int>arr={5,6,8,1,4,2};
    mergeSort(arr,0,arr.size()-1);

    for(auto x : arr){
        cout<<x<<" ";
    }
    return 0;
}