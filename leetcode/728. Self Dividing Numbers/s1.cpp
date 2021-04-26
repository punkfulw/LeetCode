// OJ: https://leetcode.com/problems/self-dividing-numbers/
// Author: github.com/punkfulw
// Time: O(N) 
// Space: O(N)
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans{};
        
        for (int i = left; i <= right; i++){
            int j = i;
            while (j > 0){
                int d_num = j % 10;
                if (d_num == 0 || (i % d_num) != 0){
                    break;
                }
                j /= 10;
            }
            if (j == 0)
                ans.push_back(i);
        }
        return ans;
    }
};
