// OJ: https://leetcode.com/problems/create-target-array-in-the-given-order/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> ans = nums;
        for (int i = 0; i < nums.size(); i++){
            for (int j = nums.size()-1; j > index.at(i); j--){
                ans.at(j) = ans.at(j-1);
            }
            ans.at(index.at(i)) =nums.at(i);
            cout << endl;
        }   
        return ans;
    }
};
