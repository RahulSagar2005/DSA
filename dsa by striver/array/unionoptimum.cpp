#include<bits/stdc++.h>
using namespace std;

vector<int> aunion(vector<int> &v1,vector<int> &v2,int n1,int n2){
    int i=0;
    int j=0;
    vector<int> un;
    while(i<n1 && j<n2){
        if(v1[i]<=v2[j]){
            if(un.size()==0 || un.back()!=v1[i]){
                un.push_back(v1[i]);
            }
            i++;
        }
        else{
            if(un.size()==0 || un.back()!=v2[j]){
                un.push_back(v2[j]);
        }
        j++;
    }
}
while (i<n1){
    if(un.size()==0 || un.back()!=v1[i]){
                un.push_back(v1[i]);
}
i++;
}
while (j<n2)
{
    if(un.size()==0 || un.back()!=v2[j]){
                un.push_back(v2[j]);
}
j++;
}
return un;
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
    vector<int> sv=aunion(v1,v2,n1,n2);
    for (auto it: sv){
        cout<<it<<" ";
    }
    return 0;
}
