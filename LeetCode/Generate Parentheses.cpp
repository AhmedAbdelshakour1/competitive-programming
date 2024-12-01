// https://leetcode.com/problems/generate-parentheses/description/


/**
  There are C_n (nth Catalan number) valid strings, and constructing each string takes O(2n) time.
  Thus, the total time complexity is O(C_n * n) -> O((4^n) / sqrt(n))
**/
class Solution {
public:
    void backtrack(vector<string> &ans, int open, int close, string s, int n) {
        if(open == n && close == n) {
            ans.push_back(s);
            return;
        }
        if(open < n) backtrack(ans, open + 1, close, s + '(', n);
        if(close < open) backtrack(ans, open, close + 1, s + ')', n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack(ans, 0, 0, "", n);
        return ans;
    }
};
