# [412. Fizz Buzz (Easy)](https://leetcode.com/problems/fizz-buzz/)

<p>Given an integer <code>n</code>, return <em>a string array</em> <code>answer</code> <b>(1-indexed)</b>. <em>where:</em></p>

<ul>
  <li><code>answer[i] == "FizzBuzz"</code> if <code>i</code> is divisible by <code>3</code> and <code>5</code>.</li>
  <li><code>answer[i] == "Fizz"</code> if <code>i</code> is divisible by <code>3</code>.</li>
  <li><code>answer[i] == "Buzz"</code> if <code>i</code> is divisible by <code>5</code>.</li>
  <li><code>answer[i] == i</code> if non of the above conditions are true.</li>
</ul>


<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> n = 3
<strong>Output:</strong> ["1","2","Fizz"]
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> n = 5
<strong>Output:</strong> ["1","2","Fizz","4","Buzz"]
</pre>

<p><strong>Example 3:</strong></p>
<pre>
<strong>Input:</strong> n = 15
<strong>Output:</strong> 
["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
</ul>


**Companies**:  
[Apple](https://leetcode.com/company/apple), [Google](https://leetcode.com/company/google), [Microsoft](https://leetcode.com/company/microsoft)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/fizz-buzz/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for (int i = 1; i <= n; i++){
            if (i % 15 == 0)
                ans.push_back("FizzBuzz");
            else if (i % 3 == 0)
                ans.push_back("Fizz");
            else if (i % 5 == 0)
                ans.push_back("Buzz");
            else
                ans.push_back(to_string(i));                    
        }
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/fizz-buzz/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans (n);
        for (int i = 1; i <= n; i++)
            ans[i-1] = to_string(i);
        for (int i = 2; i < n; i += 3)
            ans[i] = "Fizz";
        for (int i = 4; i < n; i += 5)
            ans[i] = "Buzz";
        for (int i = 14; i < n; i += 15)
            ans[i] = "FizzBuzz";
        return ans;
    }
};
```
