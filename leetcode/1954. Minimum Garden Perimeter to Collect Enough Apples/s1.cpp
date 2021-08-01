// OJ: https://leetcode.com/problems/minimum-garden-perimeter-to-collect-enough-apples/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/minimum-garden-perimeter-to-collect-enough-apples/discuss/1375504/C%2B%2B-or-With-Visualization-or-Arithmetic-Progression
// Time: O(root(T, 3))
// Space: O(1)
typedef long long ll;
class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        ll total = 0 , i = 1;
        while (neededApples > total){
            ll temp = 12 * i * i;
            total += temp;
            if (total >= neededApples)
                break;
            i++;
        }
        return i * 8;
    }
};
