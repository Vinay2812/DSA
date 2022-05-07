#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

//directly find the nodes at distance k of target node
Node *search(Node *root,int target)
{
    if(root==NULL)
        return NULL;
    
    if(root->data==target)
        return root;
    
    Node *l=search(root->left,target);
    if(l!=NULL)
        return l;
    Node *r=search(root->right,target);
    if(r!=NULL)
        return r;
    
    return NULL;
}
void NodesInSubTree(Node *root,int d,int k){
    if(root==NULL){
        return;
    }
    if(k==d){
        cout<<root->data<<" ";
        return;
    }

    NodesInSubTree(root->left,d+1,k);
    NodesInSubTree(root->right,d+1,k);
}

int NodesInAncestorTree(Node *root,Node *target,int k){
    if(root==NULL){
        return -1;//not found then false
    }

    if(root==target){
        return 1;//found then true and send 1 becoz dist of root n target is 0
    }

    int leftDistance=NodesInAncestorTree(root->left,target,k);//if target is present in left of root
    if(leftDistance!=-1){//if target node is present in left sub tree
        if(leftDistance ==k){//which means dist b/w parent & target is k ie ldist==k
            cout<<root->data<<" ";
        }
        else
        NodesInSubTree(root->right,0,k-leftDistance-1); //target node is in left then we need to find nodes in right at k -ldist -1 distance
                                                    //leftDist represents distance between parent n target 
                                                    //we need to search in right since target is in left hence dist covered id ldist+1
                                                    //hence remaining distance is k -(ldist+1);
        return leftDistance+1;
    }

    //same above condition if target node is in right ,we need to search in left
    int rightDistance=NodesInAncestorTree(root->right,target,k);//if target is present in left of root
    if(rightDistance!=-1){
        if(rightDistance ==k){
            cout<<root->data<<" ";
        }
        else
        NodesInSubTree(root->left,0,k-rightDistance-1);
        return rightDistance+1;
    }

    return -1;
}
void NodesAtDistanceK(Node *root,int target,int k){

    Node *targetNode=search(root,target);
    if(targetNode==NULL)
        return;
    NodesInSubTree(targetNode,0,k);
    NodesInAncestorTree(root,targetNode,k);
}

int main()
{
    struct Node *root,*target;
    //level 0
    root = new Node(1);
    //level 1
    root->left = new Node(2);
    target=root->right = new Node(3);
    //level 2
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    //level 3
    root->right->right->left = new Node(8);
    root->right->left->left=new Node(9);

    /*
            1
           /\
          2  3
          /\  /\
        4  5 6   7
            /  /
           9   8 
    */

    NodesAtDistanceK(root,3,2);
    return 0;
}