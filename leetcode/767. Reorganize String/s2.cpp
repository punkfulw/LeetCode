// OJ: https://leetcode.com/problems/reorganize-string/
// Author: github.com/punkfulw
// Time: O(NlogN) 
// Space: O(N)
class Solution {
public:
    string reorganizeString(string s) {
        map<char, int> mp;
        for (auto c: s)
            mp[c]++;
        priority_queue<pair<int, char>> pq;
        for (auto p: mp)
            pq.push({p.second, p.first});
        string ans = "";

        while (!pq.empty()){
            auto num1 = pq.top(); pq.pop();
            if (pq.empty()){
                if (num1.first > 1)
                    return "";
                else 
                    return ans + num1.second;
            }
            
            auto num2 = pq.top(); pq.pop();
            ans = ans + num1.second + num2.second;

            if (--num1.first)
                pq.push(num1);
            if (--num2.first)
                pq.push(num2);
        }
        return ans;
    }
};
