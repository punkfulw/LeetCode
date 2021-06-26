// OJ: https://leetcode.com/problems/3sum/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/3sum/discuss/7402/Share-my-AC-C%2B%2B-solution-around-50ms-O(N*N)-with-explanation-and-comments
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n; i++){
            int target = -nums[i];
            int front = i+1, back = n-1;
            
            while (front < back){
                int sum = nums[front] + nums[back];
                if (sum < target)
                    front++;
                else if (sum > target)
                    back--;
                else{
                    vector<int> tri = {nums[i], nums[front], nums[back]};
                    ans.push_back(tri);
                    while (front < back && nums[front] == tri[1]) front++;
                    while (front < back && nums[back] == tri[2]) back--;
                }
            }
            while (i < n-1 && nums[i] == nums[i+1])
                i++;
        }
        return ans;
    }
};

