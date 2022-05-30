// OJ: https://leetcode.com/problems/count-square-sum-triples/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for (int a = 1; a <= n; a++){
            for (int b = 1; b <= n; b++){
                int sum = pow(a, 2) + pow(b, 2), c = sqrt(sum);
                if (c > n) break;
                if (c * c == sum)
                    ans++;
            }
        }
        return ans;
    }
};
