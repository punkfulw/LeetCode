// OJ: https://leetcode.com/problems/minimum-operations-to-halve-array-sum/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int halveArray(vector<int>& v) {
        priority_queue<float> nums;
        int ans = 0;
        float sum = 0, cnt = 0;
        for (auto i: v)
        {
            sum += i;
            nums.push(i);
        }
            
        while (cnt * 2 < sum)
        {
            float cur = nums.top();
            nums.pop();
            cur /= 2;
            cnt += cur;
            nums.push(cur);
            ans++; 
        }
        return ans;  
    }
};
