// https://leetcode.com/problems/group-anagrams/description/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        string tmp;
        for (int i = 0; i < strs.size(); ++i) {
            tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            mp[tmp].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto &x : mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};
