#include<bits/stdc++.h>
using namespace std;
//pass by value
void dosomething(int num){
    cout<<num<<endl;
    num+=5;
    cout<<num<<endl;
    num+=5;
    cout<<num<<endl;
}
// pass by reference
void change(string &s){
    s[0]='t';
    cout<<s<<endl;
}
int main(){
    int num=10;
    dosomething(num);
    cout<<num<<endl;
    string s="raj";
    change(s);
    cout<<s<<endl;
    return 0;   
}