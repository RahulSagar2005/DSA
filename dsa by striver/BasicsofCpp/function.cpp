#include<bits/stdc++.h>
using namespace std;
void printname(){
    cout<<"hey rahul";
}
void printname(string name){
    cout<<"hey "<<name;
}
int sum(int n1, int n2){
    int n3=n1+n2;
    return n3;
}
int maximum(int n1,int n2,int n3){
    if(n1>n2 && n1>n3){
        return n1;
    }
    else if (n2>n3){
        return n2;
    }
    else{
        return n3;
    }
}
int main(){
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    string name;
    //cin>>name;
    //printname();
    //printname(name);
    int res=maximum(n1,n2,n3);
    cout<<res;
    return 0;
}