// OJ: https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        
        while (k){
            auto n = pq.top();
            pq.pop();
            if (n < 0)
                pq.push(-n);
            else{
                if (k % 2)
                    pq.push(-n);
                else
                    pq.push(n);
                break;
            }
            k--;
        }
        int ans = 0;
        while (!pq.empty()){
            auto i = pq.top();
            pq.pop();
            ans += i;
        }
        return ans;
    }
};
