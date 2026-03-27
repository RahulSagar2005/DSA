#include<bits/stdc++.h>
using namespace std;

void movezero(vector<int> &v,int n){
    vector <int> temp;
    for(int i=0;i<n;i++){
        if(v[i]!=0){
            temp.push_back(v[i]);
        }
    }
    for(int i=0;i<temp.size();i++){
        v[i]=temp[i];
    }
    for(int i=temp.size();i<n;i++){
        v[i]=0;
    }
}
int main(){
    int n;
    cout<<"enter the size of the  array...";
    cin>>n;
    vector<int> v;
    for (int i=0;i<n;i++){
        int num;
        cout<<"enter "<<i+1<<" element....";
        cin>>num;
        v.push_back(num);
    }
    movezero(v,n);
    for (auto it: v){
        cout<<it<<" ";
    }
    return 0;
}
