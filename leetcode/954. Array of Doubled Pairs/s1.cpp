// OJ: https://leetcode.com/problems/array-of-doubled-pairs/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<double, int> mp;
        sort(arr.begin(), arr.end());
        for (int i: arr){
            if (mp[i])
                mp[i]--;
            else
                i > 0 ? mp[double(i)*2]++ : mp[double(i)/2]++;
        }
        for (auto p: mp){
            if (p.second != 0)
                return false;
        }
        return true;
    }
};
