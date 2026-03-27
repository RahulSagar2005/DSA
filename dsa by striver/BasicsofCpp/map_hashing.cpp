#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"enter the size of array....";
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    // pre-compute 
   unordered_map <int,int> mpp;
    for (int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    for (auto it:mpp){
        cout<<it.first<<"->"<<it.second<<endl;
    // this will display number->count in sorted order
    }
    int q;
    while (q--)
    {
        int number;
        cout<<"enter the to find its count...";
        cin>>number;
        //fetch
        cout<<mpp[number]<<endl;
    }
    
    return 0;
}