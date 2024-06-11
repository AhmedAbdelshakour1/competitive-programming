// https://leetcode.com/problems/majority-element/description/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> ump;
        for(int &x :nums) ump[x]++;
        for(auto &x : ump){
            if(x.second > n / 2) return x.first;
        }
        return 0;
    }
};
