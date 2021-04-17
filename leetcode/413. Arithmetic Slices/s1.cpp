// OJ: https://leetcode.com/problems/arithmetic-slices/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int size = nums.size();
        int ans {};
        if (size < 3){
            return 0;
        }else{
            vector<int> count {};
            int ans {};
            for (int i = 0; i < size-2; i++){
                if ((nums[i+2] - nums[i+1]) == (nums[i+1] - nums[i])){
                    int j = i;
                    int sss {3};
                    while ((j+3 < size) && (nums[j+3] - nums[j+2]) == (nums[j+2] - nums[j+1])){
                        j++;
                        sss++;
                    }
                    int temp = i;
                    i += sss-2;
                    j -= temp;
                    count.push_back(sss);
                }
            }
            for (int j = 0; j < count.size();j++){
                cout << count[j];
                for (int i = 1; i <= count[j]-2; i++){
                    ans += i;
                }
            }
            return ans;
        }    
    }
};
