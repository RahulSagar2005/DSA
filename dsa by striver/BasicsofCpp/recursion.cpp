#include<bits/stdc++.h>
using namespace std;
void f(int n){
    if (n==0) return;
    cout<<n<<endl;
    f(n-1);
}
// Online C++ compiler to run C++ program online
void rev(int arr[],int i,int n){
    if(i>=n/2) return;
    swap(arr[i],arr[n-i-1]);
    rev(arr,i+1,n);
}
bool pallindrome(string &s,int i,int n){
    if(i>=n/2) return true;
    if(s[i]!=s[n-i-1]){
        return false;
    }
    pallindrome(s,i+1,5);
}
int fib(int n){
    if (n==1){
            return 1;
        }
        return fib(n-1)+fib(n-1);
}
int main(){
    int n=10;
    int arr[5]={1,2,3,4,5};
    string s="MADAM";
    //int b=pallindrome(s,0,5);
    //cout<<b;
    //rev(arr,0,5);
    // for(auto it:arr){
    //     cout<<it<<" ";
    // }
    //f(n);
    int res=fib(3);
    cout<<res;
    return 0;
}