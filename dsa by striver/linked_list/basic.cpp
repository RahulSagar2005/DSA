#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    public:
    Node(int data1, Node* next1){
        data=data1;
        next=next1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};
Node* convertarr2ll(vector<int> &arr){
    Node *head=new Node(arr[0]);
    Node*mover=head;
    for(int i=1;i<arr.size();i++){
        Node*temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;

}
int lengthll(Node*head){
    int c=0;
    Node*temp=head;
    while(temp){
        temp=temp->next;
        c++;
    }
    return c;
}
Node *removehead(Node*head){
    if(head==NULL) return head;
    Node *temp=head;
    head=head->next;
    free(temp);
    return head;
}
int checkll(Node*head,int val){
    Node*temp=head;
    while(temp){
        if(temp->data==val) return 1;
        temp=temp->next;
    }
    return 0;
}
int main(){
    vector<int> arr={12,7,4,5};
    Node*head=convertarr2ll(arr);
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<lengthll(head);
    cout<<checkll(head,4);
    Node *newhead=removehead(head);
    cout<<newhead->data;
    cout<<lengthll(newhead);
    return 0;
}