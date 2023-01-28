// https://leetcode.com/problems/product-of-array-except-self/description/


vector<int> productExceptSelf(vector<int>& nums){
    int n = nums.size();
    vector<int> ans(n, 1);
    int pre = 1, suf = 1;
    for (int i = 0; i < n; ++i) {
        ans[i] *= pre;
        pre *= nums[i];
    }
    for(int i = n - 1; ~i; --i){
        ans[i] *= suf;
        suf *= nums[i];
    }
    return ans;
}

// Another solution 

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> left(n), right(n), ans(n);
    left[0] = nums[0];
    right[n - 1] = nums[n - 1];
    for (int i = 1; i < n; ++i) left[i] = left[i - 1] * nums[i];
    for(int i = n - 2; ~i; --i) right[i] = right[i + 1] * nums[i];
    ans[0] = right[1];
    ans[n - 1] = left[n - 2];
    for (int i = 1; i < n - 1; ++i) {
        ans[i] = left[i - 1] * right[i + 1];
    }
    return ans;
}
