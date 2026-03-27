#include<bits/stdc++.h>
using namespace std;

int linsearch(vector<int> &v,int n, int cnum){
    for(int i=0;i<n;i++){
        if(v[i]==cnum){
            return i;
        }

    }
    return -1;
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
    int cnum;
    cout<<"enter the number u wnt to check....";
    cin>>cnum;
    int b=linsearch(v,n,cnum);
    cout<<b;
    return 0;
}
