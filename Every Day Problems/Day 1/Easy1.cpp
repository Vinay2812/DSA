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
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* build(ll n){
    Node *head = NULL, *tail;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        if(head == NULL){
            head = new Node(x);
            tail = head;
        }
        else{
            tail->next = new Node(x);
            tail = tail->next;
        }
    }
    return head;
}

void print(Node* head){
    while(head->next){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<head->data<<endl;
}

Node *segregate(Node *head){
    Node* zero = new Node(-1);
    Node* one = new Node(-1);
    Node* two = new Node(-1);

    Node* zt = zero;
    Node* ot = one;
    Node* tt = two;

    while(head){
        if(head -> data == 0){
            zt->next = head;
            zt = zt->next;
        }
        else if(head -> data == 1){
            ot->next = head;
            ot = ot -> next;
        }
        else{
            tt -> next = head;
            tt = tt -> next;
        }
        head = head->next;
    }

    tt->next = NULL;
    ot->next = two->next;
    zt->next = one->next;

    return zero->next;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../../input.txt","r", stdin);
        freopen("../../output.txt","w", stdout);
    #endif
    ll n;
    cin>>n;

    Node* head = build(n);
    print(head);
    head = segregate(head);
    print(head);
    
    return 0;
}