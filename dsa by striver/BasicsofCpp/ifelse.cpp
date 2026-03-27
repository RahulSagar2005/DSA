#include<bits/stdc++.h>
using namespace std;
int main(){
    int marks;
    cout<<"enter your marks...";
    cin>>marks;
    if (marks>=80 && marks<=100){
        cout<<"Grade A";
    }
    else if(marks>=60 && marks<=79){
        cout<<"Grade B";
    }
    else if(marks>=50 && marks<=59){
        cout<<"Grade C";
    }
    else if(marks>=45 && marks<=49){
        cout<<"Grade D";
    }
    else if(marks>=25 && marks<=44){
        cout<<"Grade E";
    }
    else{
        cout<<"Grade F";
    }
    return 0;
}