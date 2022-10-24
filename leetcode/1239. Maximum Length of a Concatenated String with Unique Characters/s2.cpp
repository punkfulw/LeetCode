// OJ: https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/discuss/414806/C%2B%2B-DFS-clean-and-concise-code.
// Time: O(2^N)
// Space: O(N)
class Solution {
public:
    int sol(vector<string> &arr, string s, int idx){
        unordered_set<char> set(s.begin(), s.end());
        if (set.size() != s.size())
            return 0;
        
        int ans = s.size();
        for (int i = idx; i < arr.size(); ++i){
            ans = max(ans, sol(arr, s + arr[i], i + 1));
        }
        return ans;
    }
    
    int maxLength(vector<string>& arr) {
        return sol(arr, "", 0);
    }
};
