#include<bits/stdc++.h>
using namespace  std;
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
    Node* sortedMerge(Node* l1, Node* l2) {
        // code here
        if(!l1) return l2;
        if(!l2) return l1;
        Node *res;
        if(l1->data<l2->data){
            res=l1;
            res->next=sortedMerge(l1->next,l2);
        }
        else{
            res=l2;
            res->next=sortedMerge(l1,l2->next);
        }
        return res;
        
}