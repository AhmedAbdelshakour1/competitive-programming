// https://leetcode.com/problems/longest-palindromic-substring/description/

class Solution {
public:
    string expanding(int a, int b, string &s){
        while(a >= 0 && b < s.size() && s[a] == s[b]) a--, b++;
        return s.substr(a + 1, b - a - 1);
    }
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        ans.push_back(s[0]);
        for(int i = 0; i + 1 < n; i++){
            string x = expanding(i, i, s);
            if(x.size() > ans.size()) ans = x;
            if(s[i] == s[i + 1]){
                string y = expanding(i, i + 1, s);
                if(y.size() > ans.size()) ans = y;
            }
        }
        return ans;
    }
};
