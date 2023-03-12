// https://leetcode.com/problems/minimize-deviation-in-array/description/

class Solution {
public:
int minimumDeviation(vector<int>& nums) {
    int mn = 1e9, ans  = 1e9;
    priority_queue<int> pq;
    for (int i = 0; i < nums.size(); ++i) {
        if(nums[i] & 1) nums[i] *= 2;
        mn = min(mn, nums[i]);
        pq.push(nums[i]);
    }
    while(1){
        int curr = pq.top();
        ans = min(ans, curr - mn);
        pq.push(curr / 2);
        pq.pop();
        if(curr & 1) break;
        mn = min(mn, curr / 2);
    }
    return ans;
}
};
