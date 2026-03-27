#include<bits/stdc++.h>
using namespace std;
void leftrotate(vector<int> &v,int n,int d){
    d=d%n;
    vector<int> temp(d);
    for(int i=0;i<d;i++){
        temp[i]=v[i];
    }
    for(int i=d;i<n;i++){
        v[i-d]=v[i];
    }
    for (int i=n-d;i<n;i++){
        v[i]=temp[i-(n-d)];
    }
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
