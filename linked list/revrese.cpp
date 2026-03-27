#include<bits/stdc++.h>
using namespace std;
class Node {
 public:
    int data ;
    Node *next ;

    Node(int x) {
        data = x ;
        next = NULL ;
    }
};
class Solution {
  public:
    Node* reverseList(Node* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        Node *last=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return last;
    }
};