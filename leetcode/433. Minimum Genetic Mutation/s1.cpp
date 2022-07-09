// OJ: https://leetcode.com/problems/minimum-genetic-mutation/
// Author: github.com/punkfulw
// Time: O(B) 
// Space: O(B)
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int ans = 0;
        unordered_set<string> st;
        queue<string> q;
        st.insert(start);
        q.push(start);
        
        while (q.size()){
            int n = q.size();
            for (int i = 0; i < n; i++){
                string cur = q.front(), s = cur;
                q.pop();
                if (cur == end) return ans;
                for (auto b: bank){
                    int dif = 0;
                    for (int i = 0; i < 8; i++){
                        if (s[i] != b[i])
                            dif++;
                        s[i] = b[i];
                    }
                    if (dif == 1 && st.find(s) == st.end()){
                        q.push(s);
                        st.insert(s);
                    }
                    s = cur;
                }
            }
            ans++;
        }
        return -1;
    }
};
