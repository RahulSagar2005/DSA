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
// deletion of head
Node *removehead(Node*head){
    if(head==NULL) return head;
    Node *temp=head;
    head=head->next;
    free(temp);
    return head;
}
// deletion of tail
Node * removetail(Node*head){
    if(head==NULL) return head;
    if(head->next==NULL) return head;
    Node *temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
    return head;
}
Node *removek(Node*head,int k){
    if(head==NULL) return head;
    if(k==1){
        Node*temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    Node*temp=head;
    Node*prev=NULL;
    int cnt=1;
    while(temp!=NULL){
        if(cnt==k){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
        cnt++;
    }
    return head;
}
Node *removel(Node*head,int el){
    if(head==NULL) return head;
    if(head->data==el){
        Node*temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    Node*temp=head;
    Node*prev=NULL;
    while(temp!=NULL){
        if(temp->data==el){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
int main(){
    vector<int> arr={12,7,4,5,3,6,8,4};
    Node*head=convertarr2ll(arr);
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    Node *headk=removel(head,6);
    Node *temp1=headk;
    while(temp1){
         cout<<temp1->data<<" ";
        temp1=temp1->next;
    }
}