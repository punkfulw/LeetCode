// OJ: https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/
// Author: github.com/punkfulw
// Reference: https://github.com/lzl124631x/LeetCode/edit/master/leetcode/1769.%20Minimum%20Number%20of%20Operations%20to%20Move%20All%20Balls%20to%20Each%20Box/README.md
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size(), right = 0, left = 0, sum = 0;
        vector<int> ans (n);
        
        for (int i = 0; i < n; i++){
            if (boxes[i] == '1'){
                right ++;
                sum += i;
            }
        }
        
        for (int i = 0; i < n; i++){
            ans[i] = sum;
            if (boxes[i] == '1'){
                left++;
                right--;
            }
            sum += left - right;
        }
        return ans;
    }
};
