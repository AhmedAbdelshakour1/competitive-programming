// https://leetcode.com/problems/sort-an-array/

class Solution {
public:
vector<int> sortArray(vector<int>& nums) {
   priority_queue<int, vector<int>, greater<int>> q;
   for(int &x : nums) q.push(x);
    for (int i = 0; i < nums.size(); ++i) {
        nums[i] = q.top();
        q.pop();
    }
    return nums;
}
};
