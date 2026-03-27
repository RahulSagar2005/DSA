#include<bits/stdc++.h>
using namespace std;
int partitionindex(vector<int> &v,int low,int high){
    int pivot=v[low];
    int i=low;
    int j=high;
    while(i<j){
        while(v[i]<=pivot && i<=high-1){
            i++;
        }
        
        while(v[j]>pivot && j>=low+1){
            j--;
        }
        if(i<j){
            swap(v[i],v[j]);
        }
    }
    swap(v[low],v[j]);
    return j;
}
void quicksort(vector<int> &v,int low,int high){
    if(low<high){
        int pi=partitionindex(v,low,high);
        quicksort(v,low,pi-1);
        quicksort(v,pi+1,high);
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
    quicksort(v,0,n-1);
    for (auto it: v){
        cout<<it<<" ";
    }
    return 0;
}
