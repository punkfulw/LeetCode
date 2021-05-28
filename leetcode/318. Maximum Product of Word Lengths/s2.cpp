// OJ: https://leetcode.com/problems/maximum-product-of-word-lengths/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/maximum-product-of-word-lengths/discuss/1233648/Short-and-Easy-Solution-w-Explanation-or-C%2B%2B-using-Bitset-and-Bit-masking-or-Beats-100
// Time: O(n*(N+n)), where n is the length of words and N is the average length of words
// Space: O(n)
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> arr(n);
        int ans = 0;
        
        for (int i = 0; i < n; i++){
            for (auto& c: words[i])
                arr[i] |= 1<<(c-'a');
            for (int j = 0; j < i; j++){
                if (!(arr[i] & arr[j])){
                    ans = max(ans, int(words[i].size() * words[j].size()));                    
                }
            }
        }
        return ans;
    }
};
