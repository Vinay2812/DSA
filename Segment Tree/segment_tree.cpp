#include<bits/stdc++.h>
using namespace std;

class SGTree{
private:
    vector<int> segment;
public:
    SGTree(int n){
        segment.resize(4*n + 1, -1);
    }
    void print(){
        for(auto it : segment)cout<<it<<" ";
        cout<<endl;
    }
    void build(int idx, int l, int h, vector<int>& arr){
        if(l == h){
            segment[idx] = arr[l];
            return; 
        }

        int mid = l + (h-l)/2;
        //left
        build(2*idx + 1, l, mid, arr);
        build(2*idx + 2, mid+1, h, arr);

        segment[idx] = min(segment[2*idx+1], segment[2*idx+2]);
    }

    void update(int idx, int i, int val, int l, int h, vector<int>& arr){
        if(l == h){
            segment[idx] = val;
            arr[i] = val;
            return;
        }

        int mid = l + (h-l)/2;

        if(i <= mid){
            update(2*idx+1, i, val, l, mid, arr);
        }
        else{
            update(2*idx+2, i, val, mid + 1, h, arr);
        }

        segment[idx] = min(segment[2*idx+1], segment[2*idx+2]);
    }

    int find(int idx, int l, int h, int ql, int qh){
        //find for overlapping
        /*
        1->Entire overlap: __ql__l__h___qh__
           cant further subdivide range
           hence op-> seg[idx]
        2->No overlap: __ql__qh__l___h__
                                OR
                       ___l___h___ql____qh__
            hence op-> no solution possible return INT_MAX
        3->Partial overlap: ___ql__l__qh__h___
                                OR
                            ___l___ql___h___qh__
            So find min from left & right of tree 
        */ 

       if(l>=ql and h<= qh){
            return segment[idx];
       }

       if(h<ql || l>qh)return 1e9;

       int mid = l + (h-l)/2;

       int left = find(2*idx+1, l, mid, ql, qh);
       int right = find(2*idx+2, mid+1, h, ql, qh);

       return min(left, right);
    }

};

int main()
{
    int n;cin>>n;
    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int l, r;
    SGTree sg(n);
    sg.build(0, 0, n-1, arr);
    cin>>l>>r;
    cout<<sg.find(0, 0, n-1, l, r);
    return 0;
}