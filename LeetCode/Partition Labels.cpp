// https://leetcode.com/problems/partition-labels/description/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        int f[26] = {};
        int n = s.size();
        for(int i = 0; i < n; i++){
            f[s[i] - 'a'] = i;
        }
        int p = 0, mx = 0;
        for(int i = 0; i < n; i++){
            mx = max(mx, f[s[i] - 'a']);
            if(mx == i) {
                ans.push_back(i - p + 1);
                p = i + 1;
            }
        }
        return ans;
    }
};
