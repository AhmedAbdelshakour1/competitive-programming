// https://leetcode.com/problems/single-element-in-a-sorted-array/description/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int st = 0, end = nums.size() - 1;
        while (st < end) {
            int mid = (st + end) / 2;
            if (mid % 2 == 1) mid--;
            if (nums[mid] != nums[mid + 1]) end = mid;
             else st = mid + 2;
        }
        return nums[st];
    }
};
