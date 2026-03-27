#include<bits/stdc++.h>
using namespace std;

vector<int> aunion(vector<int> &v1,vector<int> &v2,int n1,int n2){
    set<int> st;
    for(int i=0;i<n1;i++){
        st.insert(v1[i]);
    }
    for(int i=0;i<n2;i++){
        st.insert(v2[i]);
    }
    vector<int> un(st.size());
    int index=0;
    for(auto it:st){
        un[index]=it;
        index++;
    }
    return un;
    
}
int main(){
    int n1;
    cout<<"enter the size of the  array1...";
    cin>>n1;
    int n2;
    cout<<"enter the size of the  array2...";
    cin>>n2;
    vector<int> v1;
    for (int i=0;i<n1;i++){
        int num;
        cout<<"enter "<<i+1<<" element....";
        cin>>num;
        v1.push_back(num);
    }
    vector<int> v2;
    for (int i=0;i<n2;i++){
        int num;
        cout<<"enter "<<i+1<<" element....";
        cin>>num;
        v2.push_back(num);
    }
    vector<int> sv=aunion(v1,v2,n1,n2);
    for (auto it: sv){
        cout<<it<<" ";
    }
    return 0;
}
