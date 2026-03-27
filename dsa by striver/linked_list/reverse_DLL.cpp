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
Node*reverse(Node*head){
    if(head==NULL || head->next==NULL) return head; 
    Node*prev=NULL;
    Node*current=head;
    while(current!=NULL){
        prev=current->back;
        current->back=current->next;
        current->next=prev;
        current=current->back;
    }
    return prev->back;
}
int main(){
    vector<int> arr={4,5,7,8,9,6,2,1};
    Node*head=convertarraytodll(arr);
    print(head); 
    cout<<endl;
    Node* head1=reverse(head);
    print(head1);
    return 0;
}