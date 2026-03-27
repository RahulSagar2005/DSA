#include <bits/stdc++.h>
using namespace std;
// approach 2 without heap
int M = 1e9 + 7;
int rangeSum(vector<int> &nums, int n, int left, int right)
{
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            temp.push_back(sum);
        }
    }
    sort(temp.begin(), temp.end());
    int result = 0;
    for (int i = left - 1; i <= right - 1; i++)
    {
        result = (result + temp[i]) % M;
    }
    return result;
}
// using heap
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        int res=0;
        for(int i=1;i<=right;i++){
            auto it=pq.top();
            pq.pop();
            int sum=it.first;
            int idx=it.second;
            if(i>=left){
                res=(res+sum)%M;
            }
            pair<int,int> newp;
            int new_idx=idx+1;
            if(new_idx<n){
                newp.first=sum+nums[new_idx];
                newp.second=new_idx;
                pq.push(newp);
            }
        }
        return res;
    }