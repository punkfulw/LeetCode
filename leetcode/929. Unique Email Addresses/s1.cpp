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
