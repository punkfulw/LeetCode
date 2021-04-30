// OJ: https://leetcode.com/problems/n-repeated-element-in-size-2n-array
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        vector<int> test {};
        
        for (int num: A){
            auto it = find(test.begin(), test.end(), num);
            if (it == test.end())
                test.push_back(num);
            else
                return num;
        }
        return 0; 
    }
};
