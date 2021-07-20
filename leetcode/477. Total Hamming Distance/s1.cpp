// OJ: https://leetcode.com/problems/total-hamming-distance/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/total-hamming-distance/discuss/96243/Share-my-O(n)-C%2B%2B-bitwise-solution-with-thinking-process-and-explanation
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        if (n < 2)
            return 0;
        int* zeroOne = new int[2];
        while (true){
            int cnt = 0;
            zeroOne[0] = 0;
            zeroOne[1] = 0;
            for (int i = 0; i < n; i++){
                if (nums[i] == 0)
                    cnt++;
                zeroOne[nums[i] % 2]++;
                nums[i] = nums[i] >> 1;
            }
            ans += zeroOne[0] * zeroOne[1];
            if (cnt == n)
                return ans;
        }
    }
};
