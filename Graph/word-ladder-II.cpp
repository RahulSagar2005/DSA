# include<bits/stdc++.h>
using namespace std;
vector<vector<string>> findSequences(string beginword, string endword,
    vector<string>& wordlist) {
        
        unordered_set<string> st(wordlist.begin(),wordlist.end());
        queue<vector<string>> q;
        q.push({beginword});
        vector<string> usedonlevel;
        usedonlevel.push_back(beginword);
        int level=0;
        vector<vector<string>> ans;
        while(!q.empty()){
            vector<string> vec=q.front();
            q.pop();
            if(vec.size()>level){
                level++;
                for(auto it:usedonlevel){
                    st.erase(it);
                }
                usedonlevel.clear();
            }
            string word=vec.back();
            if(word==endword){
                if(ans.size()==0) ans.push_back(vec);
                else if( ans[0].size()==vec.size())
                ans.push_back(vec);
            }
            for(int i=0;i<word.size();i++){
                char o=word[i];
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(st.count(word)>0){
                        vec.push_back(word);
                        q.push(vec);
                        usedonlevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i]=o;
            }
        }
        return ans;
        
    }
    //optimize 
    unordered_map<string,int> mpp;
    vector<vector<string>> ans;
    int sz;
    string b;
    void dfs( string word,vector<string> &seq){
        if(word==b){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }
        int step=mpp[word];
        for(int i=0;i<sz;i++){
                char o=word[i];
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(mpp.find(word)!=mpp.end() && mpp[word]+1==step){
                        seq.push_back(word);
                        dfs(word,seq);
                        seq.pop_back();
                    }
                }
                word[i]=o;
        }
    }
    vector<vector<string>> findLadders(string beginword, string endword, vector<string>& wordlist) {
        unordered_set<string> st(wordlist.begin(),wordlist.end());
        queue<string> q;
        b=beginword;
        q.push(beginword);
        mpp[beginword]=1;
        sz=beginword.size();
        st.erase(beginword);
        while(!q.empty()){
            string word=q.front();
            int step=mpp[word];
            q.pop();
            if(word==endword) break;
            for(int i=0;i<sz;i++){
                char o=word[i];
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(st.count(word)){
                        q.push(word);
                        st.erase(word);
                        mpp[word]=step+1;
                    }
                }
                word[i]=o;
            }
        }
        if(mpp.find(endword)!=mpp.end()){
            vector<string> seq;
            seq.push_back(endword);
            dfs(endword,seq);
        }
        return ans;
    }