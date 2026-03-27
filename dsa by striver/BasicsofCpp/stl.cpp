#include<bits/stdc++.h>
using namespace std;
void expair(){
    pair <int,int> p={1,3};
    cout<<p.first<<" "<<p.second<<endl;
    pair <int,pair<int,int>> s= {1,{3,4}};
    cout<<s.first<<" "<<s.second.first<<endl;
    pair<int,int> arr[]={{1,2},{2,5},{4,5}};
    cout<<arr[0].second;
}
void exvector(){
    vector <int> v={10,50,30,40,56};
    cout<<v[2]<<" ";
    v.push_back(89);
    cout<<v[5]<<" ";
    v.emplace_back(45);
    cout<<v[6]<<" ";
    vector <pair<int,int>> v1;
    v1.push_back({1,2});
    v1.emplace_back(1,8);
    vector <int> :: iterator it=v.begin();
    cout<<*(it);
     
}

int main(){
    //expair();
    exvector();
    return 0;
}