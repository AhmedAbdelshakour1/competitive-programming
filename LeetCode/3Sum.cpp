// https://leetcode.com/problems/3sum/

class Solution {
public:
vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < n; i++) {
        if (i && nums[i] == nums[i - 1]) continue;
        int l = i + 1, r = n - 1, currL = 1e9, currR = 1e9;
        while (l < r) {
            if(nums[i] + nums[l] + nums[r] < 0) l++;
            else if(nums[i] + nums[l] + nums[r] > 0) r--;
            else{
                if(currL != nums[l] && currR != nums[r]){
                    ans.push_back({nums[i], nums[l], nums[r]});
                    currL = nums[l], currR = nums[r];
                }
                l++, r--;
            }
        }
    }
    return ans;
}
};
