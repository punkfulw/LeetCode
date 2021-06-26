// OJ: https://leetcode.com/problems/3sum-closest/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        int mi = INT_MAX;
        
        for (int i = 0; i < n; i++){
            int front = i+1, back = n-1;
            int sum;
            while (front < back){
                sum = nums[i] + nums[front] + nums[back];
                int d = abs(sum - target);
                if (sum < target) front++;
                else if (sum > target) back--;
                else return target;
                if (d < mi){
                    ans = sum;
                    mi = d;
                }
            }
        }
        return ans;
    }
};
