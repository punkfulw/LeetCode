# [875. Koko Eating Bananas (Medium)](https://leetcode.com/problems/koko-eating-bananas/)

<p>Koko loves to eat bananas. There are <code>n</code> piles of bananas, the <code>i<sup>th</sup></code> pile has <code>piles[i]</code> bananas. The guards have gone and will come back in <code>h</code> hours.</p>

<p>Koko can decide her bananas-per-hour eating speed of <code>k</code>. Each hour, she chooses some pile of bananas and eats <code>k</code> bananas from that pile. If the pile has less than <code>k</code> bananas, she eats all of them instead and will not eat any more bananas during this hour.</p>

<p>Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.</p>

<p>Return <em>the minimum integer</em> <code>k</code> <em>such that she can eat all the bananas within</em> <code>h</code> <em>hours</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> piles = [3,6,7,11], h = 8
<strong>Output:</strong> 4
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> piles = [30,11,23,4,20], h = 5
<strong>Output:</strong> 30
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> piles = [30,11,23,4,20], h = 6
<strong>Output:</strong> 23
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= piles.length &lt;= 10<sup>4</sup></code></li>
	<li><code>piles.length &lt;= h &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= piles[i] &lt;= 10<sup>9</sup></code></li>
</ul>


**Companies**:  
[Airbnb](https://leetcode.com/company/airbnb), [Facebook](https://leetcode.com/company/facebook), [DoorDash](https://leetcode.com/company/doordash)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/)

**Similar Questions**:
* [Minimize Max Distance to Gas Station (Hard)](https://leetcode.com/problems/minimize-max-distance-to-gas-station/)
* [Minimized Maximum of Products Distributed to Any Store (Medium)](https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/)

## Solution 1. Binary Search

```cpp
// OJ: https://leetcode.com/problems/koko-eating-bananas/
// Author: github.com/punkfulw
// Time: O(N*logM) where N is the size of piles, M is ths sum of every pile.
// Space: O(1)
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long l = 1, r = 1e14 + 1, ans;

        while (l <= r){
            long long mid = (l + r) / 2, cnt = 0;
            
            for (auto i: piles){
                cnt += i / mid + (i % mid != 0);
            }
            if (cnt <= h){
                ans = mid;
                r = mid - 1;
            }
            else 
                l = mid + 1;
        }

        return ans;
    }
};
```
