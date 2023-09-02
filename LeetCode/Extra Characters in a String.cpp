// https://leetcode.com/problems/extra-characters-in-a-string/description/

class Solution {
public:
    int n;
    int memo[51];
    string st;
    unordered_set<string> check;
    int dp(int indx){
        if(indx == n) return 0;
        int &ret = memo[indx];
        if(~ret) return ret;
        int ans = dp(indx + 1) + 1;
        for(int i = indx; i < n; i++){
            if(check.count(st.substr(indx, i - indx + 1))){
                ans = min(ans, dp(i + 1));
            }
        }
        return ret = ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        n = s.size();
        st = s;
        memset(memo, -1, sizeof memo);
        for(int i = 0; i < dictionary.size(); i++) check.insert(dictionary[i]);
        return dp(0);
    }
};
