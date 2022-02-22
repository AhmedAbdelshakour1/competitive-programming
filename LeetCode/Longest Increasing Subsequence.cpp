// https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n);
    dp.assign(n, 1);
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if(nums[i] > nums[j]){
                dp[i] = max(dp[j] + 1, dp[i]);
                ans = max(ans, dp[i]);
            }
        }
    }
    return ans;
}
};
// Another solution in O(nlogn)
class Solution {
public:
vector<int> dp;
int lengthOfLIS(vector<int>& nums) {
    int n = (int)nums.size();
    dp.resize(n + 10, 1000000000);
    for (int i = 0; i < n; i++)
        *lower_bound(dp.begin(), dp.end(), nums[i]) = nums[i];

    for (int i = 0; i <= n; i++) {
        if (dp[i] == 1000000000)
            return i;
    }
    return 0;
}
};
