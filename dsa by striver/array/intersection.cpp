#include<bits/stdc++.h>
using namespace std;

vector<int> inter(vector<int> &v1,vector<int> &v2,int n1,int n2){
    vector<int> ans;
    int vis[n2]={0};
    for(int i=0;i<n1;i++){
        for (int j=0;j<n2;j++){
            if(v1[i]==v2[j] && vis[j]==0){
                ans.push_back(v1[i]);
                vis[j]=1;
                break;
            }
            if(v2[j]>v1[i]){
                break;
            }
            
        }
    }
    return ans;
    
}
int main(){
    int n1;
    cout<<"enter the size of the  array1...";
    cin>>n1;
    int n2;
    cout<<"enter the size of the  array2...";
    cin>>n2;
    vector<int> v1;
    for (int i=0;i<n1;i++){
        int num;
        cout<<"enter "<<i+1<<" element....";
        cin>>num;
        v1.push_back(num);
    }
    vector<int> v2;
    for (int i=0;i<n2;i++){
        int num;
        cout<<"enter "<<i+1<<" element....";
        cin>>num;
        v2.push_back(num);
    }
    vector<int> sv=inter(v1,v2,n1,n2);
    for (auto it: sv){
        cout<<it<<" ";
    }
    return 0;
}
