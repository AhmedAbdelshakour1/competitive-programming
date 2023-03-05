// https://leetcode.com/problems/count-subarrays-with-fixed-bounds/description/

class Solution {
public:
long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    int n = nums.size(), mnIndx = -1, mxIndx = -1, lastInvalid = -1;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        if(nums[i] > maxK || nums[i] < minK) lastInvalid = i;
        if(nums[i] == minK) mnIndx = i;
        if(nums[i] == maxK) mxIndx = i;
        ans += max(0, min(mnIndx, mxIndx) - lastInvalid);
    }
    return ans;
}
};
