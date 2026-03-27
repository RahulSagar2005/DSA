#include<bits/stdc++.h>
using namespace std;
// using o(N) space complexity 
    void reverseStack(stack<int> &st) {
        // code here
        if(st.empty()) return;
        int top=st.top();
        st.pop();
        reverseStack(st);
        stack<int> temp;
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }
        st.push(top);
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
    }
// using O(1) space commplexity

    void insertatend(stack<int>&st,int el){
        if(st.empty()){
            st.push(el);
            return;
        }
        int curtop=st.top();
        st.pop();
        insertatend(st,el);
        st.push(curtop);
    }
    void reverseStack(stack<int> &st) {
        // code here
        if(st.empty()) return;
        int top=st.top();
        st.pop();
        reverseStack(st);
        insertatend(st,top);
    }
