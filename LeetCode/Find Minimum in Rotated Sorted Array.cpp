// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

int findMin(vector<int>& nums) {
    int n = nums.size();
    int st = 0, end = n - 1, right = nums[end];
    while(st < end){
        int mid = st + (end - st) / 2;
        if(nums[mid] > right) st = mid + 1;
        else end = mid;
    }
    return nums[st];
}
