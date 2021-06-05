// OJ: https://leetcode.com/problems/open-the-lock/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/open-the-lock/discuss/110230/BFS-solution-C%2B%2B
// Time: O(N^2 * A^N + D), where N is number of dials (4 in our case), A is number of alphabet (10 in our case), D is size of deadends
// Space: O(A^N)
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int ans {};
        unordered_set<string> dd(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        queue<string> bfs; 
        string start {"0000"};
        
        if (dd.find(start) != dd.end()) 
            return -1;
        if (target == start)
            return 0;
        bfs.push(start);
        visited.insert(start);
        
        while (!bfs.empty()){
            int sz = bfs.size();
            for (int i = 0; i < sz; i++){
                string key = bfs.front(); bfs.pop();
                vector<string> nbrs = nbrStrs(key);
                for (auto s: nbrs){
                    if (s == target)
                        return ++ans;
                    if (visited.find(s) != visited.end()) continue;
                    if (dd.find(s) == dd.end()){
                        bfs.push(s);
                        visited.insert(s);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
    
    vector<string> nbrStrs(string key){
        vector<string> res;
        for (int i = 0; i < 4; i++){
            string temp = key;
            temp[i] = (key[i]-'0' + 1) % 10 + '0';
            res.push_back(temp);
            temp[i] = (key[i]-'0' - 1 + 10) % 10 + '0';
            res.push_back(temp);
        }
        return res;
    }
};
