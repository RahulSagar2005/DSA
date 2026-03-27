#include <bits/stdc++.h>
using namespace std;
int maxRemoval(vector<int> &nums, vector<vector<int>> &queries)
{
    int q = queries.size();
    int n = nums.size();
    priority_queue<int> maxheap;                         // to store the farthest engings
    priority_queue<int, vector<int>, greater<int>> past; // past endings of queries
    sort(queries.begin(), queries.end());
    int j = 0;         // pointing to the queries
    int usedcount = 0; // how many queries i have used
    for (int i = 0; i < n; i++)
    {
        while (j < q && queries[j][0] == i)
        {
            maxheap.push(queries[j][1]);
            j++;
        }

        // first check if we can impact current i from any past queries endings
        nums[i] -= past.size();
        while (nums[i] > 0 && !maxheap.empty() && maxheap.top() >= i)
        {
            int end = maxheap.top();
            maxheap.pop();
            past.push(end);
            usedcount++;
            nums[i]--;
        }
        if (nums[i] > 0)
        {
            return -1;
        }
        // clear out past indices which are outdates
        while (!past.empty() && past.top() <= i)
        {
            past.pop();
        }
    }
    return q - usedcount;
}