// https://leetcode.com/problems/search-insert-position/description/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int st = 0, end = nums.size() - 1;        
        while(st <= end){
            int mid = st + (end - st) / 2;
            if(nums[mid] == target) return mid;
            if(nums[mid]  < target) st = mid + 1;
            else end = mid - 1;
        }
        return st;
    }
};
