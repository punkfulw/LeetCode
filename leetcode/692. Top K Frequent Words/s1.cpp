// OJ: https://leetcode.com/problems/top-k-frequent-words/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/top-k-frequent-words/discuss/108366/O(nlog(k))-Priority-Queue-C%2B%2B-code
// Time: O(Nlog(k))
// Space: O(N)
class Solution {
public:
    bool operator()(pair<string, int> a, pair<string, int> b){
        if (a.second == b.second)
            return a.first > b.first;
        return a.second < b.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;

        for (auto word: words)
            mp[word]++;
        
        priority_queue<pair<string, int>, vector<pair<string, int>>, Solution> pq;
        
        for(auto &p : mp) 
            pq.push(p);
        
        vector<string> ans;
        while(pq.size() && k--){
            auto p = pq.top();
            pq.pop();
            ans.push_back(p.first);
        }
        return ans;
    }
};
