// https://leetcode.com/problems/top-k-frequent-elements/description/

class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        
        for(int &x : nums){
            ump[x]++;
        }
        vector<pair<int, int>> v(ump.begin(), ump.end());

        sort(v.begin(), v.end(), [](auto &a, auto &b){
            return a.second > b.second;
        });

        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(v[i].first);
        }
        return ans;
    }
};
