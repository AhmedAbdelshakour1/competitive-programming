// https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/description/

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        ans[n - 1] = -1;
        int mx = arr[n - 1];
        for(int i = (int)arr.size() - 2; ~i; --i){
            ans[i] = mx;
            mx = max(mx, arr[i]);
        }
        return ans;
    }
};
