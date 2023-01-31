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
