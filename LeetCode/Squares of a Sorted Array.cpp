// https://leetcode.com/problems/squares-of-a-sorted-array/description/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size(), l = 0, r = n - 1, pos = n - 1;;
        vector<int> ans(n);
        while(l <= r){
            if(nums[r] * nums[r] >= nums[l] * nums[l]) ans[pos] = nums[r] * nums[r], r--;
            else ans[pos] = nums[l] * nums[l], l++;
            pos--;
        }
        return ans;
    }
};
