// https://leetcode.com/problems/longest-consecutive-sequence/description/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> ust(nums.begin(), nums.end());
        int ans = 0, lng;
        for(int num : nums){
            if(ust.find(num - 1) == ust.end()) {
                lng = 1;
                while(ust.find(num + lng) != ust.end()){
                    lng++;
                }
                ans = max(ans, lng);
            }
        }
        return ans;
    }
};
