class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int ar) {
        int n=capacity.size();
        vector<int> req(n,0);
        for(int i=0;i<n;i++){
            int currock=rocks[i];
            int currcap=capacity[i];
            int r=currcap-currock;
            req[i]=r;
        }
        sort(req.begin(),req.end());\
        int cnt=0;
        for(int i=0;i<n;i++){
            if(ar>=req[i]){
                ar-=req[i];
                cnt++;
            }
            else{
                break;
            }
        }
        return cnt;
    }
};