#include<bits/stdc++.h>
using namespace std;
void areverse(vector<int> &v,int start,int end){
    while(start<end){
        int temp=v[start];
        v[start]=v[end];
        v[end]=temp;
        start++;
        end--;
    }
}
void leftrotate(vector<int> &v,int n,int d){
    d=d%n;
    areverse(v,0,d-1);
    areverse(v,d,n-1);
    areverse(v,0,n-1);
}
int main(){
    int n;
    cout<<"enter the size of the  array...";
    cin>>n;
    int d;
    cout<<"enter the d...";
    cin>>d;
    vector<int> v;
    for (int i=0;i<n;i++){
        int num;
        cout<<"enter "<<i+1<<" element....";
        cin>>num;
        v.push_back(num);
    }
    leftrotate(v,n,d);
    for (auto it: v){
        cout<<it<<" ";
    }
    return 0;
}
