// OJ: https://leetcode.com/problems/verifying-an-alien-dictionary/
// Author: github.com/punkfulw
// Time: O(N) 
// Space: O(N)
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        bool res = false;
        for (int i = 0; i < words.size()-1; i++){
             vector<int> f_num{};
             vector<int> s_num{};
             f_num.assign(20, 0);
             s_num.assign(20, 0);
             for (int j = 0; j < words[i].size(); j++){
                 for (int u = 0; u < 26; u++){
                     if (words[i].at(j) == order.at(u)){
                         f_num[j] = u+1;
                     }
                 }
             }
             for (int j = 0; j < words[i+1].size(); j++){
                 for (int u = 0; u < 26; u++){
                     if (words[i+1].at(j) == order.at(u)){
                         s_num[j] = u+1;
                     }
                 }
             }
             for (int i = 0; i < 20; i++){
                 cout << f_num[i] << " ";
                 cout << s_num[i] << " " << endl;
                 if (f_num[i] < s_num[i]){
                     res = true;
                     break;
                 }else if (f_num[i] > s_num[i]){
                     res = false;
                     return res;
                 }else {
                     res = true;
                     continue;
                 }
             }
             if (res == true)
                 f_num.clear();
                  s_num.clear();
                 continue;
        }
        return res;
    }
};
