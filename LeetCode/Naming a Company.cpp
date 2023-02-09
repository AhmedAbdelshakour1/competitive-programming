// https://leetcode.com/problems/naming-a-company/description/

long long distinctNames(vector<string>& ideas) {
    unordered_set<string> mp[26];
    for (int i = 0; i < ideas.size(); ++i) mp[ideas[i][0] - 'a'].insert(ideas[i].substr(1));
    long long ans = 0;
    for (int i = 0; i < 26; ++i) {
        for (int j = i + 1; j < 26; ++j) {
            if(!mp[i].size() || !mp[j].size()) continue;
            int m = 0;
            for(auto &curr : mp[i]){
                if(mp[j].count(curr)) m++;
            }
            ans += 2LL * (mp[i].size() - m) * (mp[j].size() - m);
        }
    }
    return ans;
}
