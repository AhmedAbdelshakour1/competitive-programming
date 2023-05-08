// https://leetcode.com/problems/house-robber/description/

class Solution {
public:
int n;
int dp[101];
vector<int> v;
int solve(int indx){
    if(indx >= n) return 0;
    int &ret = dp[indx];
    if(~ret) return ret;
    return ret = max(solve(indx + 1), v[indx] + solve(indx + 2));
}
int rob(vector<int>& nums) {
    n = nums.size();
    v = nums;
    memset(dp, -1, sizeof dp);
    return solve(0);
}
};
