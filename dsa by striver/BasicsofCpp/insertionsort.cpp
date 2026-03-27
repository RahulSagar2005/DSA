#include<bits/stdc++.h>
using namespace std;
vector<int> insertionsort(vector<int> &v){
    int n=v.size();
    for (int i=0;i<=n-1;i++){
        int j=i;
        while(j>0 and v[j-1]>v[j]){
            int temp=v[j];
            v[j]=v[j-1];
            v[j-1]=temp;
        j--;     
        cout<<"runs";   
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
    vector <int> sv=insertionsort(v);
    for (auto it: sv){
        cout<<it<<" ";
    }
    return 0;
}
