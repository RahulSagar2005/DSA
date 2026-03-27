#include<bits/stdc++.h>
using namespace std;
vector<int> bubblesort(vector<int> &v){
    int n=v.size();
    for(int i=n-1;i>=0;i--){
        int didswap=0;
        for (int j=0;j<=n-1;j++){
            if(v[j]>v[j+1]){
                int temp=v[j+1];
                v[j+1]=v[j];
                v[j]=temp;
                didswap=1;
            }
        }
        if(didswap==0){
            break;
        }
        cout<<"runs\n";
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
    vector <int> sv=bubblesort(v);
    for (auto it: sv){
        cout<<it<<" ";
    }
    return 0;
}
