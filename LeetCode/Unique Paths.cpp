// https://leetcode.com/problems/unique-paths/description/

class Solution {
public:
int nCr(int n, int r){
   if(n - r < r) r = n - r;
   long long p = 1, k = 1;
   if(!r) return 1;
   while(r){
       p *= n;
       k *= r;
       int div = __gcd(p, k);
       p /= div;
       k /= div;
       n--;
       r--;
   }
    return p;
}
int uniquePaths(int m, int n) {
    return nCr(m + n - 2, min(n - 1, m - 1));
}
};

// Another Solution using Memoization
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

// Another Solution
class Solution {
public:
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int> (n, 1));
    
    for(int i = 1; i < m; i++)
        for(int j = 1; j < n; j++) 
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    
    return dp[m - 1][n - 1];
}
};

// Another Solution with memory optimization
class Solution {
public:

int uniquePaths(int m, int n) {
    vector<int> prevRow(n, 1);
    
    for(int i = 1; i < m; i++){
        vector<int> currRow(n, 1);
        for(int j = 1; j < n; j++){
            currRow[j] = currRow[j - 1] + prevRow[j];
        }
        prevRow = currRow;
    }
    
    return prevRow[n - 1];
}
};
