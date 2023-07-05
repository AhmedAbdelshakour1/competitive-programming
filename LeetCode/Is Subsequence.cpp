// https://leetcode.com/problems/is-subsequence/description/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = t.size(), m = s.size();
        map<char, vector<int>> mp;
        for(int i = 0; i < n; i++) mp[t[i]].push_back(i);
        int ok = 1, last = -1;
        for(int i = 0; i < m; i++){
            if(!mp[s[i]].empty()){
                auto v = mp[s[i]];
                auto curr = upper_bound(v.begin(), v.end(), last);
                if(curr == v.end() || *curr < last){
                    ok = 0;
                    break;
                }
                last = *curr;
            }else {
                ok = 0;
                break;
            }
        }
        return ok;
    }
};
