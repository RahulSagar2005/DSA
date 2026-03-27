#include<bits/stdc++.h>
using namespace std;
void pattern1(int n){
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
void pattern2(int n){
    for (int i=0;i<n;i++){
        for (int j=0;j<=i;j++){
            cout<<"* ";
        }
        cout<<"\n";
    }
}
void pattern3(int n){
    for (int i=1;i<=n;i++){
        for (int j=1;j<=i;j++){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}
void pattern4(int n){
    for (int i=1;i<=n;i++){
        for (int j=1;j<=i;j++){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
}
void pattern5(int n){
    for (int i=0;i<n;i++){
        for (int j=0;j<n-i;j++){
            cout<<"* ";
        }
        cout<<"\n";
    }
}
void pattern6(int n){
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n-i+1;j++){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}
void pattern7(int n){
    for (int i=0;i<n;i++){
        for (int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        for (int k=0;k<2*i+1;k++){
            cout<<"*";
        }
        for (int l=0;l<n-i-1;l++){
            cout<<" ";
        }
        cout<<"\n";
    }
}
void pattern8(int n){
    for (int i=0;i<n;i++){
        for (int j=0;j<i;j++){
            cout<<" ";
        }
        for (int k=0;k<(2*n-(2*i+1));k++){
            cout<<"*";
        }
        for (int l=0;l<i;l++){
            cout<<" ";
        }
        cout<<"\n";
    }
}
void pattern10(int n){
    for (int i=1;i<=2*n-1;i++){
        int stars=i;
        if(i>n){
            stars=2*n-i;
        }
        for (int j=1;j<=stars;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
void pattern11(int n){
    int start=1;
    for (int i=0;i<n;i++){
        if(i%2==0){
            start=1;
        }
        else{
            start=0;
        }
        for (int j=0;j<=i;j++){
            cout<<start;
            start=1-start;
        }
        cout<<endl;
    }
}
void pattern12(int n){
    for (int i=1;i<=n;i++){
        int j;
        for(j=1;j<=i;j++){
            cout<<j;
        }
        for(int k=1;k<=(2*n-2*i);k++){
            cout<<" ";
        }
        for (int l=j-1;l>0;l--){
            cout<<l;
        }
        cout<<endl;
    }
}
void pattern13(int n){
    int c=1;
    for (int  i=0;i<n;i++){
        for (int j=0;j<=i;j++){
            cout<<c<<" ";
            c++;
        }
        cout<<endl;
    }
}
void pattern14(int n){
    for (int i=0;i<n;i++){
        for(char ch='A';ch<='A'+i;ch++){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}
void pattern15(int n){
    for (int i=0;i<n;i++){
        for (char ch='A';ch<'A'+n-i;ch++){
            cout<<ch<<" ";
        }  
        cout<<endl; 
    }
}
void pattern16(int n){
    for (char ch1='A';ch1<'A'+n;ch1++){
        for (char ch='A';ch<='A'+int(ch1)-65;ch++){
            cout<<ch1;
        }
        cout<<endl;
}
}
void pattern17(int n){
    for (int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        char ch='A';
        int breakpoint=(2*i+1)/2;
        for (int k=1;k<=2*i+1;k++){
            cout<<ch;
            if(k<=breakpoint){
                ch++;
            }
            else{
                ch--;
            }
        }
        for(int l=0;l<n-i-1;l++){
            cout<<" ";
        }
    cout<<endl;
}
}
void pattern18(int n){
    for (int i=0;i<n;i++){
        char ch='A'+n-i-1;
        for (int j=0;j<=i;j++){
            cout<<ch;
            ch++;
            
        }
        cout<<endl;
    }
}
void pattern19(int n){
    for (int i=0;i<n;i++){
    //stars
    for(int j=0;j<n-i;j++){
        cout<<"*";
    }
    //space
    for (int k=0;k<2*i;k++){
        cout<<" ";
    }
    //stars
    for(int l=0;l<n-i;l++){
        cout<<"*";
    }
    cout<<endl;
    }
    //***************************
    for (int i=0;i<n;i++){
    //stars
    for(int j=0;j<=i;j++){
        cout<<"*";
    }
    //space
    for (int k=0;k<(2*n-2*(i+1));k++){
        cout<<" ";
    }
    //stars
    for(int l=0;l<=i;l++){
        cout<<"*";
    }
    cout<<endl;
    }
}
void pattern20(int n){
    int space=2*n-2;
    for (int i=1;i<=2*n-1;i++){
        int star=i;
        if(i>n) star=2*n-i;
        //stars
        for (int j=1;j<=star;j++){
            cout<<"*";
        }
        //space
        for(int j=1;j<=space;j++){
            cout<<" ";
        }
        // stars
        for (int l=1;l<=star;l++){
            cout<<"*";
        }
        cout<<endl;
        if (i<n) space-=2;
        else space+=2;
        }
}
void pattern21(int n){
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (i==0|| i==n-1|| j==0||j==n-1){
                cout<<"*";
            }
            else{
            cout<<" ";
        }
    }cout<<endl;
}}
void pattern22(int n){
    for (int i=0;i<2*n-1;i++){
        for (int j=0;j<2*n-1;j++){
            int top=i;
            int left=j;
            int right=(2*n-2)-j;
            int bottom=(2*n-2)-i;
            cout<<(n-min(min(top,bottom),min(left,right)));
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    // pattern1(n);  
    // cout<<endl;
    // pattern2(n);
    // cout<<endl;
    // pattern3(n);
    // cout<<endl;
    // pattern4(n);
    // cout<<endl;
    // pattern5(n);
    // cout<<endl;
    // pattern6(n);
    // pattern7(n);
    // pattern8(n);
    //pattern10(n);
    //pattern11(n);
    //pattern12(n);
    //pattern13(n);
    //pattern14(n);
    //pattern15(n);
    //pattern16(n);
    //pattern17(n);
    //pattern18(n);
    //pattern19(n);
    //pattern20(n);
    //pattern21(n);
    pattern22(n);
    return 0;
}