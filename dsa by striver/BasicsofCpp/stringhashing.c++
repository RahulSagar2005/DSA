#include <bits/stdc++.h>
using namespace std;
int main(){
    string s="abacdaefghcda";
    int n=s.size();
    int shash[26]={0};
    for(int i=0;i<n;i++){
        shash[s[i]-'a']++;
    }
    int q;
    while (q--)
    {
        char c;
        cout<<"enter character....";
        cin>>c;
        cout<<shash[c-'a']<<endl;
    }
    return 0;
}
// if no condition is mentioned initialize shash[256] and no need of suubtraction of 'a' also