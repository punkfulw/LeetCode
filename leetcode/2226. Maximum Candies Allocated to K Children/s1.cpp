// OJ: https://leetcode.com/problems/maximum-candies-allocated-to-k-children/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/maximum-candies-allocated-to-k-children/discuss/1908888/JavaC%2B%2BPython-Binary-Search-with-Explanation
// Time: O(Nlog(sum(A)))
// Space: O(1)
class Solution {
public:
    int maximumCandies(vector<int>& can, long long k) {
        
        int l = 0, r = 1e7;
        while (l < r)
        {
            long long mid = (l + r + 1) / 2, sum = 0;
            for (auto c: can)
                sum += c / mid;
            
            if (sum >= k)
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
};
