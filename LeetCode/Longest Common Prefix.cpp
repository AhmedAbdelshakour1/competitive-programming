// https://leetcode.com/problems/longest-common-prefix/description/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string ans = "";
        for(int i = 0, valid; i < strs[0].size(); i++){
            valid = 1;
            for(int j = 1; j < strs.size(); j++){
                if(strs[j][i] != strs[0][i]){
                    valid = 0;
                    break;
                }
            }
            if(valid) ans += strs[0][i];
            else break;
        }
        return ans;
    }
};
