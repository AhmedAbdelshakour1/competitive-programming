// https://leetcode.com/problems/valid-anagram/description/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int a[26] = {};
        for(int i = 0; i < s.size(); i++) {
            a[s[i] - 'a']++;
            a[t[i] - 'a']--;
        }
        for(int i = 0; i < 26; i++) {
            if(a[i] != 0) return false;
        }
        return true;
    }
};

// Another solution

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != t[i]) return false;
        }
        return true;
    }
};
