#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};


class Solution {
  public:
  Node * merge(Node *l1,Node *l2){
      if(!l1) return l2;
      if(!l2) return l1;
      Node *res;
      if(l1->data<l2->data){
          res=l1;
          res->bottom=merge(l1->bottom,l2);
      }
      else{
          res=l2;
          res->bottom=merge(l1,l2->bottom);
      }
      return res;
  }
    Node *flatten(Node *head) {
        if(head==NULL){
            return NULL;
        }
        Node *head2=flatten(head->next);
        return merge(head,head2);
    }
};