// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), l = 0, r = 0, ans = n ? 1 : 0;
        unordered_set<char> freq;
        freq.insert(s[l]);
        while(r + 1 < n){
            r++;
            while(freq.count(s[r])) freq.erase(s[l++]);
            freq.insert(s[r]);
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
