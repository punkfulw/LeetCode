// OJ: https://leetcode.com/problems/max-consecutive-ones-iii/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(k)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        queue<int> q;
        int cnt = 0;
        
        for (int i = 0; i < nums.size(); i++){
            q.push(nums[i]);
            cnt++;
            if (nums[i] == 0){
                if (k == 0){
                    while (q.front() != 0){
                        cnt--;
                        q.pop();
                    }
                    cnt--;
                    q.pop();
                }
                else
                    k--;
            }
            ans = max(ans, cnt);
        }
        return ans; 
    }
};
