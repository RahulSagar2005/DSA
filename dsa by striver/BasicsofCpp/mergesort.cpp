#include<bits/stdc++.h>
using namespace std;
void merge(vector<int> &v,int low,int mid,int high){
    vector<int> temp;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high){
        if (v[left]<=v[right]){
            temp.push_back(v[left]);
            left++;
        }
        else{
            temp.push_back(v[right]);
                right++;
            }
        }
    
    while(left<=mid){
        temp.push_back(v[left]);
            left++;
    }
    while(right<=high){
        temp.push_back(v[right]);
                right++;
}
for (int i=low;i<=high;i++)
{
    v[i]=temp[i-low];
}

}
void mergesort(vector<int> &v,int low,int high){
    if (low>=high){
        return;
    }
    int mid=(low+high)/2;
    mergesort(v,low,mid);
    mergesort(v,mid+1,high);
    merge(v,low,mid,high);
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
    mergesort(v,0,n-1);
    for (auto it: v){
        cout<<it<<" ";
    }
    return 0;
}
