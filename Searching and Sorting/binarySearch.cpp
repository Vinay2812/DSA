#include<bits/stdc++.h>
using namespace std;

//count zeros ->  1 1 1 1 0 0 0 0

//count occurance of number -> 1 1 2 2 2 2 3 3 3    find occurence of 2

//search in rotated array   -> 5 6 7 8 1 2 3 4      search =5

// find square root &  find nth root of num

// 1 1 2 3 3 4 5 
// l   h m    h

//O(log n)

int binarySearch(vector<int> &arr,int searchEle){

    //1.Iterative
    int l=0;
    int h=arr.size()-1;
    int mid;

    while(l<=h)
    {
        mid=(l+h)/2;    //l + (h-l)/2;
        if(arr[mid]==searchEle)
            return mid;
        else if(arr[mid]<searchEle)
            l=mid+1;
        else //arr[mid]>searchEle
            h=mid-1;

    }
    return -1;
}

// 0 1 1 1 1 1 1 1 1 1    l=1,h=0  mid=1 arr[mid]=1  ans=1


//count ones
int countOnes(vector<int>arr)
{
    int n=arr.size();
    if(arr[0]==1)
    return n;
    
    int l=0;
    int h=n-1;
    int mid,ans=n;

    while(l<=h)
    {
        mid=(l+h)/2;

        // if(mid>0 && arr[mid]==1 && arr[mid-1]==0)
        //     return n-mid;
        // else if(arr[mid]==0)
        // l=mid+1;
        // else{
        // h=mid-1;
        // }

        if(arr[mid]==0)
            l=mid+1;
        else{
            ans=mid;
            h=mid-1;
        }
    }
    //cout<<ans<<" ";
    return n-ans;
    // return 0;
}

//count occurunces of x
// 1 1 2 2 2 2 4 4 4.....   find no. of x=2

int findFirst(vector<int>arr,int x)
{
    int n=arr.size();
    int l=0;
    int h=n-1;
    int mid;
    int ans=n;
    while(l<=h)
    {
        mid=(l+h)/2;

        if(arr[mid]>=x){
            ans=mid;
            h=mid-1;
        }
        else
            l=mid+1;
    }

    return ans;
}
int findLast(vector<int>arr,int x)
{
    int n=arr.size();
    int l=0;
    int h=n-1;
    int mid;
    int ans=n;
    while(l<=h)
    {
        mid=(l+h)/2;

        if(arr[mid]<=x){
              ans=mid;
             l=mid+1;
        }
        else
          h=mid-1; 
    }

    return ans;
}

int countOccurance(vector<int>arr,int x)
{
    //return findLast(arr,x) - findFirst(arr,x) +1;
    return  findFirst(arr,x+1) -findFirst(arr,x);
}

//search in an rotated array
//1 2 3 4 5 6 7 8   -> 8 1 2 3 4 5 6 7 -> 7 8 1 2 3 4 5 6......->5 6 8 1 2 3 4      ->search 6
//5 6 7 8  9  1 2 3 4 


// which range is sorted ->  l - mid  &  mid - h
//after finding my range of sorted array ->  if(my element lies in sorted range)   
int searchInRotatedArray(vector<int>arr, int x)
{
    int l=0;
    int n=arr.size();
    int h=n-1;
    int mid;

    while(l<=h)
    {
        mid=(l+h)/2;
        // 5 6 9 1 2 3 4 5
        if(arr[mid]==x)
            return mid;
        else if(arr[l]<arr[mid]){   //sorted from l to mid
            if(x>=arr[l] && x<arr[mid])
            h=mid-1;
            else
            l=mid+1;
        }
        else
        {                       //sorted from mid to h  
            if(x>arr[mid] && x<=arr[h])  //search if num lies in sorted array or not
            l=mid+1;
            else
            h=mid-1;
        }
    }
    return -1;
}


int main()
{
    //int arr[];
    
    vector<int> arr={5,6,7,8,1,2,3,4};

    // int ans=binarySearch(arr,6);

    // cout<<ans;
    //cout<<binarySearch(arr,2);

    //inbuilt
   // cout<<binary_search(arr.begin(),arr.end(),2);

   //cout<<countOnes(arr);

  //cout<<countOccurance(arr,4);

  cout<<searchInRotatedArray(arr,6);

    return 0;
}