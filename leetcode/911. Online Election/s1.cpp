// OJ: https://leetcode.com/problems/online-election/
// Author: github.com/punkfulw
// Time:
//     TopVotedCandidate: O(NlogN)
//     q: O(logN)
// Space: O(N)
class TopVotedCandidate {
public:
    unordered_map<int, int> cnt; //per -> vote
    map<int, int> mp;  // time->winner;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n = persons.size(), mx = 0;
        for (int i = 0; i < n; i++){
            int t = times[i], p = persons[i];
            cnt[p]++;
            if (cnt[p] >= mx){
                mx = cnt[p];
                mp[t] = p;
            }
        }
    }

    int q(int t) {
        auto it = mp.upper_bound(t);
        it = prev(it);
        return it->second;
    }
};
