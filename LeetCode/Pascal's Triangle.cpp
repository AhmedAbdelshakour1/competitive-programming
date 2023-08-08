// https://leetcode.com/problems/pascals-triangle/description/

class Solution {
public:
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    ans.push_back(vector<int> {1});
    for(int sz = 2; sz <= numRows; sz++){
        vector<int> curr(sz);
        curr.front() = 1;
        curr.back() = 1;
        for(int i = 1; i < sz - 1; i++){
            curr[i] = ans[sz - 2][i] + ans[sz - 2][i - 1];
        }
        ans.push_back(curr);
    }
    return ans;
}
};
