// OJ: https://leetcode.com/problems/count-vowels-permutation/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/count-vowels-permutation/discuss/398173/C%2B%2B-Bottom-up-Recursive-DPs-O(n)-and-Matrix-Exponentiation-O(logn)
// Time: O(N)
// Space: O(1)
#define ll long long
class Solution {
public:
    int countVowelPermutation(int n) {
        int mod = 1e9 + 7;
        vector<vector<int>> relations{{1, 2, 4}, {0, 2}, {1, 3}, {2}, {2, 3}};
        vector<ll> vowel(5, 1), copy;
        
        while (--n){
            copy = vowel;
            for (int i = 0; i < 5; i++){
                vowel[i] = 0;
                for (int num: relations[i])
                    vowel[i] += copy[num], vowel[i] %= mod;
            }
        }
        ll ans = 0;
        for (int i: vowel){
            ans += i, ans %= mod;
        }
        return ans;
    }
};
