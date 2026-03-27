#include<bits/stdc++.h>
using namespace std;
// brute force
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        double res=DBL_MAX;
        int n=quality.size();
        int m=wage.size();
        //i->manager 
        // j-> worker
        for(int i=0;i<n;i++){
            double mn_rat=1.0*wage[i]/quality[i];
            vector<double> gp;
            for(int j=0;j<n;j++){
                double work_wage=mn_rat*quality[j];
                if(work_wage>=wage[j]){
                    gp.push_back(work_wage);
                }
            }
            if(gp.size()<k){
                continue;
            }
            priority_queue<double> pq;
            double sum_wages=0;
            for(auto it:gp){
                sum_wages+=it;
                pq.push(it);
                if(pq.size()>k){
                    sum_wages-=pq.top();
                    pq.pop();
                }
                
            }
            res=min(res,sum_wages);
        }
        return res;
    }
// better approach 
double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        double res=DBL_MAX;
        int n=quality.size();
        int m=wage.size();
        //i->manager 
        // j-> worker
        vector<pair<double,int>> wr(n);
        for(int wk=0;wk<n;wk++){
            wr[wk]={1.0*wage[wk]/quality[wk],quality[wk]};
        }
        sort(wr.begin(),wr.end());
        for(int i=k-1;i<n;i++){
            double mn_rat=wr[i].first;
            vector<double> gp;
            for(int j=0;j<=i;j++){
                double work_wage=mn_rat*wr[j].second;
                    gp.push_back(work_wage);
            }
            priority_queue<double> pq;
            double sum_wages=0;
            for(auto it:gp){
                sum_wages+=it;
                pq.push(it);
                if(pq.size()>k){
                    sum_wages-=pq.top();
                    pq.pop();
                }
                
            }
            res=min(res,sum_wages);
        }
        return res;
    }
//optimal approach 
double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n=quality.size();
        int m=wage.size();
        double res=DBL_MAX;
        vector<pair<double,int>> wr(n);
        for(int wk=0;wk<n;wk++){
            wr[wk]={1.0*wage[wk]/quality[wk],quality[wk]};
        }
        sort(wr.begin(),wr.end());
        int sumq=0;
        priority_queue<int> pq;
        for(int i=0;i<k;i++){
            pq.push(wr[i].second);
            sumq+=wr[i].second;
        }
        
        double mn_rt=wr[k-1].first;
        res=mn_rt*sumq;
        for(int mn=k;mn<n;mn++){
            double mn_rt=wr[mn].first;
            pq.push(wr[mn].second);
            sumq+=wr[mn].second;
            if(pq.size()>k){
                sumq-=pq.top();
                pq.pop();
            }
            res=min(res,mn_rt*sumq);
        }
        return res;
    }