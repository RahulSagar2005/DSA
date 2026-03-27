#include<bits/stdc++.h>
using namespace std;
void change(int arr[],int n){
    arr[0]+=100;
    cout<<"Inside the function "<<arr[0]<<endl;
}
int main(){
    int n=5;
    int arr[n];
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    for (int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    change(arr,n);
    cout<<"Inside the main "<<arr[0]<<endl;
    return 0;
}