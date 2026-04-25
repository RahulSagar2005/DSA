#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n, m;

    bool can(int sec, vector<int>& nums, vector<int>& changeIndices) {
        vector<int> last(n + 1, -1);

        for (int i = 0; i <= sec; i++) {
            last[changeIndices[i]] = i;
        }

        for (int i = 1; i <= n; i++) {
            if (last[i] == -1) return false;
        }

        vector<pair<int,int>> order;
        for (int i = 1; i <= n; i++) {
            order.push_back({last[i], i});
        }

        sort(order.begin(), order.end());

        int time = 0;

        for (auto &[pos, idx] : order) {
            int need = nums[idx - 1] + 1;
            if (time + need > pos + 1) return false;
            time += need;
        }

        return true;
    }

    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        n = nums.size();
        m = changeIndices.size();

        int l = 0, r = m - 1, ans = -1;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (can(mid, nums, changeIndices)) {
                ans = mid + 1;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};