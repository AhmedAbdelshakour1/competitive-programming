// https://leetcode.com/problems/contains-duplicate/description/

class Solution {
public:
bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> st;
    for (int i = 0; i < nums.size(); ++i) {
        if(!st.insert(nums[i]).second) return true;;
    }
    return false;
 }
};
