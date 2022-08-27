// OJ: https://leetcode.com/problems/single-threaded-cpu/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& nums) {
        int n = nums.size(); 
        vector<int> ans;
        
        for (int i = 0; i < n; i++)
            nums[i].push_back(i);
        sort(nums.begin(), nums.end());
        priority_queue<vector<long>, vector<vector<long>>, greater<vector<long>>> pq;
        
        long idx = 1, time = 0;
        pq.push({nums[0][1], nums[0][2], nums[0][0]});
        
        while (!pq.empty()){
            auto task = pq.top();
            pq.pop();
            time = max(time, task[2]) + task[0];
            while (idx < n && time >= nums[idx][0]){
                pq.push({nums[idx][1], nums[idx][2], nums[idx][0]});
                idx++;
            }
            ans.push_back(int(task[1]));
            if (idx < n && pq.empty()){
                pq.push({nums[idx][1], nums[idx][2], nums[idx][0]});
                idx++;
            }
        }
        return ans;
    }
};
