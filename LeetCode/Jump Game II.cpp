// https://leetcode.com/problems/jump-game-ii/description/

int jump(vector<int>& nums) {
    int ans = 0, mx = 0, end = 0;
    for (int i = 0; i < nums.size() - 1; ++i) {
        mx = max(mx, i + nums[i]);
        if(i == end){
            ans++;
            end = mx;
        }
    }
    return ans;
}
