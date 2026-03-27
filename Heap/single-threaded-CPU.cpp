    #include<bits/stdc++.h>
    using namespace std;
    
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<array<int,3>> st;
        int n=tasks.size();
        for(int i=0;i<n;i++){
            int starttime=tasks[i][0];
            int duration=tasks[i][1];
            st.push_back({starttime,duration,i});
        }
        sort(st.begin(),st.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        long long currtime=0;
        int idx=0;
        vector<int> result;
        while(idx<n || !pq.empty()){
            if(pq.empty() && currtime<st[idx][0]){
                currtime=st[idx][0];
            }
            while(idx<n && currtime>=st[idx][0]){
                pq.push({st[idx][1],st[idx][2]});
                idx++;
            }
            pair<int,int> currtask=pq.top();
            pq.pop();
            currtime+=currtask.first;
            result.push_back(currtask.second);
        }
        return result;
    }