// https://leetcode.com/problems/longest-repeating-character-replacement/description/


class Solution {
public:
    int characterReplacement(string s, int k) {
    int L = 0, R = 0, ans = 1, sz = s.size();
    int cnt[26] = {};
    cnt[s[0] - 'A']++;
    while(R < sz){
        int mx = *max_element(cnt, cnt + 26);
        if(R - L + 1 - mx <= k){
            ans = max(ans, R - L + 1);
            R++;
            if(R < sz) cnt[s[R] - 'A']++;
        }else {
            cnt[s[L] - 'A']--;
            L++;
        }
    }
    return ans;
}
};
