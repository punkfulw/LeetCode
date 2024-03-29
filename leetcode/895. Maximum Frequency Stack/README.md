# [895. Maximum Frequency Stack (Hard)](https://leetcode.com/problems/maximum-frequency-stack/)

<p>Design a stack-like data structure to push elements to the stack and pop the most frequent element from the stack.</p>

<p>Implement the <code>FreqStack</code> class:</p>

<ul>
	<li><code>FreqStack()</code> constructs an empty frequency stack.</li>
	<li><code>void push(int val)</code> pushes an integer <code>val</code> onto the top of the stack.</li>
	<li><code>int pop()</code> removes and returns the most frequent element in the stack.
	<ul>
		<li>If there is a tie for the most frequent element, the element closest to the stack's top is removed and returned.</li>
	</ul>
	</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input</strong>
["FreqStack", "push", "push", "push", "push", "push", "push", "pop", "pop", "pop", "pop"]
[[], [5], [7], [5], [7], [4], [5], [], [], [], []]
<strong>Output</strong>
[null, null, null, null, null, null, null, 5, 7, 5, 4]

<strong>Explanation</strong>
FreqStack freqStack = new FreqStack();
freqStack.push(5); // The stack is [5]
freqStack.push(7); // The stack is [5,7]
freqStack.push(5); // The stack is [5,7,5]
freqStack.push(7); // The stack is [5,7,5,7]
freqStack.push(4); // The stack is [5,7,5,7,4]
freqStack.push(5); // The stack is [5,7,5,7,4,5]
freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,5,7,4].
freqStack.pop();   // return 7, as 5 and 7 is the most frequent, but 7 is closest to the top. The stack becomes [5,7,5,4].
freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,4].
freqStack.pop();   // return 4, as 4, 5 and 7 is the most frequent, but 4 is closest to the top. The stack becomes [5,7].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= val &lt;= 10<sup>9</sup></code></li>
	<li>At most <code>2 * 10<sup>4</sup></code> calls will be made to <code>push</code> and <code>pop</code>.</li>
	<li>It is guaranteed that there will be at least one element in the stack before calling <code>pop</code>.</li>
</ul>


**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Stack](https://leetcode.com/tag/stack/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/maximum-frequency-stack/
// Author: github.com/punkfulw
// Time: O(NlogN) for keeping the pq sorted
// Space: O(N)
class FreqStack {
public:
    int pos = 0;
    unordered_map<int, int> mp;
    priority_queue<vector<int>> pq;
    
    FreqStack() {
    }
    
    void push(int val) {
        mp[val]++;
        pq.push({mp[val],pos++,val});
    }
    
    
    int pop(){
        auto mx = pq.top(); 
        pq.pop(); 
        --mp[mx[2]]; 
        return mx[2];
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/maximum-frequency-stack/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/maximum-frequency-stack/discuss/163410/C%2B%2BJavaPython-O(1)
// Time: O(1)
// Space: O(N)
class FreqStack {
public:
    int maxfreq = 0;
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> m;
    
    FreqStack() {
    }
    
    void push(int val) {
        maxfreq = max(maxfreq, ++freq[val]);
        m[freq[val]].push(val);
    }
    
    
    int pop() {
        int ans = m[maxfreq].top();
        m[maxfreq].pop();
        freq[ans]--;
        if (!m[maxfreq].size())
            maxfreq--;
        return ans;
    }
};
```

## Solution 3. LRU Cache-like

```cpp
// OJ: https://leetcode.com/problems/maximum-frequency-stack/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(N)
class FreqStack {
public:
    unordered_map<int, int> val2freq;
    map<int, vector<list<int>::iterator>> freq2iter;
    
    list<int> List;
    
    FreqStack() {
    }
    
    void push(int val) {
        List.push_back(val);
        val2freq[val]++;
        int freq = val2freq[val];
        freq2iter[freq].push_back(--List.end());
    }
    
    int pop() {
        int freq = (--freq2iter.end())->first;
        auto it = freq2iter[freq].back();
        int val = *it;
        val2freq[val]--;
        freq2iter[freq].pop_back();
        if (freq2iter[freq].empty())
            freq2iter.erase(freq);
        List.erase(it);
        
        return val;
    }
};
```
