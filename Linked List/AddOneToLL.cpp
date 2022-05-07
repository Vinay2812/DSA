#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;

    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

/*
  1->9->9       0->0->0 
                      h      var=1  c=1;   
            //  0->0->0->1
  c=1;

  if(carry==1)tail->next=new Node(carry);

  var=(head->data+c)/10;
  head->data=(head->data+c)%10
  c=var;
  
*/

Node *reverse(Node *head)
{
    Node *p=NULL,*n=NULL;

    while(head!=NULL)
    {
        n=head->next;
        head->next=p;
        p=head;
        head=n;
    }
    return p;
}

Node *addOneToList(Node *head)
{
    if(head==NULL)return new Node(1);

    head=reverse(head);

    int carry=1,var;
    Node *start=head;

    while(carry==1)
    {
        var=(head->data+carry)/10;
        head->data=(head->data+carry)%10;
        carry=var;

        if(head->next!=NULL)
        {
                head=head->next;
        }
        else{
        if(carry==1)
            head->next=new Node(1);

            break;
        }

    }

    // if(carry==1)
    // {
    //     head->next=new Node(1);
    //     head=head->next;
    // }

    return reverse(start);

}



Node * insertAtTail(Node *head,int d)
{
    if(head==NULL)
    {
            return new Node(d);
    }
    
    Node *tail=head;

    while(tail->next!=NULL)
    {
        tail=tail->next;
    }

    tail->next=new Node(d);

    return head;
}




Node * create(vector<int>&arr)
{
    Node *head=NULL;

    for(int i=0;i<arr.size();i++)
    {
        head=insertAtTail(head,arr[i]);
    }

    return head;
}

void print(Node *head)
{
    Node *temp=head;

    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL\n";
}

int main()
{
    vector<int>arr={1,2,3};
    Node *head=create(arr);
    print(head);
    
    print(addOneToList(head));
    
}