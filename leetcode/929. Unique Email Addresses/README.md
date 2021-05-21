# [929. Unique Email Addresses (Easy)](hhttps://leetcode.com/problems/unique-email-addresses/)

<p>Every <b>valid email</b> consists of a <b>local name</b> and a <b>domain name</b>, separated by the <code>'@'</code> sign.
  Besides lowercase letters, the email may contain one or more <code>'.'</code> or <code>'+'</code>.</p>
  
<ul>
  <li>For example, in <code>"alice@leetcode.com"</code>, <code>"alice"</code> is the <b>local name</b>, and <code>"leetcode.com"</code> is the <b>domain name</b>.</li>
</ul>

<p>If you add periods <code>'.'</code> between some characters in the local name part of an email address, 
  mail sent there will be forwarded to the same address without dots in the <b>local name</b>.
  Note that this rule <b>does not apply</b> to <b>domain name</b>.</p>
  
<ul>
  <li>For example, <code>"alice.z@leetcode.com"</code> and <code>"alicez@leetcode.com"</code> forward to the same email address.</li>
</ul>

<p>If you add a plus <code>'+'</code> in the <b>local name</b>, everything after the first plus sign <b>will be ignored</b>.
  This allows certain emails to be filtered. Note that this rule <b>does not apply</b> to <b>domain names</b>.</p>.
  
<ul>
  <li>For example, <code>"m.y+name@email.com"</code> will be forwarded to <code>"my@email.com"</code>.</li>
</ul>

<p>It is possible to use both of these rules at the same time.</p>
<p>Given an array of strings <code>emails</code> where we send one email to each <code>email[i]</code>, 
  <em>return the number of different addresses that actually receive mails.</em></p>


<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> emails = ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
<strong>Output:</strong> 2
<strong>Explanation: </strong> "testemail@leetcode.com" and "testemail@lee.tcode.com" actually receive mails.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> emails = ["a@leetcode.com","b@leetcode.com","c@leetcode.com"]
<strong>Output:</strong> 3
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= emails.length &lt;= 100</code></li>
  <li><code>1 &lt;= emails[i].length &lt;= 100</code></li>
  <li><code>email[i]</code> consist of lowercase English letters, <code>'+'</code>, <code>'.'</code> and <code>'@'</code>.</li>
  <li>Each <code>emails[i]</code> contains exactly one <code>'@'</code> character.</li>
  <li>All local and domain names are non-empty.</li>
  <li>Local names do not start with a <code>'+'</code> character.</li>
</ul>



**Related Topics**:  
[String](https://leetcode.com/tag/string/)


## Solution 1.

```cpp
// OJ: hhttps://leetcode.com/problems/unique-email-addresses/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set <string> mp;
        
        for (auto email: emails){
            string cur {};
            for (auto c: email){
                if (c == '+' || c == '@')
                    break;
                else if (c == '.')
                    continue;
                else
                    cur.push_back(c);
            }
            cur += email.substr(email.find('@'));
            mp.insert(cur);
        }
        return mp.size();
    }
};
```
