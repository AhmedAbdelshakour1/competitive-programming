// https://leetcode.com/problems/maximum-subarray/description/

class Solution {
public:
int maxSubArray(vector<int>& nums) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ans = nums[0], curr = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        curr = max(curr + nums[i], nums[i]);
        ans = max(ans, curr);
    }
    return ans;
 }
};
