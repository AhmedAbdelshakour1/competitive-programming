// https://leetcode.com/problems/shuffle-the-array/description/

vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> ans(2 * n);
    for(int i = 0, indx = 0; i < n; i++){
        ans[indx] = nums[i];
        ans[indx + 1] = nums[i + n];
        indx += 2;
    }
    return ans;
}
