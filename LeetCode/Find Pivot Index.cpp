// https://leetcode.com/problems/find-pivot-index/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> v(nums.size() + 1 , 0);
    for(int i = 1; i < nums.size() + 1; i++)
        v[i] = v[i - 1] + nums[i - 1];
 
    for(int i = 0; i < nums.size(); i++){
        if(v[nums.size()] - v[i + 1] == v[i]) {
            return i;
        }
    }
        return -1;
    }
};
