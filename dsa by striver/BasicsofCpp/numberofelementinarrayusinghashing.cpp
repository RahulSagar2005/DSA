#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"enter the size of array.....";
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    int hash[13]={0};
    for (int i=0;i<n;i++){
        hash[arr[i]]+=1;
    }
    for(auto it:hash){
        cout<<it<<" ";
    }
    int q;
    while(q--){
        int number;
        cin>>number;
        cout<<hash[number]<<endl;
    }
    return 0;
}