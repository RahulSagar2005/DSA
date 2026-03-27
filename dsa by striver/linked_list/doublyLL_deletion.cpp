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
 Node* deletehead(Node*head){
    if(head==NULL 
    || head->next==NULL){
        return NULL;
    }
    Node* prev=head;
    head=head->next;
    head->back=nullptr;
    prev->next=nullptr;
    return head;
 }
 Node *deletetail(Node*head){
    Node*tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    Node*prev=tail->back;
    prev->next=nullptr;
    tail->back=nullptr;
    delete tail;
    return head;
 }
 Node* removek(Node*head,int k){
    if(head==NULL) return NULL;
    int cnt=0;
    Node*temp=head;
    while(temp!=NULL){
        cnt++;
        if(cnt==k) break;
        temp=temp->next;
    }
    Node *prev=temp->back;
    Node *front=temp->next;
    if(prev==NULL && front==NULL){
        return NULL;
    }
    else if(prev==NULL){
        return deletehead(head);
    }
    else if(front==NULL){
        return deletetail(head);
    }
    prev->next=front;
    front->back=prev;
    temp->next=nullptr;
    temp->back=nullptr;
    delete temp;
    return head;
 }
void deletenode(Node*temp){
    Node*prev=temp->back;
    Node* front=temp->next;
    if(front==NULL){
        prev->next=nullptr;
        temp->back=nullptr;
        free(temp);
        return;
    }
    prev->next=front;
    front->back=prev;
    temp->next=nullptr;
    temp->back=nullptr;
    free(temp);
}
int main(){
    vector<int> arr={4,5,7,8,9,6,2,1};
    Node*head=convertarraytodll(arr);
    print(head); 
    cout<<endl;

    deletenode(head->next->next);
    print(head);
    return 0;
}