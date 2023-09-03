// https://leetcode.com/problems/unique-paths/description/

class Solution {
public:
int memo[101][101];
int solve(int r, int c, int n, int m){
    if(r == n - 1 && c == m - 1) return 1;
    if(r == n || c == m) return 0;
    int &ret = memo[r][c];
    if(~ret) return ret;
    return ret = solve(r + 1, c, n, m) + solve(r, c + 1, n, m);
}
int uniquePaths(int m, int n) {
    memset(memo, -1, sizeof memo);
    return solve(0, 0, m, n);
}
};
