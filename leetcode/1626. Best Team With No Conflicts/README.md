# [1626. Best Team With No Conflicts (Medium)](https://leetcode.com/problems/best-team-with-no-conflicts/)

<p>You are the manager of a basketball team. For the upcoming tournament, you want to choose the team with the highest overall score. The score of the team is the <strong>sum</strong> of scores of all the players in the team.</p>

<p>However, the basketball team is not allowed to have <strong>conflicts</strong>. A <strong>conflict</strong> exists if a younger player has a <strong>strictly higher</strong> score than an older player. A conflict does <strong>not</strong> occur between players of the same age.</p>

<p>Given two lists, <code>scores</code> and <code>ages</code>, where each <code>scores[i]</code> and <code>ages[i]</code> represents the score and age of the <code>i<sup>th</sup></code> player, respectively, return <em>the highest overall score of all possible basketball teams</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> scores = [1,3,5,10,15], ages = [1,2,3,4,5]
<strong>Output:</strong> 34
<strong>Explanation:</strong>&nbsp;You can choose all the players.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> scores = [4,5,6,5], ages = [2,1,2,1]
<strong>Output:</strong> 16
<strong>Explanation:</strong>&nbsp;It is best to choose the last 3 players. Notice that you are allowed to choose multiple people of the same age.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> scores = [1,2,3,5], ages = [8,9,10,1]
<strong>Output:</strong> 6
<strong>Explanation:</strong>&nbsp;It is best to choose the first 3 players. 
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= scores.length, ages.length &lt;= 1000</code></li>
	<li><code>scores.length == ages.length</code></li>
	<li><code>1 &lt;= scores[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= ages[i] &lt;= 1000</code></li>
</ul>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP


```cpp
// OJ: https://leetcode.com/problems/best-team-with-no-conflicts/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    typedef struct player{
        int score, age; 
        player(int score, int age){
            this->score = score;
            this->age = age;
        }
    } Player;
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<Player> rec;
        int n = scores.size(), ans = 0;
        for (int i = 0; i < n; i++){
            rec.push_back(Player(scores[i], ages[i]));
        }
        
        sort(rec.begin(), rec.end(), [](Player &a, Player &b){
            if (a.age == b.age)
                return a.score < b.score;
            return a.age < b.age;
        });
        
        vector<int> dp(n);

        for (int i = 0; i < n; i++){
            int cur_score = rec[i].score, cur_age = rec[i].age;
            dp[i] = cur_score;
            for (int j = 0; j < i; j++){
                Player p = rec[j];
                if (p.score > cur_score)
                    continue;
                dp[i] = max(dp[i], cur_score + dp[j]);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
```
