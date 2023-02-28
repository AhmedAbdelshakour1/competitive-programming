// https://leetcode.com/problems/longest-common-subsequence/description/

class Solution {
public:
int dp[1001][1001];
int longestCommonSubsequence(string text1, string text2) {
    for (int i = 1; i <= text1.size(); ++i) {
        for (int j = 1; j <= text2.size(); ++j) {
            if(text1[i - 1] == text2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int ans = dp[text1.size()][text2.size()];
    memset(dp, 0, sizeof dp);
    return ans;
}
};
