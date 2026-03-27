#include<bits/stdc++.h>
using namespace std;
vector<int> selectionsort(vector<int> &v){
    int n=v.size();
    for (int i=0;i<=n-2;i++){
        int mini=i;
        for (int j=i;j<=n-1;j++){
            if(v[j]<v[mini]){
                mini=j;
            }
        }
        int temp=v[mini];
        v[mini]=v[i];
        v[i]=temp;
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
    vector <int> sv=selectionsort(v);
    for (auto it: sv){
        cout<<it<<" ";
    }
    return 0;
}
