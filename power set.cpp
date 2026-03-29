  #include<bits/stdc++.h>
  using namespace std;
  vector<string> res;
  void solve(string &temp,string &s,int idx){
      if(idx>=s.length()){
          if(temp!=""){
          res.push_back(temp);
          }
          return;
      }
      temp.push_back(s[idx]);
      solve(temp,s,idx+1);
      temp.pop_back();
      solve(temp,s,idx+1);
  }
    vector<string> AllPossibleStrings(string s) {
        // Code here
        string temp="";
        int idx=0;
        solve(temp,s,idx);
        sort(res.begin(),res.end());
        return res;
}