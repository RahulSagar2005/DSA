#include<bits/stdc++.h>
using namespace std;

vector<int>  movezero(vector<int> &v,int n){
    int j=-1;
    for (int i=0;i<n;i++){
        if(v[i]==0){
            j=i;
            break;
        }
    }
    // no non zero number
    if(j==1) return v;
    for (int i=j+1;i<n;i++){
        if(v[i]!=0){
            swap(v[i],v[j]);
            j++;
        }
    }
    return v;
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
    vector<int> sv=movezero(v,n);
    for (auto it:sv){
        cout<<it<<" ";
    }
    return 0;
}
