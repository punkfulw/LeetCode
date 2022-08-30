# [853. Car Fleet (Medium)](https://leetcode.com/problems/car-fleet/)

<p><code>N</code> cars are going to the same destination along a one lane road.&nbsp; The destination is <code>target</code>&nbsp;miles away.</p>

<p>Each car <code>i</code>&nbsp;has a constant speed <code>speed[i]</code>&nbsp;(in miles per hour), and initial position <code>position[i]</code>&nbsp;miles towards the target along the road.</p>

<p>A car can never pass another car ahead of it, but it can catch up to it, and drive bumper to bumper at the same speed.</p>

<p>The distance between these two cars is ignored - they are assumed to have the same position.</p>

<p>A <em>car fleet</em> is some non-empty set of cars driving&nbsp;at the same position and same speed.&nbsp; Note that a single car is also a car fleet.</p>

<p>If a car catches up to a car fleet right at the destination point, it will&nbsp;still be&nbsp;considered as one car fleet.</p>

<p><br>
How many car fleets will arrive at the destination?</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>target = <span id="example-input-1-1">12</span>, position = <span id="example-input-1-2">[10,8,0,5,3]</span>, speed = <span id="example-input-1-3">[2,4,1,1,3]</span>
<strong>Output: </strong><span id="example-output-1">3</span>
<strong>Explanation</strong>:
The cars starting at 10 and 8 become a fleet, meeting each other at 12.
The car starting at 0 doesn't catch up to any other car, so it is a fleet by itself.
The cars starting at 5 and 3 become a fleet, meeting each other at 6.
Note that no other cars meet these fleets before the destination, so the answer is 3.
</pre>

<p><br>
<strong>Note:</strong></p>

<ol>
	<li><code>0 &lt;= N &lt;= 10 ^ 4</code></li>
	<li><code>0 &lt; target&nbsp;&lt;= 10 ^ 6</code></li>
	<li><code>0 &lt;&nbsp;speed[i] &lt;= 10 ^ 6</code></li>
	<li><code>0 &lt;= position[i] &lt; target</code></li>
	<li>All initial positions are different.</li>
</ol>

**Companies**:  
[Google](https://leetcode.com/company/google), [Nutanix](https://leetcode.com/company/nutanix), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Sort](https://leetcode.com/tag/sort/)

**Similar Questions**:
* [Car Fleet II (Hard)](https://leetcode.com/problems/car-fleet-ii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/car-fleet/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int carFleet(double target, vector<int>& position, vector<int>& speed) {
        int n = position.size(), ans = 1;
        vector<pair<int, int>> rec;
        for (int i = 0; i < n; i++) rec.push_back({position[i], speed[i]});
        sort(rec.rbegin(), rec.rend());
        int prepos = rec[0].first, presp = rec[0].second;

        for (int i = 1; i < n; i++){
            int pos = rec[i].first, sp = rec[i].second;
            if (sp <= presp || (target - prepos) / presp < (target - pos) / sp){
                ans++;
                prepos = pos;
                presp = sp;
            }
        }
        return ans;
    }
};
```