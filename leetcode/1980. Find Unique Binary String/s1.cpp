// OJ: https://leetcode.com/problems/find-unique-binary-string/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(2^N)
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        vector<int> cnt(pow(2, n));
        vector<int> used;
        iota(cnt.begin(), cnt.end(), 0);
        
        for (int i = 0; i < n; i++){
            int cur = 0;
            for (int k = 0; k < n; k++){
                cur += (nums[i][k]-'0') * pow(2, k);
            }
            used.push_back(cur);
        }
        
        string s;
        for (int i = n - 1 ; i >= 0; i++){
            int x = cnt[i];
            if (!count(used.begin(), used.end(), x)){
                while (x > 0){
                    s += (x % 2) + '0';
                    x /= 2;
                }
                break;
            }
        }
        while (s.size() != n){
            s += '0';
        }
        return s;
    }
};
