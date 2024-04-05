// https://leetcode.com/problems/trapping-rain-water/description/

// O(n) memory solution
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), mxL = 0, mxR = 0, ans = 0;
        vector<int> maxL(n), maxR(n);
        for(int i = 0; i < n; i++){
            maxL[i] = mxL;
            mxL = max(mxL, height[i]);
        }
        for(int i = n - 1; ~i; --i){
            maxR[i] = mxR;
            mxR = max(mxR, height[i]);
        }
        for(int i = 1; i < n; i++){
            ans += max(0, min(maxL[i], maxR[i]) - height[i]);
        }
        return ans;
    }
};

// O(1) memory solution
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), L = 0, R = n - 1, mxL = height[0], mxR = height[n - 1], ans = 0;
        while(L < R){
            mxL = max(mxL, height[L]);
            mxR = max(mxR, height[R]);
            if(mxL <= mxR){
                ans += max(0, mxL - height[L++]);
            }else {
                ans += max(0, mxR - height[R--]);
            }
        }
        return ans;
    }
};
