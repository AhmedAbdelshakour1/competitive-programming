// https://leetcode.com/problems/edit-distance/description/

// Memoization
class Solution {
public:
int memo[555][555];
int calc(int indx, int indx2, string &s1, string &s2){
    if(indx == s1.size()) return (int)s2.size() - indx2;
    if(indx2 == s2.size()) return (int)s1.size() - indx;
    int &ret = memo[indx][indx2];
    if(~ret) return ret;
    if(s1[indx] == s2[indx2]) return ret = calc(indx + 1, indx2 + 1, s1, s2);
    int ins = 1 + calc(indx, indx2 + 1, s1, s2);
    int del = 1 + calc(indx + 1, indx2, s1, s2);
    int rep = 1 + calc(indx + 1, indx2 + 1, s1, s2);
    return ret = min({ins, del, rep});
}
int minDistance(string word1, string word2) {
    memset(memo, -1, sizeof memo);
    return calc(0, 0, word1, word2);
}
};

// Tabulation
class Solution {
public:
int minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    // transforming word1[0...i-1] into an empty string requires i deletions.
    for (int i = 1; i <= n; ++i)
        dp[i][0] = i;

    // transforming an empty string into word2[0...j-1] requires j insertions.
    for (int j = 1; j <= m; ++j)
        dp[0][j] = j;

    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
        if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
        else{
            int ins = dp[i][j - 1] + 1;
            int del = dp[i - 1][j] + 1;
            int rep = dp[i - 1][j - 1] + 1;
            dp[i][j] = min({ins, del, rep});
        }
    return dp[n][m];
}
};
