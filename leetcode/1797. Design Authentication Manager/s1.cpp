// OJ: https://leetcode.com/problems/design-authentication-manager/
// Author: github.com/punkfulw
// Time:
//     AuthenticationManager: O(1)
//     generate: O(1)
//     renew: O(N)
//     countUnexpiredTokens: O(N)
// Space: O(N)
class AuthenticationManager {
public:
    int timeToLive;
    unordered_map<string, int> mp;
    
    AuthenticationManager(int timeToLive) {      
        this->timeToLive = timeToLive;
    }
    
    void expire(int time){
        vector<string> exp;
        for (auto &[s, t]: mp)
            if (t <= time)
                exp.push_back(s);
            
        for (auto &e: exp)
            mp.erase(e);
    }
    void generate(string tokenId, int currentTime) {
        mp[tokenId] = currentTime + timeToLive;
    }
    
    void renew(string tokenId, int currentTime) {
        expire(currentTime);
        if (mp.find(tokenId) == mp.end())
            return;
        mp[tokenId] = currentTime + timeToLive;
    }
    
    int countUnexpiredTokens(int currentTime) {
        expire(currentTime);
        return mp.size();
    }
};
