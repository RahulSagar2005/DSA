#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node *back;
    public:
    Node(int data1,Node*next1,Node*back1){
        data=data1;
        next=next1;
        back=back1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }
};
 Node* convertarraytodll(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* prev=head;
    for (int i=1;i<arr.size();i++){
        Node*temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
 }
 void print(Node*head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
Node* insert_beforehead(Node*head,int val){
    Node* newnode=new Node(val,head,nullptr);
    head->back=newnode;
    return newnode;
}
Node* insert_beforetail(Node*head,int val){
    if(head->next==NULL){
        return insert_beforehead(head,val);
    }
    Node*tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    Node*prev=tail->back;
    Node *newnode=new Node(val,tail,prev);
    prev->next=newnode;
    tail->back=newnode;
    return head;

}
Node*insert_befork(Node*head,int val,int k){
    if(k==1){
        return insert_beforehead(head,val);
    }
    Node* temp=head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            break;
        }
        temp=temp->next;
    }
    
    Node*prev=temp->back;
    Node* newnode=new Node(val,temp,prev);
    prev->next=newnode;
    temp->back=newnode;
    return head;
}
void insert_beforenode(Node* temp,int val){
Node*prev=temp->back;
Node*x=new Node(val,temp,prev);
prev->next=x;
temp->back=x;
}
int main(){
    vector<int> arr={4,5,7,8,9,6,2,1};
    Node*head=convertarraytodll(arr);
    print(head); 
    cout<<endl;
    insert_beforenode(head->next->next,16);
    print(head);
    return 0;
}